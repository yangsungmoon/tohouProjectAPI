#include "stdafx.h"
#include "backGround.h"


backGround::backGround()
{
}


backGround::~backGround()
{
}

HRESULT backGround::init(float speed) {
	setSpeed(speed);
	_sliceY = 0;
	
	IMAGEMANAGER->addImage("backGround", ".//images/background.bmp", WINSIZEX, WINSIZEY, true, true, RGB(255, 0, 255));

	return S_OK;
}
void	backGround::update() {
	//_sliceY += _speed;
	//if (_sliceY > (WINSIZEY)) _sliceY = 0;

}
void	backGround::render() {



	IMAGEMANAGER->findImage("backGround")->alphaRender(getMemDC(), 0, 0, 0, _sliceY, WINSIZEX, WINSIZEY, 150);
	//IMAGEMANAGER->findImage("½¿¶õÄ«±¸¶ó")->render(getMemDC(),WINSIZEX/2 -250 ,WINSIZEY/2 -200,100,250,340,300);
	//IMAGEMANAGER->findImage("½¿¶õÄ«±¸¶ó")->render(getMemDC(), 0, 0, 0, _sliceY, WINSIZEX, WINSIZEY);
}
void	backGround::release() {

}
