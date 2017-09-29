#include "AladdinWalk.h"



AladdinWalk::AladdinWalk(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 18	;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame = 3;
	this->mEndFrame = 13;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}

AladdinWalk::~AladdinWalk()
{
}


bool					direct = false;
 //Check current direction
void AladdinWalk::Activities(GLOBAL::DIRECTION direction)
{

	GLOBAL::SetFrameRate(35);


	if (direction == GLOBAL::LEFT)
	{
		if (direct)
		{
			this->mSprite->FlipVertical(true);
			direct = false;
		}
	}
	else if(direction==GLOBAL::RIGHT)
	{
		if (!direct)
		{
			this->mSprite->FlipVertical(false);
			direct = true;
		}
	}
	AladdinAction::Activities(direction);
}

void AladdinWalk::Update(GLOBAL::DIRECTION direction)
{
	AladdinAction::mCurrentLocation.x += (direction == GLOBAL::RIGHT) ? this->mSpeed : 0;
	AladdinAction::mCurrentLocation.x += (direction == GLOBAL::LEFT) ? (-this->mSpeed) : 0;
}

void AladdinWalk::LoadResource()
{
	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		rect.top = 1212;
		rect.bottom = 1275;
		switch (i)
		{
		case 1:
		{
			rect.left = 7;
			rect.right = 57;
			break;
		}
		case 2:
		{
			rect.left = 60;
			rect.right = 110;
			break;
		}
		case 3:
		{
			rect.left = 113;
			rect.right = 163;
			break;
		}
		case 4:
		{
			rect.left = 162;
			rect.right = 212;
			break;
		}
		case 5:
		{
			rect.left = 219;
			rect.right = 279;
			break;
		}
		case 6:
		{
			rect.left = 276;
			rect.right = 334;
			break;
		}
		case 7:
		{
			rect.left = 326;
			rect.right = 386;
			break;
		}
		case 8:
		{
			rect.left = 376;
			rect.right = 436;
			break;
		}
		case 9:
		{
			rect.left = 431;
			rect.right = 479;
			break;
		}
		case 10:
		{
			rect.left = 487;
			rect.right = 543;
			break;
		}
		case 11:
		{
			rect.left = 547;
			rect.right = 608;
			break;
		}
		case 12:
		{
			rect.left = 609;
			rect.right = 671;
			break;
		}
		case 13:
		{
			rect.left = 669;
			rect.right = 731;
			break;
		}
		}


		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);
}
