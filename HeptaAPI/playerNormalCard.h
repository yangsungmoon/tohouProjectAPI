#pragma once
#include "card.h"
class playerNormalCard :
	public card
{
public:
	playerNormalCard();
	~playerNormalCard();

	void update();
	void render();
};

