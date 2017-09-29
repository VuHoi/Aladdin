#pragma once
#ifndef __GLOBAL_H__
#define __GLOBAL_H__
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#define COUNT_FRAME	9
class GLOBAL
{
public:
	GLOBAL();
	~GLOBAL();
	
	static	HINSTANCE						GethInstance() { return GLOBAL::mHInstance; }
	static	void							SethInstance(HINSTANCE hInstance) { GLOBAL::mHInstance = hInstance; }

	static	HWND							GetHWND() { return GLOBAL::mHwnd; }
	static	void							SetHWND(HWND hwnd) { GLOBAL::mHwnd = hwnd; }

	static	LPDIRECT3D9						GetDirect() { return GLOBAL::mDirect; }
	static	void							SetDirect(LPDIRECT3D9 direct) { GLOBAL::mDirect = direct; }

	static	LPDIRECT3DDEVICE9				GetDirectDevice() { return GLOBAL::mDirectDevice; }
	static	void							SetDirectDevice(LPDIRECT3DDEVICE9 device) { GLOBAL::mDirectDevice = device; }

	static	LPDIRECT3DSURFACE9				GetBackBuffer() { return GLOBAL::mBackBuffer; }
	static	void							SetBackBuffer(LPDIRECT3DSURFACE9 backbuffer) { GLOBAL::mBackBuffer = backbuffer; }

	static	LPD3DXSPRITE					GetSpriteHandler() { return GLOBAL::mSpriteHandler; }
	static	void							SetSpriteHandler(LPD3DXSPRITE spriteHandler) { GLOBAL::mSpriteHandler = spriteHandler; }

	static	int								GetWindowsWidth() { return GLOBAL::mWindowsWidth; }
	static	void							SetWindowsWidth(int width) { GLOBAL::mWindowsWidth = width; }

	static	int								GetWindowsHeight() { return GLOBAL::mWindowsHeight; }
	static	void							SetWindowsHeight(int height) { GLOBAL::mWindowsHeight = height; }

	static	char*							GetGameName() { return GLOBAL::mGameName; }
	static	void							SetGameName(char* name) { GLOBAL::mGameName = name; }

	static	int								GetFrameRate() { return GLOBAL::mFrameRate; }
	static	void							SetFrameRate(int frameRate) { GLOBAL::mFrameRate = frameRate; }

	static	int								GetCurrentFrame() { return GLOBAL::mCurrentFrame; }
	static	void							SetUpCurrentFrame() { mCurrentFrame = (mCurrentFrame >= COUNT_FRAME) ? 1 : ++mCurrentFrame; }

	static enum								DIRECTION { UP, DOWN, LEFT, RIGHT , NONE};
	static enum								STATE { WALK, CLIMB, SWING , DROP,STAND,SIT,FIGHT,JUMP};
	static void								SetState(STATE s) { mCurrentState = s; };
	static STATE							GetState() { return mCurrentState; };

	static void								SetCurDirect(boolean s) { mCurrDirect = s; };
	static bool								GetCurDirect() { return mCurrDirect; };

	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
private:
	static	HINSTANCE						mHInstance;
	static	HWND							mHwnd;
	static	LPDIRECT3D9						mDirect;
	static	LPDIRECT3DDEVICE9				mDirectDevice;
	static	LPDIRECT3DSURFACE9				mBackBuffer; // chống giật màn hình.
	static	LPD3DXSPRITE					mSpriteHandler; //  vẽ các animation
	static	int								mWindowsWidth;
	static	int								mWindowsHeight;
	static	char*							mGameName;
	static	int								mFrameRate; // 1 giây / 20 hình.
	static	int								mCurrentFrame;
	static	STATE							mCurrentState;
	static bool								mCurrDirect;
};

#endif __GLOBAL_H__