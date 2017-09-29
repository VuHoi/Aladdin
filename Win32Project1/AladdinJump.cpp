#include "AladdinJump.h"



AladdinJump::AladdinJump()
{
}


AladdinJump::~AladdinJump()
{
}


#include "AladdinWalk.h"



AladdinJump::AladdinJump(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 18;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 9;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}


bool					directJump = false;
//Check current direction
void AladdinJump::Activities(GLOBAL::DIRECTION direction)
{

	GLOBAL::SetFrameRate(30);


	if (direction == GLOBAL::LEFT)
	{
		if (directJump)
		{
			this->mSprite->FlipVertical(true);
			directJump = false;
		}
	}
	else if (direction == GLOBAL::RIGHT)
	{
		if (!directJump)
		{
			this->mSprite->FlipVertical(false);
			directJump = true;
		}
	}
	AladdinAction::Activities(direction);
}

void AladdinJump::Update(GLOBAL::DIRECTION direction)
{

	if (mCurrentFrame <= 5 && mCurrentFrame>1)
	{
		if (direction == GLOBAL::RIGHT)
			AladdinAction::mCurrentLocation.x +=25;
		else
			AladdinAction::mCurrentLocation.x -= 25;
		AladdinAction::mCurrentLocation.y -=25;
	}
	if(mCurrentFrame<=9&&mCurrentFrame >5)
	{
		if (direction == GLOBAL::RIGHT)
			AladdinAction::mCurrentLocation.x += 20;
		else
			AladdinAction::mCurrentLocation.x -= 20;
		AladdinAction::mCurrentLocation.y += 25;
	}
	
}

void AladdinJump::LoadResource()
{
	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		switch (i)
		{
		case 1:rect.top = 703;
			rect.bottom = rect.top+45;
			rect.left = 7;
			rect.right = rect.left + 44;
			break;
		case 2:rect.top = 683;
			rect.bottom = rect.top + 79;
			rect.left = 66;
			rect.right = rect.left + 45;
			break;
		case 3:rect.top = 686;
			rect.bottom = rect.top + 60;
			rect.left =124;
			rect.right = rect.left + 57;
			break;
		case 4:rect.top = 697;
			rect.bottom = rect.top + 44;
			rect.left = 199;
			rect.right = rect.left + 59;
			break;
		case 5:rect.top =694;
			rect.bottom = rect.top+50;
			rect.left =273;
			rect.right = rect.left + 63;
			break;
		case 6:rect.top = 692;
			rect.bottom = rect.top + 52;
			rect.left = 348;
			rect.right = rect.left + 61;
			break;
		case 7:rect.top = 687;
			rect.bottom = rect.top + 59;
			rect.left = 419;
			rect.right = rect.left + 54;
			break;
		case 8:rect.top = 680;
			rect.bottom = rect.top + 86;
			rect.left = 490;
			rect.right = rect.left + 51;
			break;
		case 9:rect.top = 718;
			rect.bottom = rect.top + 45;
			rect.left = 560;
			rect.right = rect.left + 61;
			break;

		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);

}
