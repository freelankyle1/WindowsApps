#include <windows.h>
#include "inc/WindowsWindow.h"
#include "inc/App.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	Application app(1280, 720, L"Kyles Application!");
	app.ApplicationInit();

	return 0;
}

