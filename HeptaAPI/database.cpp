#include "stdafx.h"
#include "database.h"

database::database()
{
}


database::~database()
{

}

HRESULT database::init()
{
	

	return S_OK;
}

void database::update()
{


}
void database::release()
{
}

void database::loadDatabasePokemon(string name)
{
	arrFind vTemp;
	vTemp = TXTDATA->txtLoad(name.c_str());

	string str;
	int count = 0;

	for (int i = 0; i < vTemp.size(); ++i)
	{
		//ĭ���̸� ã������
		if (vTemp[i] == "|")
		{
			DBstatus* st = new DBstatus;	//�������ͽ��� �Ҵ��ϰ�
			str = vTemp[i + 1];			//i�� �ϳ� ������Ű�� �̸��̳���
			_mTotalStatus.insert(pair<string, DBstatus*>(vTemp[i + 1], st)); //���⼱ �� ���ϸ��̸��� Ű������ �׸���������ְ� 

			if (i != 0) count += 8;		
			continue;
		}

		iterStatus mIter = _mTotalStatus.find(str);			//���⼭ ���� ã�� ����־��ش�

		if (i == count + 1)								
		{
			mIter->second->name = vTemp[i].c_str();
		}

		else if (i == count + 2) mIter->second->hp = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->atk = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->def = atoi(vTemp[i].c_str());
		else if (i == count + 5) mIter->second->specialATK = atoi(vTemp[i].c_str());
		else if (i == count + 6) mIter->second->specialDEF = atoi(vTemp[i].c_str());
		else if (i == count + 7) mIter->second->element = atoi(vTemp[i].c_str());
	}

	vTemp.clear();
}

void database::loadDatabaseSkill(string name)
{
	arrFind vTemp;
	vTemp = TXTDATA->txtLoad(name.c_str());

	string str;
	int count = 0;

	for (int i = 0; i < vTemp.size(); ++i)
	{
		if (vTemp[i] == "|")
		{
			DBskills* sk = new DBskills;
			str = vTemp[i + 1];

			_mTotalSkill.insert(pair<string, DBskills*>(vTemp[i + 1], sk));

			if (i != 0) count += 5;
			continue;
		}

		map<string, DBskills*>::iterator mIter = _mTotalSkill.find(str);

		if (i == count + 1) mIter->second->name = vTemp[i].c_str();
		else if (i == count + 2) mIter->second->skillElement = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->power = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->pp = atoi(vTemp[i].c_str());
	}

	vTemp.clear();
}