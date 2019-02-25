#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class effect;

class effectManager : public singletonBase<effectManager>
{
private:
	//����
	typedef vector<effect*>						arrEffects;
	typedef vector<effect*>::iterator			iterEffects;
	//����
	typedef map<string, arrEffects>				arrEffect;
	typedef map<string, arrEffects>::iterator	iterEffect;
	//����
	typedef vector<map<string, arrEffects>>				arrTotalEffect;
	typedef vector<map<string, arrEffects>>::iterator	iterTotalEffect;

private:
	arrTotalEffect _vTotalEffect;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void addEffect(string effectName, const char* imageName, int imageWidth, int imageHeight, int effectWidth, int effectHeight, float fps, float elapsedTime, int buffer);

	void play(string effectName, int x, int y);


	effectManager();
	~effectManager();

	bool isEffectEnd(string effectName);
};

