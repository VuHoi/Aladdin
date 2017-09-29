#include "SurfaceManager.h"


SurfaceManager::SurfaceManager(char * fileName, D3DXCOLOR transcolor)
{
	this->mFileName = fileName;
	this->LoadResouce();
	this->mTranscolor = transcolor;
}

SurfaceManager::~SurfaceManager()
{
}

void SurfaceManager::Render(const RECT * sourceRect, const RECT * desRect)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mSurface,
		sourceRect,
		GLOBAL::GetBackBuffer(),
		desRect,
		D3DTEXF_NONE);
}

void SurfaceManager::Render(const RECT * sourceRect, const RECT * desRect, SurfaceManager surface)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mSurface,
		sourceRect,
		surface.mSurface,
		desRect,
		D3DTEXF_NONE);
}

LPDIRECT3DSURFACE9 SurfaceManager::GetSurface()
{
	return this->mSurface;
}

char * SurfaceManager::GetFileName()
{
	return this->mFileName;
}

void SurfaceManager::LoadResouce()
{
	D3DXIMAGE_INFO info; 
	if (D3DXGetImageInfoFromFile(this->mFileName, &info))
	{
		MessageBox(NULL, "Can't load resource", "Error", MB_OK);
		return;
	}
	
	GLOBAL::GetDirectDevice()->CreateOffscreenPlainSurface(
		info.Width,
		info.Height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&mSurface,
		NULL);

	if (
		D3DXLoadSurfaceFromFile(
			this->mSurface,
			NULL,
			NULL,
			this->mFileName,
			NULL,
			D3DX_FILTER_TRIANGLE,
			this->mTranscolor,
			&info) != D3D_OK)
	{
		MessageBox(NULL, "Can't load resource", "Error", MB_OK);
		return;
	}
}
