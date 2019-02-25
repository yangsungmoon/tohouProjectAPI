#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

void enemyManager::init() {
	// 페이즈 초기화
	for (int i = 0; i < 100; i++) {
		_phaseSwi[i] = false;
	}

	_phaseTime = 3;
	_phaseCount = 0;
	// 적 총알 초기화
	/*while (true) {
		bullet* EnemyBullet = new enemyBullet();
		if (EnemyBullet->getBulletMax() <= _vEnemyBullet.size()) break;
		EnemyBullet->init(WINSIZEX, WINSIZEY, 5, 10);
		_vEnemyBullet.push_back(EnemyBullet);
	}*/
}
void enemyManager::update() {
	phaseUpdate();
	enemyUpdate();
	
}
void enemyManager::render() {
	////몹
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) {
		(*_viEnemy)->render();
	}

	////적 총알
	//for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end(); ++_viEnemyBullet) {
	//	(*_viEnemyBullet)->render();
	//}
}
void enemyManager::release() {

}

void enemyManager::EnemyAttack() {
	//// 보스 페이즈
	//if (getFrmCount() % 30 == 0 && getFrmCount() > 0) {
	//	if (phase_swi[4]) {
	//		for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) {
	//			for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end(); ++_viEnemyBullet) {
	//			}
	//		}
	//	}
	//}

	//// 중 보스 페이즈
	//if (getFrmCount() % 50 == 0 && getFrmCount() > 0) {
	//	if (phase_swi[3]) {
	//		for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) {
	//			for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end(); ++_viEnemyBullet) {
	//			}
	//		}
	//	}
	//}
	//if (getFrmCount() % 70 == 0 && getFrmCount() > 0) {
	//	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) {
	//		for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end(); ++_viEnemyBullet) {
	//			if (!(*_viEnemyBullet)->getIsFire()) {
	//				(*_viEnemyBullet)->setX((*_viEnemy)->getcX());
	//				(*_viEnemyBullet)->setY((*_viEnemy)->getY() + (*_viEnemy)->getSizeY());
	//				(*_viEnemyBullet)->AngleAutoSet(_myUnit->getcX(), _myUnit->getcY());
	//				(*_viEnemyBullet)->setIsFire(true);
	//				break;
	//			}
	//		}
	//	}
	//}
}

void enemyManager::EnemyBulletFireAndCollision() {
	//적 총알
	//for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end(); ++_viEnemyBullet) {
	//	if (!(*_viEnemyBullet)->getIsFire()) continue;

	//	(*_viEnemyBullet)->update();
	//	if (!(*_viEnemyBullet)->getIsFire()) continue;

	//	//_myUnit
	//	if ((*_viEnemyBullet)->collision(_myUnit->getRect())) {
	//		(*_viEnemyBullet)->reset();
	//		_myUnit->hpHit((*_viEnemyBullet)->getDamage());
	//		if (_myUnit->hpCheck()) {
	//			// 게임 오버
	//		}
	//	}
	//}
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
}
