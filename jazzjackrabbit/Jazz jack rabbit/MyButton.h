#pragma once
#include "obj.h"

class CMyButton :
	public CObj
{
private:
	DWORD	m_tTime;
	DWORD   m_tTime2;
	DWORD   m_dwKey;
	int     iRand;
	int     iSelect;
public:
	CMyButton(void);
	~CMyButton(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
