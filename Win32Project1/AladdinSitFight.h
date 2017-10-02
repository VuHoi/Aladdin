#pragma once
#ifndef _ALADDIN_SITFIGHT_H__

#include"ALADDIN.h"
#include"GLOBAL.h"
#define COUNT_FRAME 7
class AladdinSitFight:public AladdinAction
{
public:
	AladdinSitFight();
	~AladdinSitFight();
	AladdinSitFight(D3DXVECTOR3 startLocation);
	void					Activities(GLOBAL::DIRECTION direction);

	void					SetEndLocation(D3DXVECTOR3 location);
private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
};
#pragma once


#endif _ALADDIN_SITFIGHT_H__