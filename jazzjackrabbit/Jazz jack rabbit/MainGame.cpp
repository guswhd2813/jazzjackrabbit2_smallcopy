#include "StdAfx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "RenderMgr.h"
#include "Device.h"


CMainGame::CMainGame(void)
: m_pSceneMgr(CSceneMgr::GetInst()),m_iFPS(0),m_dwTime(GetTickCount())
{
	memset(m_szFPS, 0, sizeof(TCHAR) * 128);
}

CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hdc = GetDC(g_hWnd);
	CDevice::GetInstance()->Init();

	m_pSceneMgr->SetScene(SC_LOGO);
}

void CMainGame::Progress(void)
{
	CKeyMgr::GetInst()->KeyCheck();
	m_pSceneMgr->Progress();
}

void CMainGame::Render(void)
{
	m_pSceneMgr->Render(m_hdc);
	++m_iFPS;


		if(m_dwTime + 1000 < GetTickCount())
		{
			m_dwTime = GetTickCount();
			wsprintf(m_szFPS, L"FPS : %d", m_iFPS);
			m_iFPS = 0;
		}
		
		
		TextOut(m_hdc, 650, 20, m_szFPS, lstrlen(m_szFPS));
}

void CMainGame::Release(void)
{
	m_pSceneMgr->DestroyInst();
	CKeyMgr::GetInst()->DestroyInst();
	CObjMgr::GetInst()->DestroyInst();
	CRenderMgr::GetInst()->DestroyInst();
	CDevice::GetInstance()->DestroyInst();

	ReleaseDC(g_hWnd, m_hdc);
}
