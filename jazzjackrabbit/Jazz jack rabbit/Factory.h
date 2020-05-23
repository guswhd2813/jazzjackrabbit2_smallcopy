#pragma once

#include "Obj.h"

template<typename T>
class CFactory
{
public:
	static CObj*	CreateObj(void)
	{
		CObj*		pObj = new T;

		pObj->Initialize();

		return pObj;
	}

	static CObj*	CreateObj(float _fX, float _fY)
	{
		CObj*		pObj = new T;

		
		pObj->SetPos(_fX, _fY);
		pObj->Initialize();

		return pObj;
	}

	static CObj*	CreateObj(float _fX,float _fY,DIRECTION _eDir)
	{
		CObj* pObj = new T;

		pObj->Initialize();
		pObj->SetPos(_fX,_fY);
		pObj->SetDirection(_eDir);

		return pObj;


	}

	static CObj*	CreateObj(float _fX,float _fY,int _iBox)//ÅÛ¹Ú½º
	{
		CObj* pObj = new T;

		pObj->Initialize();
		pObj->SetPos(_fX,_fY);
		pObj->SetBox(_iBox);

		return pObj;


	}

	static CObj*  SetScore(int _iPoint)
	{
		CObj* pObj = new T;

		pObj->Initialize();
		pObj->SetScore(_iPoint);

		return pObj;

	}
public:
	CFactory(void){	}
	~CFactory(void){}
};
