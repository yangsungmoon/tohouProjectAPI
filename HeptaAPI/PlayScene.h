#pragma once
#include "gameNode.h"
#include "background.h"
#include "player.h"
#include "enemyManager.h"

class PlayScene :
	public gameNode
{
public:
	PlayScene();
	~PlayScene();

	backGround* _bg;
	player* _player;
	enemyManager* _em;

	HRESULT init(void);		//초기화 함수
	void release(void);		//메모리 관련 해제
	void update(void);		//업데이트(연산)
	void render(void);		//그려주는 함수
};

