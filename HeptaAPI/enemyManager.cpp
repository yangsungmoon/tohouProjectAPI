#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

void enemyManager::init() 
{
	phaseInit();	
}
void enemyManager::update()
{
	phaseUpdate();
	enemyUpdate();
	enemyCardUpdate();
}
void enemyManager::render() 
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) {
		(*_viEnemy)->render();
	}

	for (_viEnemyCard = _vEnemyCard.begin(); _viEnemyCard != _vEnemyCard.end(); ++_viEnemyCard) {
		(*_viEnemyCard)->render();
	}
}
void enemyManager::release() {

}

void enemyManager::phaseInit()
{
	for (int i = 0; i < 100; i++) {
		_phaseSwi[i] = false;
	}

	_phaseTime = 3;
	_phaseCount = 0;
}

void enemyManager::enemyAttack() {
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) {
		if ((*_viEnemy)->getState() == 1) {
			enemyCard* _card = (*_viEnemy)->enemyAttack(_player->getX(), _player->getY());
			if (_card != NULL) {
				_vEnemyCard.push_back(_card);
			}
		}
	}
}

void enemyManager::enemyCreate()
{
	enemy* _enemy;
	switch (_phaseCount) {
	case 1:
	{
		if (_phaseSwi[_phaseCount] == false) {
			_enemy = new enemyAngel1();
			_enemy->init(80, 12, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(120, 6, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(160, 0, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);

			_phaseSwi[_phaseCount] = true;
		}
	}
	break;
	case 2:
	{
		if (_phaseSwi[_phaseCount] == false) {
			_enemy = new enemyAngel1();
			_enemy->init(380, 12, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(340, 6, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(300, 0, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);

			_phaseSwi[_phaseCount] == true;
		}
	}
	break;
	case 3:
	{
		if (_phaseSwi[_phaseCount] == false) {
			_enemy = new enemyAngel1();
			_enemy->init(180, 12, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(210, 6, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(240, 0, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(270, 0, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(300, 6, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);
			_enemy = new enemyAngel1();
			_enemy->init(330, 12, 10, 10, 10, 50);
			_vEnemy.push_back(_enemy);

			_phaseSwi[_phaseCount] == true;
		}
	}
	break;
	case 4:
	{
		if (_phaseSwi[_phaseCount] == false) {

			_phaseSwi[_phaseCount] == true;
		}
	}
	break;

	}
}

void enemyManager::phaseUpdate()
{
	_phaseTime -= TIMEMANAGER->getElapsedTime();
	if (_phaseTime < 0) {
		_phaseTime = 3;
		_phaseCount++;
		enemyCreate();
	}
}
void enemyManager::enemyUpdate()
{
	for (int i = 0; i < _vEnemy.size(); i++) {
		_vEnemy[i]->update(_player->getX(), _player->getY());
		if (_vEnemy[i]->getState() == 3) {
			_vEnemy.erase(_vEnemy.begin() + i);
		}
	}
	enemyAttack();
}
void enemyManager::enemyCardUpdate()
{
	for (int i = 0; i < _vEnemyCard.size(); i++) {
		_vEnemyCard[i]->update();
		if(_player->getState() == 1){
			if (_vEnemyCard[i]->isObjectCollision(_player->getRect())) {
				_vEnemyCard[i]->setIsFire(false);
				_player->setHit(true);
			}
		}

		if (!_vEnemyCard[i]->getIsFire()) {
			_vEnemyCard.erase(_vEnemyCard.begin() + i);
		}
	}

	
}
