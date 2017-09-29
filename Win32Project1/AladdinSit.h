#pragma once
#ifndef _ALADDIN_SIT_H__
#define _ALADDIN_SIT_H__


#include"ALADDIN.h"
#include"GLOBAL.h"

#define COUNT_FRAME 4
class AladdinSit :public AladdinAction
{
public:
	AladdinSit();
	AladdinSit(D3DXVECTOR3 startLocation);
	void					Activities(GLOBAL::DIRECTION direction);

	void					SetEndLocation(D3DXVECTOR3 location);
	~AladdinSit();
private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
	//Check direct
};

#endif _ALADDIN_SIT_H__
