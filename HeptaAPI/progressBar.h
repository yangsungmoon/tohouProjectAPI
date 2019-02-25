#pragma once
#include "gameNode.h"

//12.12�� ����� �ʰ�
//** ##const ����## **, ����, ȣ��, �缱, ����, ����, �������� ���� ���ٲ�
//����� �ʰ� 12.14�� �����ӟp ������ ���� ��.
//���� ȣ��� ������� ���� �ڱ��� ��Ĵ�� �ڵ��� �ؼ�
//���������� �ø����� �� ģ���鿡�� �������� ^^*�� �մϴ�
//�޾ƺ� �� ģ������ �������� ���ٸ� ������ �޾��ֱ� �ٶ��ϴ�

//�ϴ� ���� -> 
//������ 18������ 3��Ʈ�� �� �����ϴµ�
//1��Ʈ�� �¿�� �����δ�
//2��Ʈ�� ���Ʒ��� �����δ�
//3��Ʈ�� (������ �����ְ�������) �����δ�

//��� �̴Ͼ���� ü�¹ٰ� �޷��ִ�
//��� �̴Ͼ���� �� ������ ȭ�� ������ �Ŵ��� ������ �����´�

//���� ���� �������·δ� ü�¹ٰ� �� ó�� ������ ��ġ�� ũ�Ⱑ ������ �ȴ�
//��Ÿ���� �ϵ�ĥ������ ���� ���α׷����� Ŭ������ �����Ͽ�
//ũ�� ������ ��������� �ǰԲ� �Ѵ�

//����� ���ϵ� �ϵ�ĥ���鸸�� ������ �ִ� *^^* �����ϰ� �� ��.
class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _width;

	string _strKey;
	image* _progressBarTop;
	image* _high;
	image* _middle;
	image* _low;
	image* _progressBarBottom;

public:
	progressBar();
	~progressBar();

	HRESULT progressBar::init(string strKey, int x, int y, int width, int height);
	HRESULT init(string strKey, int x, int y, int width, int height, int currentGauge, int maxGauge);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge, int isHP);
	void setGauge(float currentGauge, float maxGauge, bool isHP);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	inline RECT getRect() { return _rcProgress; }

	inline bool isChangeDone(float currentGauge, float maxGauge)
	{
		if (currentGauge > maxGauge)
			currentGauge = maxGauge;

		float width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();

		return (_width == width);
	}
};

