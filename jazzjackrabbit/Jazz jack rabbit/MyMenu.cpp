#include "StdAfx.h"
#include "MyMenu.h"
#include "MyButton.h"
#include "Factory.h"
#include "SceneMgr.h"
#include "device.h"


CMyMenu::CMyMenu(void)
{
}

CMyMenu::~CMyMenu(void)
{
	Release();
}

void CMyMenu::Initialize(void)
{
	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/back.bmp");
	m_BitMap["menu"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/menu.bmp");

	m_BitMap["Start"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Start.bmp");
	m_BitMap["Edit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Edit.bmp");
	m_BitMap["Exit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Exit.bmp");
	CDevice::GetInstance()->LoadWave(L"../Sound/menu.wav");	// 0d
	CDevice::GetInstance()->LoadWave(L"../Sound/castle.wav");		// 1d
	CDevice::GetInstance()->LoadWave(L"../Sound/sugarrush.wav");	// 2
	CDevice::GetInstance()->LoadWave(L"../Sound/click1.wav");//3
	CDevice::GetInstance()->LoadWave(L"../Sound/click2.wav");//4
	CDevice::GetInstance()->LoadWave(L"../Sound/click3.wav");//5
	CDevice::GetInstance()->LoadWave(L"../Sound/gun.wav");//6d
	CDevice::GetInstance()->LoadWave(L"../Sound/jump.wav");//7d
	CDevice::GetInstance()->LoadWave(L"../Sound/jump2.wav");//8d
	CDevice::GetInstance()->LoadWave(L"../Sound/damege.wav");//9d
	CDevice::GetInstance()->LoadWave(L"../Sound/effect.wav");//10d
	CDevice::GetInstance()->LoadWave(L"../Sound/pounding.wav");//11d
	CDevice::GetInstance()->LoadWave(L"../Sound/box.wav");//12d
	CDevice::GetInstance()->LoadWave(L"../Sound/sliding.wav");//13d


	CDevice::GetInstance()->SoundPlay(0, 1);


	m_ButtonList.push_back(CreateButton(150.f, 550.f, "Start"));
	m_ButtonList.push_back(CreateButton(400.f, 550.f, "Edit"));
	m_ButtonList.push_back(CreateButton(650.f, 550.f, "Exit"));

	CObj::SetBitMap(&m_BitMap);

}
CObj* CMyMenu::CreateButton(float _fX, float _fY, string _strKey)
{
	CObj*		pButton = CFactory<CMyButton>::CreateObj(_fX, _fY);

	pButton->SetDrawKey(_strKey);

	return pButton;

}
int CMyMenu::Progress(void)
{
	int iSelect = 0;

	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		iSelect = (*iter)->Progress();

		switch(iSelect)
		{
		case 1:
			CSceneMgr::GetInst()->SetScene(SC_STAGE);
			return 0;

		case 2:
			CSceneMgr::GetInst()->SetScene(SC_EDIT);
			return 0;

		case 3:
			DestroyWindow(g_hWnd);
			break;
		}

	}

	return 0;
}

void CMyMenu::Render(HDC hdc)
{
	BitBlt(m_BitMap["back"]->GetMemDC(), 
		0, 0, 
		WINCX, WINCY, 
		m_BitMap["menu"]->GetMemDC(), 
		0, 0, SRCCOPY);

	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		(*iter)->Render(m_BitMap["back"]->GetMemDC());
	}


	BitBlt(hdc, 
		0, 0, 
		WINCX, WINCY, 
		m_BitMap["back"]->GetMemDC(), 
		0, 0, SRCCOPY);
}

void CMyMenu::Release(void)
{
	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		::Safe_Delete(*iter);
	}
	m_ButtonList.clear();
	CDevice::GetInstance()->SoundStop(0);
}
