#pragma once
#include "singletonBase.h"
#include <vector>

// ������ ���
enum DESTROY_MODE
{
	DESTROY_CIRCLE,		// ���� �ձ۰� ����
	DESTROY_RECTANGLE,	// ���� �׸𳪰� ����
	DESTROY_NAPALM,		// ������ ó��
	DESTROY_END
};

class groundDestroyManager : public singletonBase<groundDestroyManager>
{
public:
	groundDestroyManager();
	~groundDestroyManager();

			// �׷��� dc, �ı��� �� �Ų��� �÷�, ���� ��ġ, ������ ����, ������ ũ��, ������ Ƚ��, �پ�� ����, ������ ���
	void destroy(HDC hdc, COLORREF color, POINT point, float angle, float radius, int num, float ratio, DESTROY_MODE mode);
			// �׷��� dc, �ı��� �� �Ų��� �÷�, ���� ��ġ�� ���� ����
	void napalm(HDC hdc, COLORREF color, vector<POINT> point);
};

