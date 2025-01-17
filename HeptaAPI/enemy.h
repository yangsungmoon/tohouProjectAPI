#pragma once
#include "gameNode.h"
#include "enemyCardType.h"

class enemy :
	public gameNode
{
private:
	const int _width;
	const int _height;

	int _maxHp;
	int _hp;

	float _x;
	float _y;

	float _speed;
	float _damage;
	float _angle;

	float _attackTime;

	enum AttackType { ATTATK1 = 1, ATTATK2 = 2, ATTATK3 = 3, ATTATK4 = 4, ATTATK5 = 5 };
	AttackType _attackType;

	enum State { PLAY = 1, INVINCIBILITY = 2, DEAD = 3 };
	State _state;

	float x;
	float _my_x;
	float _my_y;

	bool _hit;
public:
	enemy();
	enemy(int, int);
	~enemy();

	void init(float x, float y, int hp, float sizeX, float sizeY, float speed);
	void update(float, float);
	virtual void render();
	void release();

	int getWidth() { return _width; }
	int getHeight() { return _height; }

	int getMaxHp() { return _maxHp; }
	void setHp(int hp) { _hp = hp; }
	int getHp() { return _hp; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }

	void setSpeed(float speed) { _speed = speed; }
	float getSpeed() { return _speed; }
	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }

	void setAttackTime(float attackTime) { _attackTime = attackTime; }
	float getAttackTime() { return _attackTime; }

	void setAttackType(AttackType type) { _attackType = type; }
	AttackType getAttackType() { return _attackType; }

	void setState(State type) { _state = type; }
	State getState() { return _state; }

	void setDamage(int damage) { _damage = damage; }
	int getDamage() { return _damage; }

	void setHit(bool hit) { _hit = hit; }
	bool getHit() { return _hit; }

	virtual void enemyMove() {};
	virtual enemyCard* enemyAttack(float x, float y) { return NULL; };

	RECT getRect();

	bool hpCheck();
	bool isCollision();
};

