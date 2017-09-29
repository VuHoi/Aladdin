#include "AladdinFight.h"



AladdinFight::AladdinFight()
{
}


AladdinFight::~AladdinFight()
{
}



AladdinFight::AladdinFight(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 5;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 5;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();

}

void AladdinFight::Activities(GLOBAL::DIRECTION direction)
{
	bool					directFight = GLOBAL::GetCurDirect();
	GLOBAL::SetFrameRate(20);
	if (direction == GLOBAL::LEFT)
	{
		if (directFight)
		{
			this->mSprite->FlipVertical(true);
			directFight = false;
		}
	}
	else if (direction == GLOBAL::RIGHT)
	{
		if (!directFight)
		{
			this->mSprite->FlipVertical(false);
			directFight = true;
		}
	}
	AladdinAction::Activities(direction);
}

void AladdinFight::SetEndLocation(D3DXVECTOR3 location)
{
	this->mEndLocation = location;
}

void AladdinFight::Update(GLOBAL::DIRECTION direction)
{
	//mCurrentLocation.y += this->mSpeed;
}

void AladdinFight::LoadResource()
{

	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		switch (i)
		{
		case 1:rect.top = 313;
			rect.bottom = 388;
			rect.left = 6;
			rect.right = rect.left + 44;
			break;
		case 2:rect.top = 313;
			rect.bottom = 388;
			rect.left = 54;
			rect.right = rect.left +52;
			break;
		case 3:rect.top = 313;
			rect.bottom = 388;
			rect.left = 113;
			rect.right = rect.left + 47;
			break;
		case 4:rect.top = 313;
			rect.bottom = 388;
			rect.left = 171;
			rect.right = rect.left + 83;
			break;
		case 5:rect.top = 313;
			rect.bottom = 388;
			rect.left = 260;
			rect.right = rect.left +51;
			break;

		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);

}

