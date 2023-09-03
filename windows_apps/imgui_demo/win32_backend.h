#pragma once

struct win32_backend_data
{
    HWND Window;
    HWND MouseWindow;
    i32 MouseTrackedArea; // 0: not tracked, 1: client are, 2: non-client area
    i32 MouseButtonsDown;
    i64 Time;
    i64 TicksPerSecond;
    ImGuiMouseCursor LastMouseCursor;
    bool WantUpdateMonitors;
};

struct win32_viewport_data
{
    HWND Window;
    HWND ParentWindow;
    bool WindowOwned;
    DWORD StyleFlags;
    DWORD ExtendedStyleFlags;
};

enum win32_renderer_backend
{
    W32RB_OPENGL2,
    W32RB_D3D11
};

typedef HRESULT(WINAPI *SetProcessDpiAwarenessFunctionType)(PROCESS_DPI_AWARENESS);
typedef HRESULT(WINAPI *GetDpiForMonitorFunctionType)(HMONITOR, MONITOR_DPI_TYPE, u32 *, u32 *);
typedef DPI_AWARENESS_CONTEXT(WINAPI *SetThreadDpiAwarenessContextFunctionType)(DPI_AWARENESS_CONTEXT);
typedef u32(WINAPI *RtlVerifyVersionInfoFunctionType)(OSVERSIONINFOEXW *, u32, ULONGLONG);

// There is no distinct VK_xxx for keypad enter, instead it is VK_RETURN + KF_EXTENDED, we assign it an arbitrary value to make code more readable (VK_ codes go up to 255)
#define IM_VK_KEYPAD_ENTER (VK_RETURN + 256)