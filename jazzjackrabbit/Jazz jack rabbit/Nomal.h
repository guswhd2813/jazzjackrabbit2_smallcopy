#pragma once
#include "bullet.h"

class CBitBmp;
class CNomal :
	public CBullet
{
private:
	CObj* m_pPlayer;
	DWORD	m_dwTime;

public:
	void SetPlayer(CObj* _pPlayer);
	void SetDir(int _iDIr);

public:
	virtual void Initialize(void);
	virtual void Render(HDC hdc);	
	virtual int Progress(void);		
	virtual void Release(void);

public:
	CNomal(void);
	~CNomal(void);
};
