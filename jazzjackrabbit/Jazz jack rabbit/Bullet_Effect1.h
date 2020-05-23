#pragma once
#include "effect.h"
#include "include.h"

class CBitBmp;
class CBullet_Effect1 :
	public CObj
{
private:
	map<string,CBitBmp*>	m_BitMap;
	int m_iType;
	DWORD m_dwTime;
	DWORD m_dwTime5;
	DWORD	m_dwState;
	FRAME	m_tFrame;
	DWORD	m_dwKey;

public:
	void SetType(int _type);
	DWORD	GetTime();

private:
	void SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime);

public:
	CBullet_Effect1(void);
	~CBullet_Effect1(void);
public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);
};
