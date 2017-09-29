#pragma once
#ifndef _ALADDIN_STAND_H__
#define _ALADDIN_STAND_H__
#include"ALADDIN.h"
#include"GLOBAL.h"
#define COUNT_FRAME 12
class AladdinStand :public AladdinAction
{
public:
	AladdinStand(D3DXVECTOR3 startLocation);
	~AladdinStand();

	void					Activities(GLOBAL::DIRECTION direction);

	void					SetEndLocation(D3DXVECTOR3 location);
private:
	private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
};

#endif _ALADDIN_STAND_H__
