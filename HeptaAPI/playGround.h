#pragma once
#include "gameNode.h"
#include "OpeningScene.h"
#include "PlayScene.h"
#include "endingScene.h"


class playGround : public gameNode
{
private:
	 
public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	playGround();
	~playGround();
};

