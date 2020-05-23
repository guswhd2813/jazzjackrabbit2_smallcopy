#include "StdAfx.h"
#include "SceneMgr.h"
#include "Logo.h"
#include "MyMenu.h"
#include "MyEdit.h"
#include "Stage.h"
#include "Stage2.h"

CSceneMgr* CSceneMgr::m_pInst = NULL;

CSceneMgr::CSceneMgr(void)
: m_pScene(NULL)
{

}

CSceneMgr::~CSceneMgr(void)
{
	Release();
}

void CSceneMgr::SetScene(SCENEID eScene)
{
	if(m_pScene != NULL)
		Release();

	switch(eScene)
	{
	case SC_LOGO:
		m_pScene = new CLogo;
		break;

	case SC_MENU:
		m_pScene = new CMyMenu;
		break;

	case SC_EDIT:
		m_pScene = new CMyEdit;
		break;

	case SC_STAGE:
		m_pScene = new CStage;
		break;
	case SC_STAGE2:
		m_pScene = new CStage2;
		break;
	}

	m_pScene->Initialize();
}

void CSceneMgr::Progress(void)
{
	if (m_pScene)
		m_pScene->Progress();
}

void CSceneMgr::Render(HDC hdc)
{
	if (m_pScene)
		m_pScene->Render(hdc);
}

void CSceneMgr::Release(void)
{	
	::Safe_Delete(m_pScene);
}

