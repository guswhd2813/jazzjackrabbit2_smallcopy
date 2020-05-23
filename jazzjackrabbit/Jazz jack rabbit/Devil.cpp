#include "StdAfx.h"
#include "Devil.h"

CDevil::CDevil(void)
{
}

CDevil::~CDevil(void)
{
}


void CDevil::Initialize(void)
{
	m_tInfo.fCX = 57.f;
	m_tInfo.fCY = 39.f;
	m_fSpeed =0.4f;


	m_tInfo.iHp = 2;
	m_tInfo.iAttack = 1;
	
	m_strKey = "devil";
	m_dwState=ST_STAND;
	m_iDrawID = 0;
	m_dwTime6 = GetTickCount();
	m_tFrame1 = FRAME(0, 0, 0, 80);
	m_bOnGround = false;
	m_fSpeedY = 0;

	fPrefX =m_tInfo.fX;
}

int CDevil::Progress(void)
{

	if(!m_bOnGround)
	{
		m_fSpeedY +=0.02;
		m_tInfo.fY += m_fSpeedY;
			
	}
	else
	{
		m_tInfo.fY += m_fSpeedY;
		m_fSpeedY = 0.f;
	}

	if(m_dwTime6 + m_tFrame1.dwTime < GetTickCount())
	{
		m_dwTime6 = GetTickCount();
		++m_tFrame1.iStart;
	}

	if(m_tFrame1.iStart >= m_tFrame1.iLast)
	{
		if(m_dwState != ST_STAND)
			m_dwState = ST_STAND;

		m_tFrame1.iStart = 0;
	}

		SetState(ST_STAND,8,0,100);
		m_dwState = ST_STAND;

			

	if(m_tInfo.fX > fPrefX+170.f  || m_tInfo.fX < fPrefX-450.f  )
	{
		
		m_fSpeed *=-1;
	
	}	
	

	m_tInfo.fX += m_fSpeed;
	m_fSpeed +=0.01f;
	
	return 0;
}


void CDevil::Render(HDC hdc)
{
	if(m_fSpeed>0)
	{
		TransparentBlt(hdc, 
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY)
			, (*m_pBitMap)["devil"]->GetMemDC(),
			int(m_tInfo.fCX * m_tFrame1.iStart), 
				int(m_tInfo.fCY * m_tFrame1.iScene), 
			(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
			RGB(0, 128, 255));
	}
	else
	{
		TransparentBlt(hdc, 
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY)
			, (*m_pBitMap)["devil1"]->GetMemDC(),
			int(m_tInfo.fCX * m_tFrame1.iStart), 
				int(m_tInfo.fCY * m_tFrame1.iScene), 
			(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
			RGB(0, 128, 255));
	}

}

void CDevil::Release(void)
{
	
}

void CDevil::SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime)
{
	
	if(m_dwState & dwState)
	{
		if(m_tFrame1.iScene != iScene)
			m_tFrame1.iStart = 0;

		m_tFrame1.iLast = iLast;
		m_tFrame1.iScene = iScene;
		m_tFrame1.dwTime = dwTime;
	}
	
	
}