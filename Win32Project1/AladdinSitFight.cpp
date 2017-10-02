
#include "AladdinSitFight.h"



AladdinSitFight::AladdinSitFight()
{
}


AladdinSitFight::~AladdinSitFight()
{
}



AladdinSitFight::AladdinSitFight(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 5;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 7;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();

}

void AladdinSitFight::Activities(GLOBAL::DIRECTION direction)
{


	GLOBAL::SetFrameRate(25);


	if (direction == GLOBAL::LEFT)
		this->mSprite->FlipVertical(true);
	else
		this->mSprite->FlipVertical(false);
	AladdinAction::Activities(direction);
}

void AladdinSitFight::SetEndLocation(D3DXVECTOR3 location)
{
	this->mEndLocation = location;
}

void AladdinSitFight::Update(GLOBAL::DIRECTION direction)
{
	//mCurrentLocation.y += this->mSpeed;
}

void AladdinSitFight::LoadResource()
{

	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		switch (i)
		{

		case 1:
			rect.left = 7;
			rect.top = 638;
			rect.right = rect.left + 50;
			rect.bottom = rect.top + 35;

			break;
		case 2:
			rect.left =62;
			rect.top = 640;
			rect.right = rect.left + 49;
			rect.bottom = rect.top +34;

			break;
		case 3:
			rect.left =114;
			rect.top = 640;
			rect.right = rect.left +72;
			rect.bottom = rect.top +34;

			break;
		case 4:
			rect.left =189;
			rect.top = 639;
			rect.right = rect.left + 95;
			rect.bottom = rect.top + 34;

			break;
		case 5:
			rect.left = 298;
			rect.top = 640;
			rect.right = rect.left + 84;
			rect.bottom = rect.top + 34;

			break;
		case 6:
			rect.left = 391;
			rect.top = 640;
			rect.right = rect.left + 73;
			rect.bottom = rect.top + 34;

		case7:
			rect.left = 473;
			rect.top = 640;
			rect.right = rect.left + 48;
			rect.bottom = rect.top + 34;
			break;

		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);

}



