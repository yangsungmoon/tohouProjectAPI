#pragma once
#include "gameNode.h"
#include <functional>

//�ݹ��Լ� == �Լ�������
using CALLBACK_FUNCTION = std::function<void()>;
using CALLBACK_FUNCTION_INT = std::function<void(int)>;

//���θ� �ϸ� �� ������ �ִ�
//<Functional> �̶�� ���̺귯���� �ִµ�
//���⿡ std::Function, std::move, std::bind ���
//�ݹ��Լ��� ���� �������� ������ static �����̹Ƿ�
//�Ű������� ����� �� ���� �����̴�.
//������ Functional ���̺귯���� �̿��Ѵٸ� �Ϲ� �Ű�������
//�ݹ��Լ��� �־ ����� �� �ִ�.
//����, �缱, ȣ��, ����, ����


//����) �ǿܷ� ����
//����2) �ǿܷ� ��ޱ⵵ ���� 


//��ư ���¿� ���� ����
enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,		//�ʱ�ȭ ����
	BUTTONDIRECTION_UP,			//��ư�� �ö�� ��
	BUTTONDIRECTION_DOWN		//��ư�� ������ ��
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;
	float _x, _y;

	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	CALLBACK_FUNCTION _callbackFunction;
	CALLBACK_FUNCTION_INT _callbackFunction_int;

public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION_INT cbFunction);

	void release(void);
	void update(void);
	void update(int num);
	void render(void);

	inline void setDirection(BUTTONDIRECTION dir) { _direction = dir; }
	inline BUTTONDIRECTION getDirection() { return _direction; }
	inline void setPosition(POINT pos)
	{
		_x = pos.x;
		_y = pos.y;
		_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	}
};

