#include "StdAfx.h"
#include "MyButton.h"
#include "device.h"
#include "KeyMgr.h"

CMyButton::CMyButton(void)
:m_tTime2(GetTickCount())
{
}

CMyButton::~CMyButton(void)
{
	Release();
}

void CMyButton::Initialize(void)
{
	
	m_tInfo.fCX = 247.f;
	m_tInfo.fCY = 82.f;
	m_iDrawID   = 0;
	iSelect     =0;
	
	
}

int CMyButton::Progress(void)
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();	
	m_tTime= GetTickCount();
	iRand = (m_tTime%3);	
		
	
	
	if(m_tTime2 + 100< GetTickCount())
	{
		m_tTime2 = GetTickCount();
		if(m_dwKey & KEY_RIGHT)
		{
			if(iRand==0) CDevice::GetInstance()->SoundPlay(3, 0);
			else if(iRand==1) CDevice::GetInstance()->SoundPlay(4, 0);
			else if(iRand==2) CDevice::GetInstance()->SoundPlay(5, 0);
			
			iSelect++;
		}
		if(m_dwKey & KEY_LEFT)
		{
			if(iRand==0) CDevice::GetInstance()->SoundPlay(3, 0);
			else if(iRand==1) CDevice::GetInstance()->SoundPlay(4, 0);
			else if(iRand==2) CDevice::GetInstance()->SoundPlay(5, 0);
			iSelect--;
		}
		if(iSelect>2) iSelect=0;
		if(iSelect<0) iSelect=2;
	}

		


		if(iSelect==0)
		{
			m_iDrawID = 0;
			m_strKey =="Start";
				if(GetAsyncKeyState(VK_RETURN))	return 1;
		}
		if(iSelect==1)
		{
			
			m_strKey =="Edit";
			m_iDrawID = 1;
				if(GetAsyncKeyState(VK_RETURN))	return 2;
		}
		if(iSelect==2)
		{
			
			m_strKey =="Exit";
			m_iDrawID = 2;
				if(GetAsyncKeyState(VK_RETURN))	return 2;
		}
	


	return 0;
}

void CMyButton::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		int(m_tInfo.fCX * m_iDrawID), 0, 
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(180, 255, 255));
}

void CMyButton::Release(void)
{
	
}
