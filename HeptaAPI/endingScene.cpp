#include "stdafx.h"
#include "EndingScene.h"



EndingScene::EndingScene()
{
}


EndingScene::~EndingScene()
{

}

HRESULT EndingScene::init(void)		
{

	return S_OK;
}
void	EndingScene::release(void)	
{

}
void	EndingScene::update(void)	
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->changeScene("������");
	}
}
void	EndingScene::render(void)	
{

	char str[256] = "���� ���� �߼��� ����";

	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));


}