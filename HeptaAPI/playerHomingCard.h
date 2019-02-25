#pragma once
#include "card.h"
class playerHomingCard :
	public card
{
private:
	float _enemyX;
	float _enemyY;

	bool _homingSwi;
	float _homingCounter;

	enemy* _enemy;
public:
	playerHomingCard();
	~playerHomingCard();

	void update();
	void render();

	void setHomingInit(enemy* __enemy);
	void transHoming();
};

