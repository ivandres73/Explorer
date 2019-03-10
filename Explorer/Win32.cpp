#include "Win32.h"

LRESULT Win32 :: WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hwnd, &ps);
	}
	return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

HWND Win32::createTreeView(int x, int y, int height, int width, HWND hWnd)
{
	/*CreateWindowEx(0, WC_TREEVIEW, L"TREE VIEW", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_SIZEBOX | WS_VSCROLL | WS_TABSTOP
		| TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS, x, y, width, height, hWnd,
		(HMENU)IDM_TREE_VIEW, hInst, nullptr);*/
	return 0;
}
