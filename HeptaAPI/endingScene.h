#pragma once
#include "gameNode.h"
class EndingScene : public gameNode
{
public:
	EndingScene();
	~EndingScene();


	HRESULT init(void);		//�ʱ�ȭ �Լ�
	void release(void);		//�޸� ���� ����
	void update(void);		//������Ʈ(����)
	void render(void);		//�׷��ִ� �Լ�


};
