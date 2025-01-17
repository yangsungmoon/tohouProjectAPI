#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"

player::player() :_width(10), _height(10)
{
}

player::player(int width, int height) : _width(width), _height(height)
{
}

player::~player()
{
}

HRESULT player::init(int x, int y)
{
	_maxHp = 100;
	setHp(100);

	_x = x;
	_y = y;

	_attackType = ATTATK1;
	_speed = 500;
	_damage = 1;
	_state = INVINCIBILITY;

	_invincibilityTime = 2;
	_hit = false;
	_score = 0;

	IMAGEMANAGER->addImage("Player", ".//images/ss.bmp", 27, 38, true, true, RGB(255, 0, 255));

	return S_OK;
}
void player::update()
{
	playerInvincibilityTime();
	playerMove();
	cardUpdate();

	if (hpCheck()){
		_state = DEAD;
	}
}
void player::render()
{
	playerRender();
	cardRender();
}
void player::release()
{

}

void player::playerInvincibilityTime() {
	if(_state == INVINCIBILITY){
		_invincibilityTime -= TIMEMANAGER->getElapsedTime();
		if (_invincibilityTime < 0) {
			_invincibilityTime = 2;
			_state = PLAY;
		}
	}
}

void player::playerMove()
{
	int width = IMAGEMANAGER->findImage("Player")->getWidth();
	int height = IMAGEMANAGER->findImage("Player")->getHeight();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_x > GAMESCREENLEFT + width / 2) {
			_x -= _speed * TIMEMANAGER->getElapsedTime();
		}
		else {
			setX(GAMESCREENLEFT + width / 2);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_x < GAMESCREENRIGHT - width / 2) {
			_x += _speed * TIMEMANAGER->getElapsedTime();
		}
		else {
			setX(GAMESCREENRIGHT - width / 2);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_y > GAMESCREENTOP + height / 2) {
			_y -= _speed * TIMEMANAGER->getElapsedTime();
		}
		else {
			setY(GAMESCREENTOP + height / 2);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_y < GAMESCREENBOTTOM - height / 2) {
			_y += _speed * TIMEMANAGER->getElapsedTime();
		}
		else {
			setY(GAMESCREENBOTTOM - height / 2);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE)) {
		playerFire();
	}
	if (KEYMANAGER->isStayKeyDown(VK_SHIFT)) {
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL)) {
		// 임시 데미지 추가
		_damage+=10;
		if (_damage >= 40)
		{
			setAttackType(ATTATK5);
		}
		else if (_damage >= 30)
		{
			setAttackType(ATTATK4);
		}
		else if (_damage >= 20)
		{
			setAttackType(ATTATK3);
		}
		else if (_damage >= 10)
		{
			setAttackType(ATTATK2);
		}
	}

}

void player::playerFire()
{
	float angle = 3.14 / 72;
	float speed = 1000.0f;
	playerCard* _playerCard;
	enemy* enemyTarget = NULL;

	for (int i = 0; i < _em->getvEnemy().size(); i++) {
		enemyTarget = _em->getvEnemy().at(i);
		break;
	}
	switch (getAttackType()) {
	case ATTATK1:
	{
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * 36, 10);
		_vPlayerCard.push_back(_playerCard);
	}
	break;
	case ATTATK2:
	{
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * 36, 10);
		_vPlayerCard.push_back(_playerCard);

		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
	}
	break;
	case ATTATK3:
	{
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 1), 10);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 1), 10);
		_vPlayerCard.push_back(_playerCard);

		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
	}
	break;
	case ATTATK4:
	{
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 2), 10);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36), 10);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 2), 10);
		_vPlayerCard.push_back(_playerCard);

		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
	}
	break;
	case ATTATK5:
	{
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 2), 10);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36), 10);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerNormalCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 2), 10);
		_vPlayerCard.push_back(_playerCard);

		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 10), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);

		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 + 20), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
		_playerCard = new playerHomingCard();
		_playerCard->init(getX(), getY(), speed, angle * (36 - 20), 10);
		_playerCard->setHomingInit(enemyTarget);
		_vPlayerCard.push_back(_playerCard);
	}
	break;
	}
}

void player::playerRender()
{
	if(_state != DEAD){
		int width = IMAGEMANAGER->findImage("Player")->getWidth();
		int height = IMAGEMANAGER->findImage("Player")->getHeight();

		IMAGEMANAGER->findImage("Player")->centerRender(getMemDC(), _x, _y, width, height);
		//Rectangle(getMemDC(), _x- width / 2, _y - height /2, _x + width /2, _y + height /2);
	}
}

void player::cardUpdate()
{
	for (int i = 0; i < _vPlayerCard.size(); i++)
	{
		_vPlayerCard[i]->update();
		if (!_vPlayerCard[i]->getIsFire())
		{
			_vPlayerCard.erase(_vPlayerCard.begin()+i);
		}
	}

	cardCollision();
}

void player::cardRender() 
{
	for (auto _viPlayerCard = _vPlayerCard.begin(); _viPlayerCard != _vPlayerCard.end(); ++_viPlayerCard)
	{
		(*_viPlayerCard)->render();
	}
}

RECT player::getRect()
{
	int shotRange = 2;

	RECT rc = {
		getX() - shotRange,
		getY() - shotRange,
		getX() + shotRange,
		getY() + shotRange
	};

	return rc;
}

void player::hpHit(int damage) {
	setHp(getHp() - damage);
}

bool player::hpCheck() {
	if (_hit) {
		_hit = false;
		_hp -= 10;
		if (_hp <= 0) {
			return true;
		}
	}
	
	return false;
}

void player::cardCollision() 
{
	vector<enemy*> _tempEnemy = _em->getvEnemy();
	for (int i = 0; i < _vPlayerCard.size(); i++)
	{
		if (_vPlayerCard[i]->getIsFire())
		{
			for (int j = 0; j < _tempEnemy.size(); j++)
			{
				if (_vPlayerCard[i]->isObjectCollision(_tempEnemy[j]->getRect()))
				{
					_vPlayerCard[i]->setIsFire(false);
					_tempEnemy[j]->setHit(true);
					break;
				}
			}
		}
	}
}