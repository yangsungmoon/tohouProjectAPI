#include "stdafx.h"
#include "playerCard.h"

playerCard::playerCard()
{
}
playerCard::~playerCard()
{
}

void playerCard::update()
{
	float tempX = getX();
	float tempY = getY();

	setX(getX() + cosf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());
	setY(getY() + -sinf(getAngle()) * getSpeed() * TIMEMANAGER->getElapsedTime());

	RECT rc = { tempX, tempY, getX(), getY() };

	if (isWindowCollision()) {
		setIsFire(false);
	}
}
void playerCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth() / 2, getY() - getHeight() / 2, getX() + getWidth() / 2, getY() + getHeight() / 2);
}

