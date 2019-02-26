#include "stdafx.h"
#include "enemy.h"


enemy::enemy() :_width(10), _height(10)
{
}

enemy::enemy(int width, int height) : _width(width), _height(height)
{
}

enemy::~enemy()
{
}

void enemy::init(float x, float y, int hp, float sizeX, float sizeY, float speed)
{
	_x = x;
	_y = y;
	_hp = hp;

	_angle = 3.14 / 2;
	_speed = speed;
	
	_state = INVINCIBILITY;

	_my_x = 0;
	_my_y = 0;
}
void enemy::update(float my_x, float my_y) {
	if (_y >= 16 && _state != DEAD) _state = PLAY;
	_my_x = my_x;
	_my_y = my_y;
	enemyMove();

	if (isCollision() && _state == PLAY) {
		_state = DEAD;
	}
}
void enemy::render() {
		//Ellipse(getMemDC(), _x, _y, _x + _sizeX, _y + _sizeY);
}
void enemy::release() {

}

RECT enemy::getRect() {
	int shotRange = 2;

	RECT rc = {
		getX() - shotRange,
		getY() - shotRange,
		getX() + shotRange,
		getY() + shotRange
	};

	return rc;
}

bool enemy::hpCheck() {
	if (getHp() <= 0) {
		
		return true;
	}

	return false;
}
bool enemy::isCollision() {
	if (GAMESCREENLEFT > _x || _x > GAMESCREENRIGHT ||
		GAMESCREENTOP > _y || _y > GAMESCREENBOTTOM)
	{
		return true;
	}

	return false;
	return false;
}