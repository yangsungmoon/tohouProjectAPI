#include "stdafx.h"
#include "card.h"

card::card():CARDMAX(400), _width(5), _height(5)
{
}


card::~card()
{
}

void card::init(float x, float y, float speed, float angle, int damage)
{
	_x = x;
	_y = y;
	_speed = speed;
	_angle = angle;
	_damage = damage;
	_isFire = true;
}
void card::update()
{
	float tempX = _x;
	float tempY = _y;

	_x = _x + cosf(_angle) * _speed * TIMEMANAGER->getElapsedTime();
	_y = _y + -sinf(_angle) * _speed * TIMEMANAGER->getElapsedTime();

	if (isCollision()) {
		_isFire = false;
	}
}
void card::render()
{
	Rectangle(getMemDC(), _x - _width / 2, _y - _height / 2, _x + _width / 2, _y + _height / 2);
}
void card::release()
{

}
bool card::isCollision()
{
	if (GAMESCREENLEFT > _x || _x > GAMESCREENRIGHT ||
		GAMESCREENTOP > _y || _y > GAMESCREENBOTTOM)
	{
		return true;
	}
	
	return false;
}

float card::calcAngle(float _tx, float _ty)
{
	float deltaX = _tx - _x;
	float deltaY = _ty - _y;

	float distance = sqrtf(deltaX * deltaX + deltaY * deltaY);

	float angle = acosf(deltaX / distance);

	/* 완전유도
	if (y < getcY())
	{
		angle = 2 * PI - angle;
		if (angle >= 2 * PI) angle -= 2 * PI;
	}
	*/
	return angle;
}