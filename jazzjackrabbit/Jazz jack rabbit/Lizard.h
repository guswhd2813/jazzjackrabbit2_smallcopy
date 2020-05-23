#pragma once
#include "monster.h"

class CLizard :
	public CMonster
{
private:
	DWORD	m_dwState;
	DWORD	m_dwTime6;
		DWORD	m_patternTime;
	FRAME	m_tFrame1;
	void	SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime);



public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);
public:
	CLizard(void);
	~CLizard(void);
};
