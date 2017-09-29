#pragma once
#ifndef _ALADDIN_CLIMB_H__
#define _ALADDIN_CLIMB_H__

#include"AladdinAction.h"
#include"ALADDIN.h"
#include"GLOBAL.h"
#define COUNT_FRAME 10
//Thể hiện hành động leo của Aladdin
class AladdinClimb :public AladdinAction
{
public:
	AladdinClimb(D3DXVECTOR3 startLocation);
	~AladdinClimb();
	void				Activities(GLOBAL::DIRECTION direction);
private:
	void				Update(GLOBAL::DIRECTION direction);

	void				LoadResource();
};

#endif _ALADDIN_CLIMB_H__