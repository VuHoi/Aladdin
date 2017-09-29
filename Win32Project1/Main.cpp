#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include"GAME.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#define WINDOWS_WIDTH	1000
#define WINDOWS_HEIGHT	600
#define FRAME_RATE		80

LPDIRECT3D9						d3d;
LPDIRECT3DDEVICE9				d3ddevice;
LPDIRECT3DSURFACE9				backBuffer;
HWND							hWnd;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	GAME game(hInstance, WINDOWS_WIDTH, WINDOWS_HEIGHT, "TEST GAME", 30);
	game.Initialize();

	MSG msg;
	int done = 1;
	DWORD frameStart = GetTickCount();
	DWORD delta;
	while (done)
	{
		DWORD tick_per_frame = 1100 / GLOBAL::GetFrameRate(); // số giây cần để vẽ.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			if (msg.message == WM_QUIT)
				done = 0;
			TranslateMessage(&msg); 
			DispatchMessage(&msg);
		}
		DWORD now = GetTickCount();
		delta = now - frameStart;
		if (delta >= tick_per_frame)
		{
			game.Run();
			frameStart = now;
		}
	}

	return msg.wParam;
} // End WinMain


