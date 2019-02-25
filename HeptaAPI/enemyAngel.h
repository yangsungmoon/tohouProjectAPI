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
	void enemyFire();
};

class enemyAngel2 :
	public enemy
{
public:
	enemyAngel2();
	~enemyAngel2();

	void render();

	void enemyMove();
	void enemyFire();
};

