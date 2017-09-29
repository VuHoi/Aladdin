#pragma once

#ifndef _ALADDIN_FIGHT_H__

#include"ALADDIN.h"
#include"GLOBAL.h"
#define COUNT_FRAME 5
class AladdinFight :public AladdinAction
{
public:
	AladdinFight();
	~AladdinFight();
	AladdinFight(D3DXVECTOR3 startLocation);
	void					Activities(GLOBAL::DIRECTION direction);

	void					SetEndLocation(D3DXVECTOR3 location);
private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
};

#endif _ALADDIN_FIGHT_H__