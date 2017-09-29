#pragma once
#ifndef __ALADDINACTION_H__
#define __ALADDINACTION_H__
#include"GLOBAL.h"
#include"SPRITE.h"

//Thể hiện các hành động di chuyển của aladdin
class AladdinAction
{
public:
	AladdinAction();
	~AladdinAction();
	/*
	Direction: Phương hướng
	..*/
	virtual	void			Activities(GLOBAL::DIRECTION direction);
	/*Thay đổi vị trí hiện tại của animation
	..*/
	static void				SetCurrentLocation(D3DXVECTOR3 location);
	static D3DXVECTOR3		GetCurrentLocation();
	/*Thay đổi tốc độ animation
	..*/
	void					SetSpeed(float speed);
	static void				SetEndLocation(D3DXVECTOR3 location);
	static D3DXVECTOR3				GetEndLocation();

protected:
	virtual int				GetCurrentFrame();	//lấy chỉ số frame hiện tại
	virtual void			SetUpCurrentFrame();//Tăng chỉ số frame
	/*
	direction: Hướng đi của animation
	..*/
	virtual void			Update(GLOBAL::DIRECTION direction) = 0;
	int						mCurrentFrame;		//Index hiện tại của animation
	int						mStartFrame;		//Index bắt đầu trong một mảng sprite
	int						mEndFrame;			//Index cuối cùng trong mảng sprite
	static D3DXVECTOR3		mCurrentLocation;	//Vị trí hiện tại của animation						
	SPRITE*					mSprite;			//Biến thể hiện Sprite
	float					mSpeed;				//Tốc độc của aladdin
	static D3DXVECTOR3		mEndLocation;		//Vị trí kết thúc hoạt động

	
};

#endif __ALADDINACTION_H__