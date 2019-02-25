#include "stdafx.h"
#include "PlayScene.h"



PlayScene::PlayScene()
{
}


PlayScene::~PlayScene()
{
}

HRESULT PlayScene::init(void)
{
	_bg = new backGround();
	_bg->init(0.5);

	_player = new player();
	_player->init(GAMESCREENLEFT + GAMESCREENWIDTH / 2, GAMESCREENBOTTOM);

	_em = new enemyManager();
	_em->init();

	_player->setEnemyManagerAdresslink(_em);
	_em->setMyUnitAdressLink(_player);

	return S_OK;
}
void	PlayScene::release(void)
{

}
void	PlayScene::update(void)
{
	_bg->update();
	_player->update();
	_em->update();

	if (KEYMANAGER->isOnceKeyDown(VK_END))
	{
		SCENEMANAGER->changeScene("엔딩");
	}
}
void	PlayScene::render(void)
{
	_bg->render();
	_player->render();
	_em->render();

	char str[256];
	sprintf_s(str, "페이즈 카운터 : %f", (float)_em->getPhaseCount());
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));

}
