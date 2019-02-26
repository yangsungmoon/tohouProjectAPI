#pragma once
#include "enemyCard.h"

class enemyNormalCard :public enemyCard
{
public:
	enemyNormalCard();
	~enemyNormalCard();

	void render();
};

class enemyHomingCard : public enemyCard
{
	enemyHomingCard();
	~enemyHomingCard();

	void update();
	void render();
};