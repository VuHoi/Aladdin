#include "AladdinSwing.h"



AladdinSwing::AladdinSwing(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 7;
	mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 10;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}

AladdinSwing::~AladdinSwing()
{
}

void AladdinSwing::Activities(GLOBAL::DIRECTION direction)
{
	GLOBAL::SetFrameRate(30);
	if (direction == GLOBAL::RIGHT)
		this->mSprite->FlipVertical(true);
	AladdinAction::Activities(direction);
}

void AladdinSwing::Update(GLOBAL::DIRECTION direction)
{
	mCurrentLocation.x += (direction == GLOBAL::RIGHT) ? this->mSpeed : 0;
	mCurrentLocation.x += (direction == GLOBAL::LEFT) ? (-this->mSpeed) : 0;
}

void AladdinSwing::LoadResource()
{
	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		rect.top = 1469;
		rect.bottom = 1552;
		switch (i)
		{
		case 1:
		{
			rect.left = 10;
			rect.right = 50;
			break;
		}
		case 2:
		{
			rect.left = 57;
			rect.right = 120;
			break;
		}
		case 3:
		{
			rect.left = 115;
			rect.right = 178;
			break;
		}
		case 4:
		{
			rect.left = 176;
			rect.right = 239;
			break;
		}
		case 5:
		{
			rect.left = 242;
			rect.right = 301;
			break;
		}
		case 6:
		{
			rect.left = 303;
			rect.right = 362;
			break;
		}
		case 7:
		{
			rect.left = 365;
			rect.right = 424;
			break;
		}
		case 8:
		{
			rect.left = 430;
			rect.right = 495;
			break;
		}
		case 9:
		{
			rect.left = 504;
			rect.right = 566;
			break;
		}
		case 10:
		{
			rect.left = 566;
			rect.right = 628;
			break;
		}
		}

		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);
}
