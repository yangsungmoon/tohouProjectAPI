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

	HRESULT init(void);		//�ʱ�ȭ �Լ�
	void release(void);		//�޸� ���� ����
	void update(void);		//������Ʈ(����)
	void render(void);		//�׷��ִ� �Լ�
};

