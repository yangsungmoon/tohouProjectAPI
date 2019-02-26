#pragma once
#include "playerCard.h"

class playerHomingCard :
	public playerCard
{
private:
	float _enemyX;
	float _enemyY;

	bool _homingSwi;
	float _homingCounter;

public:
	playerHomingCard();
	~playerHomingCard();

	void update();
	void render();

	void transHoming();
};

