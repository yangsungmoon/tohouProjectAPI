#pragma once
#include "gameNode.h"
class OpeningScene : public gameNode
{

private:
	float _count;


public:
	OpeningScene();
	~OpeningScene();


	HRESULT init(void);		//�ʱ�ȭ �Լ�
	void release(void);		//�޸� ���� ����
	void update(void);		//������Ʈ(����)
	void render(void);		//�׷��ִ� �Լ�
};

