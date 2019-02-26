#pragma once
#include "playerCard.h"

class playerNormalCard :
	public playerCard
{
public:
	playerNormalCard();
	~playerNormalCard();

	void render();
};

