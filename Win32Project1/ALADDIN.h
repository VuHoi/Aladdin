#pragma once
#ifndef __ALADDIN_H__
#define	__ALADDIN_H__
#include"SPRITE.h"
#include<vector>
#include"AladdinAction.h"
#include"AladdinWalk.h"
#include"AladdinClimb.h"
#include"AladdinSwing.h"
#include"AladdinDrop.h"
#include "AladdinStand.h"
#include "AladdinSit.h"
#include "AladdinFight.h"
#include "AladdinJump.h"
using namespace std;

class ALADDIN
{
public:
	/*
	startLocation: Điểm xuất phát của aladdin
	..*/
	ALADDIN(D3DXVECTOR3 startLocation);
	~ALADDIN();
	void		Render();
	/*state: Trạng thái của aladdin (Walk, Down, Up...)
	direction: Hướng đi của aladdin
	..*/
	void				Activities(GLOBAL::STATE state, GLOBAL::DIRECTION direction);
	AladdinAction**		GetAction();
	D3DXVECTOR3			GetCurrentLocation();
	void				SetCurrentLocation(D3DXVECTOR3 location);
	void				SetEndLocation(D3DXVECTOR3 location);
	D3DXVECTOR3			GetEndLocation();
	void				SetSpeed(float speed, GLOBAL::STATE state = GLOBAL::DROP);
protected:
	AladdinAction*		mAction[8];
	D3DXVECTOR3			mCurrentLocation;
};

#endif _ALADDIN_H__