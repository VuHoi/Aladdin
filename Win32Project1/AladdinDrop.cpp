#include "AladdinDrop.h"




AladdinDrop::AladdinDrop(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 15;
	mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 18;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}

AladdinDrop::~AladdinDrop()
{
}

void AladdinDrop::Activities(GLOBAL::DIRECTION direction)
{
	if (direction == GLOBAL::LEFT)
		this->mSprite->FlipVertical(true);
	this->mSpeed += 2.0f;
	int i = this->GetCurrentFrame();
	this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
	this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
	if (i < 7)
	{
		this->SetUpCurrentFrame();
	}
	else if (mCurrentLocation.y >= AladdinAction::mEndLocation.y)
		this->SetUpCurrentFrame();
	else
		this->Update(direction);
}

void AladdinDrop::SetEndLocation(D3DXVECTOR3 location)
{
	this->mEndLocation = location;
}

void AladdinDrop::Update(GLOBAL::DIRECTION direction)
{
	mCurrentLocation.y += this->mSpeed;
}

void AladdinDrop::LoadResource()
{
	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	int lastX = 0;
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		if (i <= 7)
		{
			rect.top = 805;
			float x = 60;
			rect.right = 200+x * i;
			rect.left = 200 + x * i - x + 1;
			rect.bottom = 905;
		}
		else
		{
			rect.top = 905;
			float x;
			switch (i)
			{
			case 8:case 9: case 10: case 11: case 12: x = 72.5; break;
			case 13:case 14: x = 86; break; 
			case 15: case 16: case 17: x = 104; break;
			default: x = 115;
			}
			rect.left = lastX;
			rect.right = lastX + x;
			rect.bottom = 985;
			lastX = rect.right;
		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);
}

void AladdinDrop::SetUpCurrentFrame()
{
	this->mCurrentFrame += (this->mCurrentFrame <= this->mEndFrame) ? 1 : 0;
}
