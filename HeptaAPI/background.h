#pragma once
#include "gameNode.h"
class backGround :
	public gameNode
{
private:
	float _speed;
	float _sliceY;

public:
	backGround();
	~backGround();

	virtual HRESULT init(float);
	void update();
	void render();
	void release();

	void setSpeed(float speed) { _speed = speed; }
};

