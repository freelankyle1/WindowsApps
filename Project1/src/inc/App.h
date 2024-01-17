#pragma once
#include "WindowsWindow.h"

class Application
{
public:
	Application();
	Application(int width, int height, const wchar_t*);
	~Application();

	int ApplicationInit();

private:
	const wchar_t* m_AppName;
	int m_Width, m_Height;
	WindowsWindow::window* m_Wnd;
};