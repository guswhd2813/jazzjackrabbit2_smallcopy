#pragma once
#include "obj.h"

class CMonster :
	public CObj
{
protected:
	float fPrefX;
	bool bDir;
	bool bSt;
public:
	CMonster(void);
	~CMonster(void);


};
