#include "AladdinAfterDrop.h"



AladdinAfterDrop::AladdinAfterDrop()
{
}


AladdinAfterDrop::~AladdinAfterDrop()
{
}
AladdinAfterDrop::AladdinAfterDrop(D3DXVECTOR3 startLocation)
{
	this->mSpeed = 18;
	AladdinAction::mCurrentLocation = startLocation;
	this->mStartFrame =1;
	this->mEndFrame = 11;
	this->mCurrentFrame = this->mStartFrame;
	this->LoadResource();
}
void AladdinAfterDrop::Activities(GLOBAL::DIRECTION direction)
{
	GLOBAL::SetFrameRate(30);
	if (direction == GLOBAL::LEFT)
		this->mSprite->FlipVertical(true);
	else
		this->mSprite->FlipVertical(false);
	AladdinAction::Activities(direction);
}


void AladdinAfterDrop::Update(GLOBAL::DIRECTION direction)
{

}
void AladdinAfterDrop::LoadResource()
{

	vector<RECT> listSourceRect;
	char filePath[100];
	sprintf_s(filePath, "AladdinAction/Aladdin.png");
	for (int i = 1; i <= COUNT_FRAME; i++)
	{
		RECT rect;
		switch (i)
		{
	/*	case 1:
			rect.left = 83;
			rect.top = 910;
			rect.right = rect.left + 61;
			rect.bottom = rect.top + 68;
			break;
		case 2:
			rect.left = 142;
			rect.top = 941;
			rect.right = rect.left + 74;
			rect.bottom = rect.top + 39;
			break;
		case 3:
			rect.left = 212;
			rect.top = 944;
			rect.right = rect.left + 69;
			rect.bottom = rect.top + 35;
			break;
		case 4:
			rect.left = 287;
			rect.top = 947;
			rect.right = rect.left + 72;
			rect.bottom = rect.top + 34;
			break;
		case 5:
			rect.left = 364;
			rect.top = 947;
			rect.right = rect.left + 80;
			rect.bottom = rect.top + 36;
			break;
		case 6:
			rect.left = 452;
			rect.top = 932;
			rect.right = rect.left + 87;
			rect.bottom = rect.top + 51;
			break;
		case 7:
			rect.left = 550;
			rect.top = 927;
			rect.right = rect.left + 88;
			rect.bottom = rect.top + 57;
			break;
		case 8:
			rect.left = 645;
			rect.top = 924;
			rect.right = rect.left + 95;
			rect.bottom = rect.top + 62;
			break;
		case 9:
			rect.left = 747;
			rect.top = 924;
			rect.right = rect.left + 99;
			rect.bottom = rect.top + 62;
			break;
		case 10:
			rect.left = 852;
			rect.top = 924;
			rect.right = rect.left + 106;
			rect.bottom = rect.top + 62;
			break;
		case 11:
			rect.left = 967;
			rect.top = 926;
			rect.right = rect.left + 106;
			rect.bottom = rect.top + 56;
			break;*/
		case 1:
			rect.left = 83;
			rect.top = 924;
			rect.right = rect.left + 61;
			rect.bottom = rect.top + 62;
			break;
		case 2:
			rect.left = 142;
			rect.top = 924;
			rect.right = rect.left + 74;
			rect.bottom = rect.top + 62;
			break;
		case 3:
			rect.left = 212;
			rect.top = 924;
			rect.right = rect.left + 69;
			rect.bottom = rect.top + 62;
			break;
		case 4:
			rect.left = 287;
			rect.top = 924;
			rect.right = rect.left + 72;
			rect.bottom = rect.top + 62;
			break;
		case 5:
			rect.left = 364;
			rect.top = 924;
			rect.right = rect.left + 80;
			rect.bottom = rect.top + 62;
			break;
		case 6:
			rect.left = 452;
			rect.top = 924;
			rect.right = rect.left + 87;
			rect.bottom = rect.top + 62;
			break;
		case 7:
			rect.left = 550;
			rect.top = 924;
			rect.right = rect.left + 88;
			rect.bottom = rect.top + 62;
			break;
		case 8:
			rect.left = 645;
			rect.top = 924;
			rect.right = rect.left + 95;
			rect.bottom = rect.top + 62;
			break;
		case 9:
			rect.left = 747;
			rect.top = 924;
			rect.right = rect.left + 99;
			rect.bottom = rect.top + 62;
			break;
		case 10:
			rect.left = 852;
			rect.top = 924;
			rect.right = rect.left + 106;
			rect.bottom = rect.top + 62;
			break;
		case 11:
			rect.left = 967;
			rect.top = 926;
			rect.right = rect.left + 106;
			rect.bottom = rect.top + 62;
			break;

		}
		listSourceRect.push_back(rect);
	}

	this->mSprite = new SPRITE(filePath, D3DCOLOR_XRGB(255, 0, 255), listSourceRect);

}

