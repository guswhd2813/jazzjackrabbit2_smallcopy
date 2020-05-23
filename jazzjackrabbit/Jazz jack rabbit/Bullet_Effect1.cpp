#include "StdAfx.h"
#include "Bullet_Effect1.h"
#include "device.h"


CBullet_Effect1::CBullet_Effect1(void)
:m_dwTime(GetTickCount())
{
}

CBullet_Effect1::~CBullet_Effect1(void)
{
}
 void CBullet_Effect1::Initialize(void)
 {
	
	m_strKey = "effect1";
	m_iDrawID = 0;
	m_tInfo.fCX=56.f;
	m_tInfo.fCY=50.f;
	m_tFrame = FRAME(0, 0, 0, 80);
	m_dwTime5 = GetTickCount();
	CDevice::GetInstance()->SoundPlay(10, 0);

 }
int CBullet_Effect1::Progress(void)
{
	
	SetState(EF_EFFECT1, 8, 0, 100);			//¿Ã∆—∆Æ1
	m_dwState = ST_EFFECT1;
	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();
		++m_tFrame.iStart;
	}

	if(m_tFrame.iStart >= m_tFrame.iLast)
	{
		if(m_dwState != ST_STAND)
			m_dwState = ST_STAND;

		m_tFrame.iStart = 0;
	}

//	SetState(ST_EFFECT2, 12, 0, 80);
//	SetState(ST_EFFECT3, 7, 0, 80);

	
	

	return 0;
}
void CBullet_Effect1::Render(HDC hdc)
{
		TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)["effect1"]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart), 
		int(m_tInfo.fCY * m_tFrame.iScene), 
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(150,150,150));

}
void CBullet_Effect1::Release(void)
{

}

void  CBullet_Effect1::SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime)
{
	
	if(m_dwState & dwState)
	{
		if(m_tFrame.iScene != iScene)
			m_tFrame.iStart = 0;

		m_tFrame.iLast = iLast;
		m_tFrame.iScene = iScene;
		m_tFrame.dwTime = dwTime;
	}
	
	
}
DWORD CBullet_Effect1::GetTime()
{
	return m_dwTime5;
}