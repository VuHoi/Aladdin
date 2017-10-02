#include "AladdinAction.h"
#include "GAME.h"

D3DXVECTOR3		AladdinAction::mCurrentLocation = D3DXVECTOR3(0, 0, 0);
D3DXVECTOR3		AladdinAction::mEndLocation = D3DXVECTOR3(0, 0, 0);
AladdinAction::AladdinAction()
{
}

AladdinAction::~AladdinAction()
{
	if (this->mSprite)
		delete(this->mSprite);
}
int frameSit = 1;
int frameDrop = 1;
int frameAfterDrop = 1;
void UpdateFrame()
{
	frameSit = 1;
	frameDrop = 1;
	frameAfterDrop = 1;
}
void AladdinAction::Activities(GLOBAL::DIRECTION direction)
{
	int i = this->GetCurrentFrame();
	GLOBAL::STATE state = GLOBAL::GetState();

	switch (state)
	{
	case GLOBAL::CLIMB:
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
		if(direction==GLOBAL::UP)
			this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		if (direction == GLOBAL::DOWN)
			this->mSprite->Draw(10-i, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		if (direction == GLOBAL::NONE)
			this->mSprite->Draw(6, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		UpdateFrame();
		break;
	case GLOBAL::STAND:
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y - 20);
		this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2.3, this->mSprite->GetScale().y * 2.3));
		UpdateFrame();
		break;
	case GLOBAL::SIT:
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
		if (frameSit++ <= 3)
		{

			this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		}
		else
		{
			this->mSprite->Draw(3, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		}
		break;
	case GLOBAL::FIGHT:
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y - 10);
		this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2.1, this->mSprite->GetScale().y * 2.1));
		UpdateFrame();
		break;
	case GLOBAL::SITFIGHT:
		if (mCurrentFrame == 4)
			this->mSprite->SetPosition(mCurrentLocation.x + 20, mCurrentLocation.y + 10);
		else
			this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y + 10);
		this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2.1, this->mSprite->GetScale().y * 2.1));
		UpdateFrame();
		break;
	case GLOBAL::AFTERDROP:
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y + 5);
		if(frameAfterDrop++<=11)
			this->mSprite->Draw(frameAfterDrop-1, D3DXVECTOR2(this->mSprite->GetScale().x * 2.2, this->mSprite->GetScale().y * 2.2));
		break;
	case GLOBAL::DROP:
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
		if (mCurrentLocation.y < AladdinAction::mEndLocation.y)
		{
			if (frameDrop++ <=8)
			{
				GLOBAL::SetFrameRate(15);
				this->mSprite->Draw(frameDrop-1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
			}
			else
			{
				this->mSpeed = 40;
				GLOBAL::SetFrameRate(15);
				this->mSprite->Draw(9 - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
				this->mCurrentFrame = 1;
			}
		
			
		}
		break;

	

	default:
		UpdateFrame();
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
		this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		break;
	}
	
	this->SetUpCurrentFrame();
	this->Update(direction);
}

void AladdinAction::SetCurrentLocation(D3DXVECTOR3 location)
{
	mCurrentLocation = location;
}

D3DXVECTOR3 AladdinAction::GetCurrentLocation()
{
	return mCurrentLocation;
}

void AladdinAction::SetSpeed(float speed)
{
	this->mSpeed = speed;
}

void AladdinAction::SetEndLocation(D3DXVECTOR3 location)
{
	mEndLocation = location;
}

D3DXVECTOR3 AladdinAction::GetEndLocation()
{
	return mEndLocation;
}

int AladdinAction::GetCurrentFrame()
{
	return this->mCurrentFrame;
}

void AladdinAction::SetUpCurrentFrame()
{
	mCurrentFrame = (mCurrentFrame >= this->mEndFrame) ? this->mStartFrame : ++mCurrentFrame;

}
