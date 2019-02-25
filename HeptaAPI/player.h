#pragma once
#include "gameNode.h"
#include <vector>
#include "playerNormalCard.h"
#include "playerHomingCard.h"

class enemyManager;
class player :
	public gameNode
{
private:
	enemyManager* _em;
	
	// 케릭터 설정
	const int _width;
	const int _height;

	int _maxHp;
	int _hp;

	float _x;
	float _y;

	float _speed;
	float _damage;

	enum AttackType { ATTATK1 = 1, ATTATK2 = 2, ATTATK3 = 3, ATTATK4 = 4, ATTATK5 = 5};
	AttackType _attackType;

	enum State { PLAY = 1, INVINCIBILITY = 2, DEAD = 3 };
	State _state;

	int _score;

	vector<card*> _vPlayerCard;
public:
	player();
	player(int, int);
	~player();

	virtual HRESULT init(int, int);
	void update();
	void render();
	void release();

	int getWidth() { return _width; }
	int getHeight() { return _height; }

	int getMaxHp() { return _maxHp; }
	void setHp(int hp) { _hp = hp; }
	int getHp() { return _hp; }

	float getX() { return _x; }
	void setX(int x) { _x = x; }
	float getY() { return _y; }
	void setY(int y) { _y = y; }

	void setSpeed(float speed) { _speed = speed; }
	float getSpeed() { return _speed; }

	void setAttackType(AttackType type) { _attackType = type; }
	AttackType getAttackType() { return _attackType; }

	void setState(State type) { _state = type; }
	State getState() { return _state; }

	void setDamage(int damage) { _damage = damage; }
	int getDamage() { return _damage; }

	void addScore(int score) { _score += score; }
	int getScore() { return _score; }

	void setEnemyManagerAdresslink(enemyManager* em) { _em = em; }

	void playerMove();
	void playerFire();
	void playerRender();
	void cardUpdate();
	void cardRender();

	RECT getRect();

	void hpHit(int);
	bool hpCheck();
};

