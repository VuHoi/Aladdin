#pragma once
#ifndef _ALADDIN_WALK_H__
#define _ALADDIN_WALK_H__
#include"AladdinAction.h"
#include"ALADDIN.h"
#include<vector>
#include"GLOBAL.h"
using namespace std;
#define COUNT_FRAME 13

class AladdinWalk :public AladdinAction
{
public:
	AladdinWalk(D3DXVECTOR3 startLocation);
	~AladdinWalk();
	void				Activities(GLOBAL::DIRECTION direction);
private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();

};

#endif _ALADDIN_WALK_H__