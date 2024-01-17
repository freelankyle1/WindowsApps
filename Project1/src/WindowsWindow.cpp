#include "inc/WindowsWindow.h"


namespace WindowsWindow
{
    LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    
    HRESULT window::WndClassInit()
    {
        m_hInstance = GetModuleHandle(nullptr);

        ZeroMemory(&m_WndClass, sizeof(WNDCLASSEX));

        // fill in the struct with the needed information
        m_WndClass.hInstance = GetModuleHandle(nullptr);
        m_WndClass.cbSize = sizeof(WNDCLASSEX);
        m_WndClass.style = CS_HREDRAW | CS_VREDRAW;
        m_WndClass.lpfnWndProc = WndProc;
        m_WndClass.cbClsExtra = 0;
        m_WndClass.cbWndExtra = 0;
        m_WndClass.hIcon = nullptr;
        m_WndClass.hbrBackground = (HBRUSH)BLACK_BRUSH;
        m_WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        m_WndClass.lpszClassName = m_WndClassName;
        m_WndClass.hIconSm = nullptr;

        if (!RegisterClassEx(&m_WndClass));
            return 0;
    }

	window::window(int width, int height, const wchar_t* name)
        : m_Width(width), m_Height(height), m_Name(name), m_hWnd(0)
	{
        //register WndClass
        WndClassInit();
        
        //construct the window
        RECT rc;

        rc.left = 100;
        rc.top = 100;
        rc.right = rc.left + width;
        rc.bottom = rc.top + height;

        //adjusts the window to how we want it
        //specify the styles...Caption   +  border   +  Minimizebox   No menu
        AdjustWindowRect(&rc, WS_CAPTION | WS_BORDER | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

        m_hWnd = CreateWindowW(
            m_WndClassName, m_Name,
            WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
            CW_USEDEFAULT, CW_USEDEFAULT,
            rc.right - rc.left, rc.bottom - rc.top,
            nullptr, nullptr, m_hInstance, this
        );

        ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	}

	window::~window()
	{
        UnregisterClass(m_WndClassName, m_hInstance);
        OutputDebugStringW(L"Window Class Unregistered!\n");
    }

    HWND window::GetHandle() const
    {
        return m_hWnd;
    }

    LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch (msg)
        {
            case(WM_CLOSE):
                PostQuitMessage(0);
                break;
        }
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}