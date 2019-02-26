#include "stdafx.h"
#include "playerNormalCard.h"

playerNormalCard::playerNormalCard()
{
}

playerNormalCard::~playerNormalCard()
{
}

void playerNormalCard::render()
{
	Rectangle(getMemDC(), getX() - getWidth()/ 2, getY()- getHeight()/ 2, getX()+ getWidth()/ 2, getY()+ getHeight()/ 2);
}