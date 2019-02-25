#include "stdafx.h"
#include "enemyAngel.h"


enemyAngel1::enemyAngel1()
{
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
void enemyAngel1::enemyFire()
{

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
void enemyAngel2::enemyFire()
{

}
