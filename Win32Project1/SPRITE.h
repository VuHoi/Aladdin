#pragma once
#ifndef __SPRITE_H__
#define	__SPRITE_H__
#include<vector>
using namespace std;
#include"GLOBAL.h"
class SPRITE
{
public:
	/*
	filePath:	Đường dẫn file
	sourceRect: Hình chữ nhật chứa sprite cần vẽ
	transcolor: Màu chỉ định là màu trong suốt
	..*/
	SPRITE(
		const char* filePath,
		D3DCOLOR transcolor = 0,
		vector<RECT> listSourceRect = vector<RECT>(),
		D3DXVECTOR2 scale = D3DXVECTOR2(1,1));
	~SPRITE();

	/*
	position:		Vị trí của sprite cần vẽ
	sourceRect:		Hình chữ nhật chứa sprite cần vẽ
	scale:			Vector tuỳ chỉnh zoom sprite
	transform:		Vector tịnh tiến sprite
	rotation:		Góc quay sprite
	rotationCenter: Điểm quay sprite
	..*/
	void				Draw(
		int				spriteIndex = 0,
		D3DXVECTOR2		scale = D3DXVECTOR2(),
		D3DXVECTOR3		position = D3DXVECTOR3(),
		RECT			sourceRect = RECT(),
		D3DXVECTOR2		transform = D3DXVECTOR2(),
		float			rotation = 0,
		D3DXVECTOR2		rotationCenter = D3DXVECTOR2());

	LPDIRECT3DTEXTURE9	GetTexture();

	D3DXIMAGE_INFO		GetImageInfo();

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 position);
	void				SetPosition(float x, float y);
	void				SetPosition(D3DXVECTOR2 position);

	D3DXVECTOR2			GetScale();
	void				SetScale(D3DXVECTOR2 scale);
	void				SetScale(float x, float y);

	D3DXVECTOR2			GetTranslation();
	void				SetTranslation(D3DXVECTOR2 translation);

	D3DXVECTOR2			GetRotationCenter();
	void				SetRotationCenter(D3DXVECTOR2 rotationCenter);

	float				GetRotation();
	void				SetRotation(float rotation);

	void				SetResourceRect(RECT rect);

	void				FlipHorizontal(bool flag);
	bool				IsFlipHorizontal();

	void				FlipVertical(bool flag);
	bool				IsFlipVertical();


private:
	bool							isRect(RECT rect);

	//-----------------------------------------------------------------------
	D3DXVECTOR3						mPosition;			//Sprite location
	LPDIRECT3DTEXTURE9				mTexture;
	D3DXIMAGE_INFO					mImageInfo;
	LPD3DXSPRITE					mSpriteHandler;
	RECT							mSourceRect;		//Rectangle chứa sprite cần vẽ
	bool							mIsFlipVertical;
	bool							mIsFlipHorizontal;
	float							mRotation;			//Góc quay tính theo radian
	D3DXVECTOR2						mRotationCenter;	//Điểm quay
	D3DXVECTOR2						mScale;				//Vector tuỳ chỉnh zoom hình
	D3DXVECTOR2						mTranslation;		//Vector tịnh tiến
	D3DXMATRIX						mMatrix;			// Ma trận hỗ trợ phép dời hình
	vector<RECT>					mListRect;			//Danh sách các hình chữ nhất chứa các sprite cần vẽ lên
};

#endif __SPRITE_H__