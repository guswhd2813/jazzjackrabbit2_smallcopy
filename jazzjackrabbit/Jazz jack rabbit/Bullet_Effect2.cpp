#include "StdAfx.h"
#include "Bullet_Effect2.h"


CBullet_Effect2::CBullet_Effect2(void)
:m_dwTime(GetTickCount())
{
}

CBullet_Effect2::~CBullet_Effect2(void)
{
}
 void CBullet_Effect2::Initialize(void)
 {
	
	m_strKey = "effect2";
	m_iDrawID = 0;
	m_tInfo.fCX=65.f;
	m_tInfo.fCY=63.f;
	m_tFrame2 = FRAME(0, 0, 0, 80);
	m_dwTime8 = GetTickCount();
	

 }
int CBullet_Effect2::Progress(void)
{
	
	SetState(EF_EFFECT2, 12, 0, 100);			//¿Ã∆—∆Æ2
	m_dwState = ST_EFFECT2;
 	if(m_dwTime + m_tFrame2.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();
		++m_tFrame2.iStart;
	}

	if(m_tFrame2.iStart >= m_tFrame2.iLast)
	{
		if(m_dwState != ST_STAND)
			m_dwState = ST_STAND;

		m_tFrame2.iStart = 0;
	}

//	SetState(ST_EFFECT2, 12, 0, 80);
//	SetState(ST_EFFECT3, 7, 0, 80);


	return 0;
}

void CBullet_Effect2::Render(HDC hdc)
{
		TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)["effect2"]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame2.iStart), 
		int(m_tInfo.fCY * m_tFrame2.iScene), 
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(150,150,150));

}

void CBullet_Effect2::Release(void)
{

}

void  CBullet_Effect2::SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime)
{	
	if(m_dwState & dwState)
	{
		if(m_tFrame2.iScene != iScene)
			m_tFrame2.iStart = 0;

		m_tFrame2.iLast = iLast;
		m_tFrame2.iScene = iScene;
		m_tFrame2.dwTime = dwTime;
	}
	
	
}
DWORD CBullet_Effect2::GetTime()
{
	return m_dwTime8;
}