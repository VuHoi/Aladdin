#include "AladdinStand.h"


AladdinStand::~AladdinStand()
{

}




AladdinStand::AladdinStand(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 5;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 12;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}
bool	directStand = false;
void AladdinStand::Activities(GLOBAL::DIRECTION direction)
{
	
	GLOBAL::SetFrameRate(35);


	if (direction == GLOBAL::LEFT)
		this->mSprite->FlipVertical(true);
	else
		this->mSprite->FlipVertical(false);
	AladdinAction::Activities(direction);

}

void AladdinStand::SetEndLocation(D3DXVECTOR3 location)
{
	this->mEndLocation = location;
}

void AladdinStand::Update(GLOBAL::DIRECTION direction)
{
	//mCurrentLocation.y += this->mSpeed;
}

void AladdinStand::LoadResource()
{

	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i =1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		switch(i)
		{
		case 1:rect.top = 57;
			rect.bottom =135;
			rect.left = 180 ;
			rect.right = rect.left + 43;
			break;
		case 2:rect.top = 57;
			rect.bottom =135;
			rect.left = 226 ;
			rect.right = rect.left + 43;
			break;
		case 3:rect.top = 57;
			rect.bottom = 135;
			rect.left = 274;
			rect.right = rect.left + 38;
			break;
		case 4:rect.top = 57;
			rect.bottom = 135;
			rect.left = 318;
			rect.right = rect.left + 43;
			break;
		case 5:rect.top =57;
			mCurrentLocation.y-= 3;
			rect.bottom = 135;
			rect.left = 365;
			rect.right = rect.left + 43;
			break;
		case 6:rect.top = 57;
			//mCurrentLocation.y -= 80-59;
			rect.bottom = 135;
			rect.left = 415;
			rect.right = rect.left + 45;
			break;
		case 7:rect.top = 57;
			//mCurrentLocation.y-= 80 - 55;
			rect.bottom =135;
			rect.left = 465;
			rect.right = rect.left + 45;
			break;
		case 8:rect.top =57;
			//mCurrentLocation.y -= 80 - 61;
			rect.bottom =135;
			rect.left = 515;
			rect.right = rect.left + 45;
			break;
		case 9:rect.top = 57;
			//mCurrentLocation.y -= 80 - 70;
			rect.bottom = 135;
			rect.left =566;
			rect.right = rect.left + 45;
			break;
		case 10:rect.top =57;
			
			rect.bottom = 135;
			rect.left = 617;
			rect.right = rect.left + 45;
			break;
		case 11:rect.top = 57;
		
			rect.bottom = 135;
			rect.left = 665;
			rect.right = rect.left + 45;
			break;
		case 12:rect.top =57;
		
			rect.bottom = 135;
			rect.left = 712;
			rect.right = rect.left + 43;
			break;

		}
		

		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);

}

