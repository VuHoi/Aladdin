#include "ALADDIN.h"



ALADDIN::ALADDIN(D3DXVECTOR3 startLocation)
{
	this->mAction[GLOBAL::WALK] = new AladdinWalk(startLocation);
	this->mAction[GLOBAL::CLIMB] = new AladdinClimb(startLocation);
	this->mAction[GLOBAL::SWING] = new AladdinSwing(startLocation);
	this->mAction[GLOBAL::DROP] = new AladdinDrop(startLocation);
	this->mAction[GLOBAL::STAND] = new AladdinStand(startLocation);
	this->mAction[GLOBAL::SIT] = new AladdinSit(startLocation);
	this->mAction[GLOBAL::FIGHT] = new AladdinFight(startLocation);
	this->mAction[GLOBAL::JUMP] = new AladdinJump(startLocation);
	this->mAction[GLOBAL::SITFIGHT] = new AladdinSitFight(startLocation);
	this->mAction[GLOBAL::AFTERDROP] = new AladdinAfterDrop(startLocation);
	this->mCurrentLocation = startLocation;
}


ALADDIN::~ALADDIN()
{
}

void ALADDIN::Activities(GLOBAL::STATE state, GLOBAL::DIRECTION direction)
{
	this->mAction[state]->Activities(direction);
}

AladdinAction ** ALADDIN::GetAction()
{
	return this->mAction;
}

D3DXVECTOR3 ALADDIN::GetCurrentLocation()
{
	return AladdinAction::GetCurrentLocation();
}

void ALADDIN::SetCurrentLocation(D3DXVECTOR3 location)
{
	AladdinAction::SetCurrentLocation(location);
}

void ALADDIN::SetEndLocation(D3DXVECTOR3 location)
{
	AladdinAction::SetEndLocation(location);
}

D3DXVECTOR3 ALADDIN::GetEndLocation()
{
	return AladdinAction::GetEndLocation();;
}

void ALADDIN::SetSpeed(float speed, GLOBAL::STATE state)
{
	this->mAction[state]->SetSpeed(speed);
}



