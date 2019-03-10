#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include "Win32.h"
#include <CommCtrl.h>

HINSTANCE hInst;

HWND createMainWindow(WNDCLASS wc, HINSTANCE* hInstance);
int createTreeview(int x, int y, int height, int width, HWND hWnd);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	WNDCLASS wc = { };
	
	// Create the window.
	HWND hwnd = createMainWindow(wc, &hInstance);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (msg.message == WM_KEYDOWN)
			MessageBoxEx(0, L"event", L"you pressed a key", 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

int createTreeView(int x, int y, int height, int width, HWND hWnd)
{
	CreateWindowEx(0, WC_TREEVIEW, L"TREE VIEW", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_SIZEBOX | WS_VSCROLL | WS_TABSTOP
		| TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS, x, y, width, height, hWnd,
		NULL,/*(HMENU)ID_TREEVIEW*/ hInst, NULL);
	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_PAINT:
		{
			/*PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
			EndPaint(hwnd, &ps);*/

			PAINTSTRUCT ps;
			RECT rc;
			HDC hdc = BeginPaint(hwnd, &ps);
			GetClientRect(hwnd, &rc);
			SetBkColor(hdc, RGB(50,50,50));
			ExtTextOut(hdc, 0, 0, ETO_OPAQUE, &rc, 0, 0, 0);
			EndPaint(hwnd, &ps);
		}
		return 0;

		case WM_CREATE:
		{
			createTreeView(0, 0, 400, 200, hwnd);
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

HWND createMainWindow(WNDCLASS wc, HINSTANCE* hInstance)
{
	// Register the window class.
	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = *hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	return CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		L"Windows Explorer",			// Window text
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // Parent window
		NULL,       // Menu
		*hInstance,  // Instance handle
		NULL        // Additional application data
	);
}

