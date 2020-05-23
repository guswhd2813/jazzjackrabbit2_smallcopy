#pragma once
#include "bullet.h"

class CBitBmp;
class CMulti :
	public CBullet
{
	private:
	CObj* m_pPlayer;
	bool bUp;
	bool bLR;

public:
	void SetPlayer(CObj* _pPlayer);
	void SetDir(int _iDIr);

public:
	virtual void Initialize(void);
	virtual void Render(HDC hdc);	
	virtual int Progress(void);		
	virtual void Release(void);
public:
	CMulti(void);
	~CMulti(void);
};
