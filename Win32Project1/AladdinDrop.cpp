#include "AladdinDrop.h"




AladdinDrop::AladdinDrop(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 20;
	mCurrentLocation = startLocation;
	this->mStartFrame = 1;
	this->mEndFrame = 10;
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
	else
		this->mSprite->FlipVertical(false);

	AladdinAction::Activities(direction);


	
}

void AladdinDrop::SetEndLocation(D3DXVECTOR3 location)
{
	this->mEndLocation = location;
}

void AladdinDrop::Update(GLOBAL::DIRECTION direction)
{
	if (direction == GLOBAL::LEFT)
	{
		mCurrentLocation.x -= 10;
	}
	if (direction == GLOBAL::RIGHT)
	{
		mCurrentLocation.x += 10;
	}
	mCurrentLocation.y += this->mSpeed;
}

void AladdinDrop::LoadResource()
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
			rect.left = 72;
			rect.top = 826;
			rect.right = rect.left + 56;
			rect.bottom = rect.top + 64;

			break;
		case 2:
			rect.left =135;
			rect.top = 827;
			rect.right = rect.left + 56;
			rect.bottom = rect.top + 64;

			break;
		case 3:
			rect.left = 201;
			rect.top = 822;
			rect.right = rect.left + 57;
			rect.bottom = rect.top + 71;

			break;
		case 4:
			rect.left = 267;
			rect.top = 820;
			rect.right = rect.left + 53;
			rect.bottom = rect.top + 74;

			break;
		case 5:
			rect.left = 333;
			rect.top = 828;
			rect.right = rect.left + 42;
			rect.bottom = rect.top + 68;

			break;
		case 6:
			rect.left = 387;
			rect.top = 815;
			rect.right = rect.left + 41;
			rect.bottom = rect.top + 83;

		case 7:
			rect.left = 447;
			rect.top = 806;
			rect.right = rect.left + 35;
			rect.bottom = rect.top + 96;
			break;
		case 8:
			rect.left = 501;
			rect.top = 806;
			rect.right = rect.left + 38;
			rect.bottom = rect.top + 98;
			break;
		case 9:
			rect.left = 563;
			rect.top = 811;
			rect.right = rect.left + 37;
			rect.bottom = rect.top + 96;
			break;
		/*case 10:
			rect.left = 11;
			rect.top = 899;
			rect.right = rect.left + 59;
			rect.bottom = rect.top + 87;
			break;*/
		/*case 11:
			rect.left = 83;
			rect.top = 910;
			rect.right = rect.left + 61;
			rect.bottom = rect.top + 68;
			break;
		case 12:
			rect.left = 142;
			rect.top = 941;
			rect.right = rect.left + 74;
			rect.bottom = rect.top + 39;
			break;
		case 13:
			rect.left = 212;
			rect.top = 944;
			rect.right = rect.left + 69;
			rect.bottom = rect.top + 35;
			break;
		case 14:
			rect.left = 287;
			rect.top = 947;
			rect.right = rect.left + 72;
			rect.bottom = rect.top + 34;
			break;
		case 15:
			rect.left = 364;
			rect.top = 947;
			rect.right = rect.left + 80;
			rect.bottom = rect.top + 36;
			break;
		case 16:
			rect.left = 452;
			rect.top = 932;
			rect.right = rect.left + 87;
			rect.bottom = rect.top + 51;
			break;
		case 17:
			rect.left = 550;
			rect.top = 927;
			rect.right = rect.left + 88;
			rect.bottom = rect.top + 57;
			break;
		case 18:
			rect.left = 645;
			rect.top = 924;
			rect.right = rect.left + 95;
			rect.bottom = rect.top + 62;
			break;
		case 19:
			rect.left = 747;
			rect.top = 924;
			rect.right = rect.left + 99;
			rect.bottom = rect.top + 62;
			break;
		case 20:
			rect.left = 852;
			rect.top = 924;
			rect.right = rect.left +106;
			rect.bottom = rect.top + 62;
			break;*/

		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255,0, 255), listSourceRect);

}

void AladdinDrop::SetUpCurrentFrame()
{
	this->mCurrentFrame += (this->mCurrentFrame <= this->mEndFrame) ? 1 : 0;
}
