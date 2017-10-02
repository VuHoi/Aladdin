#pragma once
#ifndef _ALADDIN_AFTERDROP_H__
#define _ALADDIN_AFTERDROP_H__
#include"AladdinAction.h"
#include"ALADDIN.h"
#include<vector>
#include"GLOBAL.h"
using namespace std;
#define COUNT_FRAME 11
class AladdinAfterDrop :public AladdinAction
{
public:
	AladdinAfterDrop();
	~AladdinAfterDrop();
	AladdinAfterDrop(D3DXVECTOR3 startLocation);
	void				Activities(GLOBAL::DIRECTION direction);
private:
	//Update sprite location
	void				Update(GLOBAL::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
};

#endif _ALADDIN_AFTERDROP_H__