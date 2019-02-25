#pragma once
#include "image.h"

//����۶�� �� ��Ʈ�� �̹����� �ϳ� �����صд�
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX , WINSIZEY , false);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;		//�Ŵ������� �ʱ�ȭ �� ���̳�

protected:
	string _destScene;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);	//�׷��ִ� �Լ�

	image* getBackBuffer(void) { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }


	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();

	inline void setDestScene(string dest) { _destScene = dest; }
};

