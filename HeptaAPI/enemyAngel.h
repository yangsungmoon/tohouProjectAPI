#pragma once
#include "enemy.h"
class enemyAngel1 :
	public enemy
{
public:
	enemyAngel1();
	~enemyAngel1();

	void render();

	void enemyMove();
	enemyCard* enemyAttack(float x, float y);
};

class enemyAngel2 :
	public enemy
{
public:
	enemyAngel2();
	~enemyAngel2();

	void render();

	void enemyMove();
	enemyCard* enemyAttack();
};

