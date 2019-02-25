#pragma once
#include "gameNode.h"
#include "enemy.h"

class card :
	public gameNode
{
private:
	const int CARDMAX;

	const int _width;
	const int _height;
	
	float _x;
	float _y;

	float _speed;
	float _angle;

	int	  _damage;

	bool _isFire;
public:
	card();
	~card();

	virtual void init(float x, float y, float speed, float angle, int damage);
	virtual void update();
	virtual void render();
	void release();

	int getCardMax() { return CARDMAX; }

	int getWidth() { return _width; }
	int getHeight() { return _height; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }

	float getY() { return _y; }
	void setY(float y) { _y = y; }

	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }

	float getAngle() { return _angle; }
	void setAngle(float angle) { _angle = angle; }

	void setDamage(int damage) { _damage = damage; }
	int getDamage() { return _damage; }

	bool getIsFire() { return _isFire; }
	void setIsFire(bool swi) { _isFire = swi; }

	bool isCollision();

	// 유도용 빈 함수
	virtual void setHomingInit(enemy* _enemy) {};
	float calcAngle(float _tx, float _ty);
};

