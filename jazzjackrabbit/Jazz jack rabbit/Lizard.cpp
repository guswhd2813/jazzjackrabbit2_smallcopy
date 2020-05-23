#include "StdAfx.h"
#include "Lizard.h"


CLizard::CLizard(void)
:m_patternTime(GetTickCount())
{
}

CLizard::~CLizard(void)
{
}

void CLizard::Initialize(void)
{
	m_tInfo.fCX = 75.f;
	m_tInfo.fCY = 55.f;
	m_fSpeed =0.5f;


	m_tInfo.iHp = 2;
	m_tInfo.iAttack = 1;
	
	m_strKey = "lizard";
	m_dwState=ST_STAND;
	m_iDrawID = 0;
	m_dwTime6 = GetTickCount();
	m_tFrame1 = FRAME(0, 0, 0, 80);

	m_bOnGround = false;
	m_fSpeedY = 0;

	fPrefX =m_tInfo.fX;
}

int CLizard::Progress(void)
{

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

		SetState(ST_STAND,12,0,100);
		m_dwState = ST_STAND;

	if(!m_bOnGround)
	{
		m_fSpeedY += 0.02f;
		m_tInfo.fY += m_fSpeedY;
			
	}
	else
	{
		m_tInfo.fY += m_fSpeedY;
		m_fSpeedY = 0.f;
	}
	
	

	if(m_tInfo.fX > fPrefX+120.f  || m_tInfo.fX < fPrefX-170.f  )
	{
		m_fSpeed *=-1;
	
	}	
	m_tInfo.fX += m_fSpeed;

	
	
	return 0;
}


void CLizard::Render(HDC hdc)
{
	if(m_fSpeed>0)
	{
		TransparentBlt(hdc, 
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY)
			, (*m_pBitMap)["lizard"]->GetMemDC(),
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
			, (*m_pBitMap)["lizard1"]->GetMemDC(),
			int(m_tInfo.fCX * m_tFrame1.iStart), 
				int(m_tInfo.fCY * m_tFrame1.iScene), 
			(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
			RGB(0, 128, 255));
	}

}

void CLizard::Release(void)
{
	
}

void CLizard::SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime)
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