#pragma once
#include "scene.h"

class CObj;
class CMyEdit :
	public CScene
{
private:
	vector<TILE*>		m_vecTile;
	
	float				m_fScrollX;
	float				m_fScrollY;

	int iPick;
	
	CObj*	m_pBack;

	TCHAR	m_szUI[128];

	DWORD		m_dwTime;
	bool		bStage;
	//∂Û¿Œ

public:


private:
	TILE* CreateTile(float _fX, float _fY);
	void  Picking(void);
	void Change(void);
	void  KeyInput(void);
	void  Scroll(void);

//
	void SaveMap(void);
	void LoadMap(void);

public:
	CMyEdit(void);
	~CMyEdit(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};