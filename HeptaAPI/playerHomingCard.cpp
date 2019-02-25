#include "stdafx.h"
#include "playerHomingCard.h"



playerHomingCard::playerHomingCard()
{
}

playerHomingCard::~playerHomingCard()
{
}

void playerHomingCard::update()
{
	if(_homingSwi){
		if (_enemy == NULL) {
			_enemyX = GAMESCREENLEFT + GAMESCREENWIDTH / 2;
			_enemyY = GAMESCREENTOP;
		}
		else {
			_enemyX = _enemy->getX();
			_enemyY = _enemy->getY();
		}
		setAngle(calcAngle(_enemyX, _enemyY));
	}
	else{
		transHoming();
	}

	setX(getX() + cosf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
	setY(getY() + -sinf(getAngle()) * getSpeed()* TIMEMANAGER->getElapsedTime());

	if (isCollision()) {
		setIsFire(false);
	}
}
void playerHomingCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth() / 2, getY() - getHeight() / 2, getX() + getWidth() / 2, getY() + getHeight() / 2);
}

void playerHomingCard::setHomingInit(enemy* __enemy)
{
	_enemy = __enemy;
	_homingSwi = false;
	_homingCounter = 0.01f;
}

void playerHomingCard::transHoming()
{
	if(_homingCounter > 0){
		_homingCounter -= TIMEMANAGER->getElapsedTime();
	}
	else {
 		_homingSwi = true;
	}
}