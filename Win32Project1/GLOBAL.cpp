#include "GLOBAL.h"

HINSTANCE						GLOBAL::mHInstance = NULL;
HWND							GLOBAL::mHwnd = NULL;
LPDIRECT3D9						GLOBAL::mDirect = NULL;
LPDIRECT3DDEVICE9				GLOBAL::mDirectDevice = NULL;
LPDIRECT3DSURFACE9				GLOBAL::mBackBuffer = NULL;
LPD3DXSPRITE					GLOBAL::mSpriteHandler = NULL;
int								GLOBAL::mWindowsWidth;
int								GLOBAL::mWindowsHeight;
char*							GLOBAL::mGameName = "TEST GAME";
int								GLOBAL::mFrameRate;
int								GLOBAL::mCurrentFrame = 0;
GLOBAL::STATE					GLOBAL::mCurrentState = STAND;
GLOBAL::GLOBAL()
{
}


GLOBAL::~GLOBAL()
{
}
