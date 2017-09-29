#pragma once
#ifndef _SURFACE_MANAGER_H__
#define _SURFACE_MANAGER_H__

#include"Global.h"
//Quản lý load, vẽ một surface
class SurfaceManager
{
public:
	SurfaceManager(char* fileName, D3DXCOLOR transcolor = D3DCOLOR_XRGB(0, 0, 0));
	~SurfaceManager();
	/*sourceRect: Hình chữ nhật chứa phần cần vẽ từ file source
	desRect: Hình chữ nhật được vẽ lên ở BackBuffer
	..*/
	void					Render(const RECT* sourceRect, const RECT* desRect);
	/*sourceRect: Hình chữ nhật chứa phần cần vẽ từ file source
	desRect: Hình chữ nhật được vẽ lên ở Surface đích
	surface: surface địch cần vẽ tới
	..*/
	void					Render(const RECT* sourceRect, const RECT* desRect, SurfaceManager surface);
	LPDIRECT3DSURFACE9		GetSurface();
	char*					GetFileName();
private:
	char*					mFileName;
	LPDIRECT3DSURFACE9		mSurface;
	D3DXCOLOR				mTranscolor;
	void					LoadResouce();
};

#endif _SURFACE_MANAGER_H__