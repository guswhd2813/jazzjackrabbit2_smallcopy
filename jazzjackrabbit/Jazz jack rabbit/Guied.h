#pragma once
#include "bullet.h"

class CGuied :
	public CBullet
{
	
private:
	
		float fGuidedX;
	float fGuidedY;
	CObj* m_pPlayer;
	CObj* m_pMonster;

public:
	void SetPlayer(CObj* _pPlayer);
	void SetMonster(CObj* _pMonster);
	void SetDir(int _iDIr);
	void SetType(int _Type);
	void SetXY(float _x,float _y);

public:
	virtual void Initialize(void);
	virtual void Render(HDC hdc);	
	virtual int Progress(void);		
	virtual void Release(void);
public:
	CGuied(void);
	~CGuied(void);
};
