#pragma once
#include <vector>
#include "enemy.h"
#include "enemyAngel.h"

class player;
class enemyManager
{
private:
	vector<enemy*> _vEnemy;
	vector<enemy*>::iterator _viEnemy;

	vector<card*> _vEnemyCard;
	vector<card*>::iterator _viEnemyCard;
	
	bool _phaseSwi[100];

	float _phaseTime;
	int _phaseCount;

	player* _player;

public:
	enemyManager();
	~enemyManager();

	void init();
	void update();
	void render();
	void release();

	vector<enemy*> getvEnemy() { return _vEnemy; }
	vector<enemy*>::iterator getviEnemy() { return _viEnemy; }

	int getPhaseCount() { return _phaseCount; }

	void enemyCreate();
	void EnemyAttack();
	void EnemyBulletFireAndCollision();

	void setMyUnitAdressLink(player* player) { _player = player; }

	void phaseUpdate();
	void enemyUpdate();
};