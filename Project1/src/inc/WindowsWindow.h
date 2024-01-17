#pragma once
#include <Windows.h>


namespace WindowsWindow
{
	class window
	{

	public:
		window() = default;
		window(int, int, const wchar_t*);
		window(const window&) = delete;
		window operator=(const window&) = delete;
		~window();

		HWND GetHandle() const;

	private:
		HRESULT WndClassInit();

	private:

		//WndClass stuff
		static constexpr const wchar_t* const m_WndClassName = L"WndClassName";
		WNDCLASSEX m_WndClass;
		HINSTANCE m_hInstance;

		//Window stuff
		int m_Width;
		int m_Height;
		const wchar_t* m_Name;
		HWND m_hWnd;

		//only one window allowed
		static window wnd;

	};
}