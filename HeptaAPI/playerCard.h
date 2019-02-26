#pragma once
#include "card.h"
#include "enemy.h"

class playerCard :public card
{
private:
	enemy* _enemy;
public:
	playerCard();
	~playerCard();

	virtual void update();
	virtual void render();

	void setHomingInit(enemy* enemy) { _enemy = enemy; };
	enemy* getEnemy() { return _enemy; }
};
