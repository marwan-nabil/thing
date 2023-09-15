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
    b32 MonitorsNeedUpdate;
};

struct win32_viewport_data
{
    HWND Window;
    HWND ParentWindow;
    b32 WindowOwned;
    DWORD StyleFlags;
    DWORD ExtendedStyleFlags;
};

enum win32_renderer_backend
{
    W32RB_OPENGL2,
    W32RB_DX11
};

struct win32_global_handles
{
    HMODULE ShcoreDllModule;
    HMODULE User32DllModule;
    HMODULE NtDllModule;
};

typedef HRESULT (WINAPI *SetProcessDpiAwarenessFunctionType)(PROCESS_DPI_AWARENESS);
typedef HRESULT (WINAPI *GetDpiForMonitorFunctionType)(HMONITOR, MONITOR_DPI_TYPE, u32 *, u32 *);
typedef DPI_AWARENESS_CONTEXT (WINAPI *SetThreadDpiAwarenessContextFunctionType)(DPI_AWARENESS_CONTEXT);
typedef u32 (WINAPI *RtlVerifyVersionInfoFunctionType)(OSVERSIONINFOEXW *, u32, ULONGLONG);

#define VK_KEYPAD_ENTER (VK_RETURN + 256)