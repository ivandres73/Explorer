#ifndef WIN32_H
#define WIN32_H

#include <Windows.h>
#include <CommCtrl.h>

class Win32
{
	private:

	public:
		LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static HWND createTreeView(int x, int y, int height, int width, HWND hWnd);
		int getNumberOfDrives(char* s);
};

#endif