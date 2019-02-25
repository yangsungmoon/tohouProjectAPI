#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{

}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("������",new OpeningScene);
	SCENEMANAGER->addScene("����",new PlayScene);
	SCENEMANAGER->addScene("����",new EndingScene);
	
	SCENEMANAGER->init("������");
	SCENEMANAGER->init("����");
	SCENEMANAGER->init("����");

	SCENEMANAGER->changeScene("������");
	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();
}

//����
void playGround::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();

	
}

//�׸��°�.......
void playGround::render(void)
{
	//������ PeekMessage ����
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	SCENEMANAGER->render();
	

	TIMEMANAGER->render(getMemDC());
	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
