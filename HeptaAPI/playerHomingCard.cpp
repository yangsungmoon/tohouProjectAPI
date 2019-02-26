#include "stdafx.h"
#include "playerHomingCard.h"



playerHomingCard::playerHomingCard()
{
	playerCard();
	_homingSwi = false;
	_homingCounter = 0.01f;
}

playerHomingCard::~playerHomingCard()
{
}

void playerHomingCard::update()
{
	if(_homingSwi){
		if (getEnemy() == NULL) {
			_enemyX = GAMESCREENLEFT + GAMESCREENWIDTH / 2;
			_enemyY = GAMESCREENTOP;
		}
		else {
			_enemyX = getEnemy()->getX();
			_enemyY = getEnemy()->getY();
		}
		setAngle(calcAngle(_enemyX, _enemyY));
	}
	else{
		transHoming();
	}

	setX(getX() + cosf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
	setY(getY() + -sinf(getAngle()) * getSpeed()* TIMEMANAGER->getElapsedTime());

	if (isWindowCollision()) {
		setIsFire(false);
	}
}
void playerHomingCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth() / 2, getY() - getHeight() / 2, getX() + getWidth() / 2, getY() + getHeight() / 2);
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