#pragma once
#ifndef __GAME_H__
#define	__GAME_H__

#include"GLOBAL.h"
#include"SPRITE.h"
#include"AladdinAction.h"
#include"ALADDIN.h"
#include"SurfaceManager.h"
#include<vector>
#include "dxinput.h"
using namespace std;
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) 
#define KEY_UP(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
class GAME
{
public:
	//hInstance
	//Windows Width
	//Windows Height
	//Game Name
	//Frame Rate
	//...
	GAME(HINSTANCE hInstance, int windowsWidth, int windowsHeight, char* gameName, int frameRate);
	~GAME();
	void					Initialize();
	void					Run();
private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void					InitWindows();
	void					InitDevice();
	void					LoadResource();
	vector<SPRITE*>			_listSpriteRun1;
	ALADDIN*				mAladdin;
	D3DXVECTOR3				mLastLocation;			//Lưu lại vị trí cuối cùng của một hành động
	GLOBAL::STATE			mState;
	SurfaceManager*			mMap;
};

#endif __GAME_H__
