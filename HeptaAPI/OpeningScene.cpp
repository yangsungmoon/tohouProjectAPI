#include "stdafx.h"
#include "OpeningScene.h"



OpeningScene::OpeningScene()
{
}


OpeningScene::~OpeningScene()
{
}



HRESULT OpeningScene::init(void)
{

	_count = 5.5;
	return S_OK;
}
void	OpeningScene::release(void)
{

}
void	OpeningScene::update(void)
{

	_count += TIMEMANAGER->getElapsedTime();
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->changeScene("����");
	}

	//�˾��� ��������
}

void	OpeningScene::render(void)
{
	char str[256] = "�� ���Ҹ���";
	sprintf_s(str, "%f", _count);

	TextOut(getMemDC(), WINSIZEX/2, WINSIZEY/2, str, strlen(str));
}
