#pragma once
#ifndef _ALADDIN_DROP_H__
#define _ALADDIN_DROP_H__

#include"AladdinAction.h"
#include"ALADDIN.h"
#include"GLOBAL.h"
#define COUNT_FRAME 9
//Thể hiện hành động nhảy xuống của Aladdin
class AladdinDrop :public AladdinAction
{
public:
	AladdinDrop(D3DXVECTOR3 startLocation);

	~AladdinDrop();
	void					Activities(GLOBAL::DIRECTION direction);

	void					SetEndLocation(D3DXVECTOR3 location);
private:
	void					Update(GLOBAL::DIRECTION direction);

	void					LoadResource();

	void					SetUpCurrentFrame();

	D3DXVECTOR3				mEndLocation;
};

#endif _ALADDIN_DROP_H__