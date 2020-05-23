#pragma once
#include "bullet.h"

class CTangTang :
	public CBullet
{
	private:
	CObj* m_pPlayer;



public:
	void SetPlayer(CObj* _pPlayer);
	void SetDir(int _iDIr);
	void SetType(int _Type);
		void SetXS(int _xs);
	void SetYS(int _ys);
	float GetXS();
	float GetYS();


public:
	virtual void Initialize(void);
	virtual void Render(HDC hdc);	
	virtual int Progress(void);		
	virtual void Release(void);
public:
	CTangTang(void);
	~CTangTang(void);
};
