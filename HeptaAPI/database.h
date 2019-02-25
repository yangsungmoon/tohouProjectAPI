#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class pokemon;
//class player;

struct DBstatus
{
public:
	string name;
	int element;
	int hp;
	int atk;
	int def;
	int specialATK;
	int specialDEF;

	DBstatus() {};
	~DBstatus() {};
};

struct DBskills
{
public:
	string name;
	int skillElement;
	int power;
	int pp;

	DBskills() {};
	~DBskills() {};
};

//���� �̱��� DB �����д�
class database : public singletonBase <database>
{
private:
	//���ʹ� ���ϸ��� ���� �޾ƿ������ؼ� �Ǵ� �ٸ� ���𰡸� ���ؼ�����
	typedef vector<pokemon*> vPokemon;
	typedef vector<pokemon*>::iterator viPokemon;

	//�ؽ�Ʈ�����͸� �ֱ����� ����
	typedef vector<string> arrFind;	
	typedef vector<string>::iterator iterFind;

	//�������ͽ��� ���� ��
	typedef map<string, DBstatus*> arrStatus;
	typedef map<string, DBstatus*>::iterator iterStatus;

	arrStatus _mTotalStatus;
	vPokemon* _vEnemyPokemon;
	map<string, DBskills*> _mTotalSkill;

	//player* _playerMemory;

public:
	database();
	~database();

	void loadDatabasePokemon(string name);	//���ϸ� �������ͽ��� �ҷ�����
	void loadDatabaseSkill(string name);	//���ϸ� ��ų�����͸� �ҷ�����

	DBstatus* getStatusData(string str) { return _mTotalStatus.find(str)->second; }
	DBskills* getSkillsData(string str) { return _mTotalSkill.find(str)->second; }

	//inline vPokemon* getVEnemyPokemon() { return _vEnemyPokemon; }
	//inline void setVEnemyPokemon(vPokemon* poke) { _vEnemyPokemon = poke; }

	//inline void setPlayerMemory(player* player) { _playerMemory = player; }
	//inline player* getPlayerMemory() { return _playerMemory; }

	HRESULT init();
	void update();
	void release();
};

