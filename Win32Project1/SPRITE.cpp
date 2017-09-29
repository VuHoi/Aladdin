#include "SPRITE.h"



SPRITE::SPRITE(const char * filePath, D3DCOLOR transcolor, vector<RECT> listSourceRect, D3DXVECTOR2 scale)
{
	HRESULT result;
	this->mSpriteHandler = GLOBAL::GetSpriteHandler();
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mRotation = 0;
	this->mRotationCenter = D3DXVECTOR2(mPosition.x, mPosition.y);
	this->mTranslation = D3DXVECTOR2(0, 0);
	this->mScale = scale;
	this->mListRect = listSourceRect;
	this->mIsFlipHorizontal = false;
	this->mIsFlipVertical = false;

	D3DXGetImageInfoFromFile(filePath, &mImageInfo);

	//Update lại hình chữ nhật chưa sprite cần vẽ
	if (!listSourceRect.size() <= 0)
	{
		this->mSourceRect.left = 0;
		this->mSourceRect.top = 0;
		this->mSourceRect.right = this->mImageInfo.Width;
		this->mSourceRect.bottom = this->mImageInfo.Height;
		this->mListRect.push_back(mSourceRect);
	}
	D3DXCreateTextureFromFileEx(
		GLOBAL::GetDirectDevice(),
		filePath,
		mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&mImageInfo,
		NULL,
		&mTexture);

	if (!this->mTexture)
	{
		MessageBox(NULL, "Can't Create Texture", "Error", MB_OK);
	}
}

SPRITE::~SPRITE()
{
	if (mTexture)
		mTexture->Release();
}

void SPRITE::Draw(int spriteIndex, D3DXVECTOR2 scale, D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 transform, float rotation, D3DXVECTOR2 rotationCenter)
{
	D3DXVECTOR3	inPosition = (position != D3DXVECTOR3()) ? position : this->mPosition;
	RECT		inSourceRect = (isRect(sourceRect)) ? sourceRect : this->mListRect[spriteIndex];
	float		inRotation = (rotation != 0.0f)? rotation:this->mRotation;
	D3DXVECTOR2 inScale = (scale != D3DXVECTOR2()) ? scale : this->mScale;
	D3DXVECTOR2	inTranslation = (transform != D3DXVECTOR2()) ? transform : this->mTranslation;
	D3DXVECTOR2	inRotationCenter = (rotationCenter != D3DXVECTOR2()) ? rotationCenter : D3DXVECTOR2(inPosition.x, inPosition.y);
	D3DXVECTOR2	scalingCenter = D3DXVECTOR2(inPosition.x, inPosition.y);

	D3DXMatrixTransformation2D(
		&mMatrix, 
		&scalingCenter, 
		0, 
		&inScale, 
		&inRotationCenter, 
		inRotation, 
		&inTranslation);

	D3DXMATRIX oldMatrix;
	this->mSpriteHandler->GetTransform(&oldMatrix);
	this->mSpriteHandler->SetTransform(&mMatrix);

	D3DXVECTOR3 center = D3DXVECTOR3((inSourceRect.right - inSourceRect.left)/2, (inSourceRect.bottom - inSourceRect.top)/2, 0);//Tâm của sprite cần vẽ

	this->mSpriteHandler->Draw(
		this->mTexture,
		&inSourceRect,
		&center,
		&inPosition,
		D3DCOLOR_ARGB(255, 255, 255, 255));
	this->mSpriteHandler->SetTransform(&oldMatrix);
}

LPDIRECT3DTEXTURE9 SPRITE::GetTexture()
{
	return this->mTexture;
}

D3DXIMAGE_INFO SPRITE::GetImageInfo()
{
	return this->mImageInfo;
}

D3DXVECTOR3 SPRITE::GetPosition()
{
	return this->mPosition;
}

void SPRITE::SetPosition(D3DXVECTOR3 position)
{
	this->mPosition = position;
}

void SPRITE::SetPosition(float x, float y)
{
	this->mPosition = D3DXVECTOR3(x, y, 0);
}

void SPRITE::SetPosition(D3DXVECTOR2 position)
{
	this->SetPosition(position.x, position.y);
}

D3DXVECTOR2 SPRITE::GetScale()
{
	return this->mScale;
}

void SPRITE::SetScale(D3DXVECTOR2 scale)
{
	this->mScale = scale;
}

void SPRITE::SetScale(float x, float y)
{
	this->mScale = D3DXVECTOR2(x, y);
}

D3DXVECTOR2 SPRITE::GetTranslation()
{
	return this->mTranslation;
}

void SPRITE::SetTranslation(D3DXVECTOR2 translation)
{
	this->mTranslation = translation;
}

D3DXVECTOR2 SPRITE::GetRotationCenter()
{
	return this->mRotationCenter;
}

void SPRITE::SetRotationCenter(D3DXVECTOR2 rotationCenter)
{
	this->mRotationCenter = rotationCenter;
}

float SPRITE::GetRotation()
{
	return this->mRotation;
}

void SPRITE::SetRotation(float rotation)
{
	this->mRotation = rotation;
}

void SPRITE::SetResourceRect(RECT rect)
{
	this->mSourceRect = rect;
}

void SPRITE::FlipHorizontal(bool flag)
{
	if (mIsFlipHorizontal != flag)
	{
		this->mIsFlipHorizontal = flag;
		this->mScale = D3DXVECTOR2(this->mScale.x, -this->mScale.y);
	}
}

bool SPRITE::IsFlipHorizontal()
{
	return this->mIsFlipHorizontal;
}

void SPRITE::FlipVertical(bool flag)
{
	if (this->mIsFlipVertical != flag)
	{
		this->mIsFlipVertical = flag;
		this->mScale = D3DXVECTOR2(-this->mScale.x, this->mScale.y);
	}
}

bool SPRITE::IsFlipVertical()
{
	return this->mIsFlipVertical;
}

bool SPRITE::isRect(RECT rect)
{
	return ((rect.top != rect.bottom) && (rect.left != rect.right));
}
