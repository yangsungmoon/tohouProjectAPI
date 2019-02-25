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

	SCENEMANAGER->addScene("오프닝",new OpeningScene);
	SCENEMANAGER->addScene("메인",new PlayScene);
	SCENEMANAGER->addScene("엔딩",new EndingScene);
	
	SCENEMANAGER->init("오프닝");
	SCENEMANAGER->init("메인");
	SCENEMANAGER->init("엔딩");

	SCENEMANAGER->changeScene("오프닝");
	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();
}

//연산
void playGround::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();

	
}

//그리는거.......
void playGround::render(void)
{
	//오프닝 PeekMessage 방지
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================
	SCENEMANAGER->render();
	

	TIMEMANAGER->render(getMemDC());
	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
