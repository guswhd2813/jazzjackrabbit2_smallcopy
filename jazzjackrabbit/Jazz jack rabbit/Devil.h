#pragma once
#include "monster.h"

class CDevil :
	public CMonster
{
private:
	DWORD	m_dwState;
	DWORD	m_dwTime6;
	FRAME	m_tFrame1;
	void	SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime);



public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);
public:
	CDevil(void);
	~CDevil(void);
};
