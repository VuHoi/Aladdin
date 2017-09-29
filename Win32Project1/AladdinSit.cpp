#include "AladdinSit.h"



AladdinSit::AladdinSit()
{
}


AladdinSit::~AladdinSit()
{
}
AladdinSit::AladdinSit(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 5;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame =4;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();

}
bool flag = false;
void AladdinSit::Activities(GLOBAL::DIRECTION direction)
{
	
	GLOBAL::SetFrameRate(35);
	if (direction == GLOBAL::LEFT)
	{
		if (flag)
		{
			this->mSprite->FlipVertical(true);
			flag = false;
		}
	}

	else if (direction == GLOBAL::RIGHT)
	{
		if (!flag)
		{
			this->mSprite->FlipVertical(false);
			flag = true;
		}
	}
	AladdinAction::Activities(direction);
}

void AladdinSit::SetEndLocation(D3DXVECTOR3 location)
{
	this->mEndLocation = location;
}

void AladdinSit::Update(GLOBAL::DIRECTION direction)
{
	//mCurrentLocation.y += this->mSpeed;
}

void AladdinSit::LoadResource()
{

	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		switch (i)
		{
		case 1:rect.top = 499;
			rect.bottom = 550;
			rect.left = 204;
			rect.right = rect.left + 43;
			break;
		case 2:rect.top = 499;
			rect.bottom = 550;
			rect.left = 258;
			rect.right = rect.left + 49;
			break;
		case 3:rect.top = 499;
			rect.bottom = 550;
			rect.left = 314;
			rect.right = rect.left + 56;
			break;
		case 4:rect.top = 499;
			rect.bottom = 550;
			rect.left = 377;
			rect.right = rect.left +55;
			break;

		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);

}

