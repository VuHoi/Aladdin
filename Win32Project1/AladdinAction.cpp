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
int frame = 1;

void AladdinAction::Activities(GLOBAL::DIRECTION direction)
{
	int i = this->GetCurrentFrame();
	
	if (GLOBAL::GetState()==GLOBAL::STAND)
	{
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y-20);
		this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2.3, this->mSprite->GetScale().y * 2.3));
		frame = 1;
	}
	else
	if (GLOBAL::GetState() == GLOBAL::SIT)
	{
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
		if (frame++ < 4)
		{
		
			this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		}
		else
		{
			this->mSprite->Draw(3, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
		}
	}
	else 
	{
		frame = 1;
		this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
		this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x * 2, this->mSprite->GetScale().y * 2));
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
