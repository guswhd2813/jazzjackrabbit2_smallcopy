#pragma once

#include "Include.h"

class CSceneMgr;
class CMainGame
{
private:
	HDC			m_hdc;
	CSceneMgr*	m_pSceneMgr;
	DWORD		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[128];

public:
	void	Initialize(void);
	void	Progress(void);
	void	Render(void);
	void	Release(void);

public:
	CMainGame(void);
	~CMainGame(void);
};
