#include "stdafx.h"
#include "enemyCardType.h"

enemyNormalCard::enemyNormalCard()
{
}
enemyNormalCard::~enemyNormalCard()
{
}

void enemyNormalCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth() / 2, getY() - getHeight() / 2, getX() + getWidth() / 2, getY() + getHeight() / 2);
}

// À¯µµÅº
enemyHomingCard::enemyHomingCard()
{
}
enemyHomingCard::~enemyHomingCard()
{
}

void enemyHomingCard::update()
{
	update();
}
void enemyHomingCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth() / 2, getY() - getHeight() / 2, getX() + getWidth() / 2, getY() + getHeight() / 2);
}