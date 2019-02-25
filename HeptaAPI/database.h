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

//내부 싱글톤 DB 만들어둔다
class database : public singletonBase <database>
{
private:
	//에너미 포켓몬의 수를 받아오기위해서 또는 다른 무언가를 위해서ㅋㅋ
	typedef vector<pokemon*> vPokemon;
	typedef vector<pokemon*>::iterator viPokemon;

	//텍스트데이터를 넣기위한 벡터
	typedef vector<string> arrFind;	
	typedef vector<string>::iterator iterFind;

	//스테이터스를 넣을 맵
	typedef map<string, DBstatus*> arrStatus;
	typedef map<string, DBstatus*>::iterator iterStatus;

	arrStatus _mTotalStatus;
	vPokemon* _vEnemyPokemon;
	map<string, DBskills*> _mTotalSkill;

	//player* _playerMemory;

public:
	database();
	~database();

	void loadDatabasePokemon(string name);	//포켓몬 스테이터스를 불러오자
	void loadDatabaseSkill(string name);	//포켓몬 스킬데이터를 불러오자

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

