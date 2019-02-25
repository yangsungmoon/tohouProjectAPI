// stdafx.h : �̸� �����ϵ� ������� : ���� ����ϴ� �͵��� �̸� ������ �δ� ��
#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <io.h>

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "soundManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "iniDataManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "utils.h"
#include "collision.h"
#include "txtData.h"
#include "database.h"

// ��ü����
#include "groundDestroyManager.h"
#include "cameraManager.h"
#include "dialogue.h"


using namespace std;
using namespace HEPTA_UTIL;

//=======================================================
// ## ������ ���� ������ ## 2017.11.08 ##
//=======================================================

#define WINNAME		(LPTSTR)TEXT("Hepta Window API")
#define WINSTARTX	50		//������ ������ǥ X
#define WINSTARTY	50		//������ ������ǥ Y
#define WINSIZEX	640		//������ ����ũ��
#define WINSIZEY	480		//������ ����ũ��
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

// �÷��� ��ǥ
#define GAMESCREENLEFT		32
#define GAMESCREENTOP		16
#define GAMESCREENRIGHT		416
#define GAMESCREENBOTTOM	464
#define GAMESCREENWIDTH		384	
#define GAMESCREENHEIGHT	448

#define KEYMANAGER		keyManager::getSingleton()
#define RND				randomFunction::getSingleton()
#define IMAGEMANAGER	imageManager::getSingleton()
#define SOUNDMANAGER	soundManager::getSingleton()
#define TIMEMANAGER		timeManager::getSingleton()
#define EFFECTMANAGER	effectManager::getSingleton()
#define SCENEMANAGER	sceneManager::getSingleton()
#define KEYANIMANAGER	keyAniManager::getSingleton()
#define TXTDATA			txtData::getSingleton()
#define INIDATA			iniDataManager::getSingleton()
#define DATABASE		database::getSingleton()

// ��ü����
#define DESTROY			groundDestroyManager::getSingleton()
#define CAMERAMANAGER	cameraManager::getSingleton()
#define DIALOGUE		dialogue::getSingleton()


#define BLACK		RGB(0, 0, 0)
#define RED			RGB(255, 0, 0)
#define GREEN		RGB(0, 255, 0)
#define BLUE 		RGB(0, 0, 255)
#define MAGENTA		RGB(255, 0, 255)
#define CYAN		RGB(0, 255, 255)
#define YELLOW		RGB(255, 255, 0)
#define WHITE		RGB(255, 255, 255)

#define PLAYER_SELECT_KEY	'X'
#define PLAYER_CANCLE_KEY	'C'

//=======================================================
// ## ��ũ�� ## 2017.11.15 ##
//=======================================================

#define SAFE_DELETE(p) { if(p) {delete(p); (p) = NULL; }}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL; }}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

//=======================================================
// ## ������ ���� extern ## 2017.11.08 ##
//=======================================================

extern HINSTANCE	_hInstance;		//�ν��Ͻ� �ڵ�
extern HWND			_hWnd;			//�ڵ�
extern POINT		_ptMouse;

extern bool _isDebug;