#include "stdafx.h"
#include "enemyAngel.h"


enemyAngel1::enemyAngel1()
{
	enemy();
	setAttackTime(1);
}
enemyAngel1::~enemyAngel1()
{
}
void enemyAngel1::render() 
{
	Ellipse(getMemDC(), getX() - (getWidth() / 2), getY() - (getHeight() / 2), getX() + (getWidth() / 2), getY() + (getHeight() / 2));
}
void enemyAngel1::enemyMove()
{
	setX(getX() + cosf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
	setY(getY() + sinf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
}
enemyCard* enemyAngel1::enemyAttack(float x, float y)
{
	setAttackTime(getAttackTime() - TIMEMANAGER->getElapsedTime());
	if (getAttackTime() <= 0) {
		setAttackTime(1);

		enemyNormalCard* _card = new enemyNormalCard();
		_card->init(getX(), getY(), 80, 3.14/2, 10);
		_card->setAngle(_card->calcAngle(x, y));
		
		return _card;
	}

	return NULL;
}

enemyAngel2::enemyAngel2()
{
}
enemyAngel2::~enemyAngel2()
{
}
void enemyAngel2::render()
{

}
void enemyAngel2::enemyMove()
{

}
enemyCard* enemyAngel2::enemyAttack()
{
	return NULL;
}
