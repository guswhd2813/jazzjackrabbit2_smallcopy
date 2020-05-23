#pragma once
#include "obj.h"

class CItem :
	public CObj
{
private:
	
public:
	void Initialize(void);
	int	 Progress(void);
	void Render(HDC hdc);
	void Release(void);
	
	void SetType(int _Type);

public:
	CItem(void);
	~CItem(void);
};
