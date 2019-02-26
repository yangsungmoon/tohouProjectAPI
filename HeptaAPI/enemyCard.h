#pragma once
#include "card.h"

class enemyCard :public card
{
private:
	
public:
	enemyCard();
	~enemyCard();

	virtual void update();
	virtual void render();
	void setPlayerPosition(float x, float y);
};
