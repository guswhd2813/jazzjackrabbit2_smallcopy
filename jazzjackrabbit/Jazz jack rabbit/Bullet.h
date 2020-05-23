#pragma once

#include "obj.h"


class CBitBmp;
class CBullet
	:public CObj
{

protected:
	map<string,CBitBmp*>	m_BitMap;

	float m_fBulletSpd;
	float m_fSpeed;

	int iDir;
	bool bDir;

	
	list<CObj*>* m_pEffect;



	float fDix;
	float fDiY;


public:
	void CreateEffect1(void);
	

	void SetEffect(list<CObj*>* _pEffect);
	
public:
	virtual void Initialize(void) PURE;
	virtual void Render(HDC hdc)  PURE;	
	virtual int Progress(void)   PURE;		
	virtual void Release(void)	  PURE;

public:
	CBullet(void);
	~CBullet(void);
};
