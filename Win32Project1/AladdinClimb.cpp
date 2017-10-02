#include "AladdinClimb.h"


AladdinClimb::AladdinClimb(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 10;
	mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 10;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}

AladdinClimb::~AladdinClimb()
{
}

void AladdinClimb::Activities(GLOBAL::DIRECTION direction)
{
	GLOBAL::SetFrameRate(50);
	AladdinAction::Activities(direction);
}



void AladdinClimb::Update(GLOBAL::DIRECTION direction)
{
	mCurrentLocation.y -= (direction == GLOBAL::UP) ? this->mSpeed : 0;
	mCurrentLocation.y += (direction == GLOBAL::DOWN) ? this->mSpeed : 0;
}

void AladdinClimb::LoadResource()
{
	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		rect.top = 1360;
		float x = 44;
		rect.right = x * i;
		rect.left = x * i - x + 1;
		rect.bottom = 1440;
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);
}

