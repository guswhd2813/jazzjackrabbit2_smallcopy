#pragma once
#include "obj.h"

class CBack2 :
	public CObj
{
public:
	CBack2(void);
	~CBack2(void);
public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);
};
