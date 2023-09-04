#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>
#include <stdint.h>
#include <GL/GL.h>
#include <tchar.h>
#include <shellscalingapi.h>

#include "..\..\miscellaneous\base_types.h"
#include "..\..\miscellaneous\basic_defines.h"

#define ENABLE_ASSERTIONS 1
#include "..\..\miscellaneous\assertions.h"

#include "..\..\imgui\imgui.h"

#include "opengl2_backend.h"
#include "win32_backend.h"
#include "main_win32_opengl2.h"

#include "opengl2_backend.cpp"
#include "win32_backend.cpp"

static window_data GlobalMainWindowData;
static i32 GlobalWidth;
static i32 GlobalHeight;

static LRESULT WINAPI MainWindowCallbackHandler(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
    // Win32 message handler
    // You can read the ImGuiIoInterface.WantCaptureMouse, ImGuiIoInterface.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
    // - When ImGuiIoInterface.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
    // - When ImGuiIoInterface.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.

    if (Win32_CustomCallbackHandler(Window, Message, WParam, LParam))
    {
        return true;
    }

    switch (Message)
    {
        case WM_SIZE:
        {
            if (WParam != SIZE_MINIMIZED)
            {
                GlobalWidth = LOWORD(LParam);
                GlobalHeight = HIWORD(LParam);
            }
            return 0;
        } break;

        case WM_SYSCOMMAND:
        {
            if ((WParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            {
                return 0;
            }
        } break;

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        } break;
    }

    return DefWindowProcW(Window, Message, WParam, LParam);
}

// Support function for multi-viewports
// Unlike most other backend combination, we need specific hooks to combine Win32+OpenGL.
// We could in theory decide to support Win32-specific code in OpenGL backend via e.g. an hypothetical ImGui_ImplOpenGl2_InitForRawWin32().
static void CreateWindowHook(ImGuiViewport *ViewPort)
{
    assert(ViewPort->RendererUserData == NULL);

    window_data *WindowData = (window_data *)ImGui::MemAlloc(sizeof(window_data));
    *WindowData = {};
    OpenGl2_CreateDevice((HWND)ViewPort->PlatformHandle, WindowData);
    ViewPort->RendererUserData = WindowData;
}

static void DestroyWindowHook(ImGuiViewport *ViewPort)
{
    if (ViewPort->RendererUserData != NULL)
    {
        window_data *WindowData = (window_data *)ViewPort->RendererUserData;
        OpenGl2_CleanupDeviceWGL((HWND)ViewPort->PlatformHandle, WindowData);
        if (WindowData)
        {
            ImGui::MemFree(WindowData);
        }
        ViewPort->RendererUserData = NULL;
    }
}

static void RenderWindowHook(ImGuiViewport *ViewPort, void *RenderArgument)
{
    // Activate the platform window DC in the OpenGL rendering context
    if (window_data *WindowData = (window_data *)ViewPort->RendererUserData)
    {
        wglMakeCurrent(WindowData->DeviceContext, GlobalOpenGLRenderingContext);
    }
}

static void SwapBuffersHook(ImGuiViewport *ViewPort, void *RenderArgument)
{
    if (window_data *WindowData = (window_data *)ViewPort->RendererUserData)
    {
        SwapBuffers(WindowData->DeviceContext);
    }
}

i32 main(i32 argc, char **argv)
{
    Win32_EnableDpiAwareness();

    WNDCLASSEXW MainWindowClass = {};
    MainWindowClass.cbSize = sizeof(MainWindowClass);
    MainWindowClass.style = CS_OWNDC;
    MainWindowClass.lpfnWndProc = MainWindowCallbackHandler;
    MainWindowClass.cbClsExtra = 0;
    MainWindowClass.cbWndExtra = 0;
    MainWindowClass.hInstance = GetModuleHandle(NULL);
    MainWindowClass.hIcon = NULL;
    MainWindowClass.hCursor = NULL;
    MainWindowClass.hbrBackground = NULL;
    MainWindowClass.lpszMenuName = NULL;
    MainWindowClass.lpszClassName = L"MainWindowClass";
    MainWindowClass.hIconSm = NULL;

    RegisterClassExW(&MainWindowClass);

    HWND Window = CreateWindowW
    (
        MainWindowClass.lpszClassName,
        L"my imgui demo",
        WS_OVERLAPPEDWINDOW,
        100, 100, 1280, 800,
        NULL, NULL, MainWindowClass.hInstance, NULL
    );

    if (!OpenGl2_CreateDevice(Window, &GlobalMainWindowData))
    {
        OpenGl2_CleanupDeviceWGL(Window, &GlobalMainWindowData);
        DestroyWindow(Window);
        UnregisterClassW(MainWindowClass.lpszClassName, MainWindowClass.hInstance);
        return 1;
    }
    wglMakeCurrent(GlobalMainWindowData.DeviceContext, GlobalOpenGLRenderingContext);

    // Show the window
    ShowWindow(Window, SW_SHOWDEFAULT);
    UpdateWindow(Window);

    // Setup Dear ImGui context
    ImGui::CreateContext();
    ImGuiIO *ImGuiIoInterface = &ImGui::GetIO();
    ImGuiIoInterface->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    ImGuiIoInterface->ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
    ImGuiIoInterface->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsClassic();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle *ImGuiStyleInterface = &ImGui::GetStyle();
    ImGuiStyleInterface->WindowRounding = 0.0f;
    ImGuiStyleInterface->Colors[ImGuiCol_WindowBg].w = 1.0f;

    // Setup Platform/Renderer backends
    Win32_Initialize(Window, W32RB_OPENGL2);
    OpenGl2_Initialize();

    // Win32+GL needs specific hooks for ViewPort, as there are specific things needed to tie Win32 and GL api.
    if (ImGuiIoInterface->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGuiPlatformIO *ImGuiPlatformIoInterface = &ImGui::GetPlatformIO();
        Assert(ImGuiPlatformIoInterface->Renderer_CreateWindow == NULL);
        Assert(ImGuiPlatformIoInterface->Renderer_DestroyWindow == NULL);
        Assert(ImGuiPlatformIoInterface->Renderer_SwapBuffers == NULL);
        Assert(ImGuiPlatformIoInterface->Platform_RenderWindow == NULL);
        ImGuiPlatformIoInterface->Renderer_CreateWindow = CreateWindowHook;
        ImGuiPlatformIoInterface->Renderer_DestroyWindow = DestroyWindowHook;
        ImGuiPlatformIoInterface->Renderer_SwapBuffers = SwapBuffersHook;
        ImGuiPlatformIoInterface->Platform_RenderWindow = RenderWindowHook;
    }

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //ImGuiIoInterface->Fonts->AddFontDefault();
    //ImGuiIoInterface->Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //ImGuiIoInterface->Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //ImGuiIoInterface->Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //ImGuiIoInterface->Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = ImGuiIoInterface->Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, ImGuiIoInterface->Fonts->GetGlyphRangesJapanese());
    //Assert(font != NULL);

    // Our state
    bool ShowDemoWindow = true;
    bool ShowAnotherWindow = false;
    ImVec4 ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    b32 Done = false;
    while (!Done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the MainWindowCallbackHandler() function below for our to dispatch events to the Win32 backend.
        MSG Message;
        while (PeekMessage(&Message, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
            if (Message.message == WM_QUIT)
            {
                Done = true;
            }
        }

        if (Done)
        {
            break;
        }

        // Start the Dear ImGui frame
        OpenGl2_NewFrame();
        Win32_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (ShowDemoWindow)
        {
            ImGui::ShowDemoWindow(&ShowDemoWindow);
        }

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static f32 FloatSliderValue = 0.0f;
            static i32 CounterValue = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text."); // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &ShowDemoWindow); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &ShowAnotherWindow);

            ImGui::SliderFloat("f32", &FloatSliderValue, 0.0f, 1.0f); // Edit 1 f32 using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (f32 *)&ClearColor); // Edit 3 floats representing a color

            if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
            {
                CounterValue++;
            }
            ImGui::SameLine();
            ImGui::Text("CounterValue = %d", CounterValue);
            ImGui::Text
            (
                "Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / ImGuiIoInterface->Framerate,
                ImGuiIoInterface->Framerate
            );
            ImGui::End();
        }

        // 3. Show another simple window.
        if (ShowAnotherWindow)
        {
            ImGui::Begin("Another Window", &ShowAnotherWindow);   // Pass a pointer to our b32 variable (the window will have a closing button that will clear the b32 when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
            {
                ShowAnotherWindow = false;
            }
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        glViewport(0, 0, GlobalWidth, GlobalHeight);
        glClearColor(ClearColor.x, ClearColor.y, ClearColor.z, ClearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        OpenGl2_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        if (ImGuiIoInterface->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();

            // Restore the OpenGL rendering context to the main window DC, since platform windows might have changed it.
            wglMakeCurrent(GlobalMainWindowData.DeviceContext, GlobalOpenGLRenderingContext);
        }

        // Present
        SwapBuffers(GlobalMainWindowData.DeviceContext);
    }

    OpenGl2_Shutdown();
    Win32_Shutdown();
    ImGui::DestroyContext();

    OpenGl2_CleanupDeviceWGL(Window, &GlobalMainWindowData);
    wglDeleteContext(GlobalOpenGLRenderingContext);
    DestroyWindow(Window);
    UnregisterClassW(MainWindowClass.lpszClassName, MainWindowClass.hInstance);

    return 0;
}