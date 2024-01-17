#include "inc/App.h"

Application::Application()
	: m_Wnd(nullptr), m_Width(800), m_Height(600), m_AppName(L"DefaultAppName")
{}

Application::Application(int width, int height, const wchar_t* name)
	: m_Wnd(nullptr), m_Width(width), m_Height(height), m_AppName(name)
{
}

int Application::ApplicationInit()
{
	m_Wnd = new WindowsWindow::window(m_Width, m_Height, m_AppName);

	MSG m = { 0 };

	while (true)
	{
		while (PeekMessageW(&m, nullptr, 0, 0, PM_REMOVE))
		{
			if (m.message == WM_QUIT)
			{
				return m.wParam;
			}

			TranslateMessage(&m);
			DispatchMessage(&m);
		}
	}
}

Application::~Application()
{
	delete m_Wnd;
	OutputDebugStringW(L"Application Destroyed!\n");
}