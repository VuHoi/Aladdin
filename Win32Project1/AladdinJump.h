#pragma once
#ifndef _ALADDIN_JUMP_H__
#define _ALADDIN_JUMP_H__

#include"AladdinAction.h"
#include"ALADDIN.h"
#include<vector>
#include"GLOBAL.h"
using namespace std;
#define COUNT_FRAME 13
class AladdinJump :public AladdinAction
{
public:
	AladdinJump();
	~AladdinJump();
	AladdinJump(D3DXVECTOR3 startLocation);
	void				Activities(GLOBAL::DIRECTION direction);
private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
};


#endif _ALADDIN_JUMP_H__