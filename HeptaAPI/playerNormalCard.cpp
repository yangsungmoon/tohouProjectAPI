#include "stdafx.h"
#include "playerNormalCard.h"



playerNormalCard::playerNormalCard()
{
}


playerNormalCard::~playerNormalCard()
{
}

void playerNormalCard::update()
{
	float tempX = getX();
	float tempY = getY();

	setX(getX() + cosf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
	setY(getY() + -sinf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());

	RECT rc = { tempX, tempY, getX(), getY() };

	if (isCollision()) {
		setIsFire(false);
	}
}
void playerNormalCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth()/ 2, getY()- getHeight()/ 2, getX()+ getWidth()/ 2, getY()+ getHeight()/ 2);
}