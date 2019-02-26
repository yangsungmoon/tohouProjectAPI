#include "stdafx.h"
#include "enemyCard.h"

enemyCard::enemyCard()
{
}
enemyCard::~enemyCard()
{
}

void enemyCard::update()
{
	float tempX = getX();
	float tempY = getY();

	setX(getX() + cosf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
	setY(getY() + sinf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());

	RECT rc = { tempX, tempY, getX(), getY() };

	if (isWindowCollision()) {
		setIsFire(false);
	}
}
void enemyCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth() / 2, getY() - getHeight() / 2, getX() + getWidth() / 2, getY() + getHeight() / 2);
}

void enemyCard::setPlayerPosition(float x, float y)
{
	setAngle(calcAngle(x, y));
}