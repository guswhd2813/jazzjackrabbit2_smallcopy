#include "StdAfx.h"
#include "Nomal.h"

CNomal::CNomal(void)
:m_dwTime(GetTickCount())
{
}

CNomal::~CNomal(void)
{
	Release();
}

void CNomal::Initialize(void)
{
	m_fBulletSpd = 3.f;
	bDir=0;
	m_dwTime = GetTickCount(); 
	m_tInfo.iAttack=1;
}

void CNomal::Render(HDC hdc)
{
	if( bDir == 1)  
	{
		TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["Nomal"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));
	}
	if( bDir  == 0)  
	{
			TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["Nomal_up"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));
	}
}
int CNomal::Progress()
{
	
	if(m_iDIr == 1)  	
	{
		m_tInfo.fCX = 13.f;
		m_tInfo.fCY = 4.f;
		m_strKey="Nomal";
		m_tInfo.fX += m_fBulletSpd;
		bDir=1;
	}
	else if(m_iDIr == 2)  
	{
		m_tInfo.fCX = 13.f;
		m_tInfo.fCY = 4.f;
		m_strKey="Nomal";
		m_tInfo.fX -= m_fBulletSpd;
		bDir=1;
	}
	else if(m_iDIr == 3)  	
	{
		m_tInfo.fCX = 4.f;
		m_tInfo.fCY = 13.f;		
		m_strKey="Nomal-up";
		m_tInfo.fY -= m_fBulletSpd;
		bDir=0;
	}
	
	else if(m_iDIr== 4)  	
	{	
		m_tInfo.fCX = 4.f;
		m_tInfo.fCY = 13.f;
		m_strKey="Nomal-up";
		m_tInfo.fY -= m_fBulletSpd;
		bDir=0;
	}
	
	else if(m_iDIr == 5)  	
	{	
		m_tInfo.fCX = 13.f;
		m_tInfo.fCY = 4.f;
		m_strKey="Nomal";
		m_tInfo.fX += m_fBulletSpd;
		bDir=1;
	}
	
	else if(m_iDIr == 6)  	
	{	
		m_tInfo.fCX = 13.f;
		m_tInfo.fCY = 4.f;
		m_strKey="Nomal";
		m_tInfo.fX -= m_fBulletSpd;
		bDir=1;
	}
	
	if(m_dwTime + 400 < GetTickCount())
	{
		
	}
	
	

	
	//m_tInfo.fY += m_fBulletSpd;
	
	return 0;
}
void CNomal::Release()
{
	CreateEffect1();
}

void CNomal::SetPlayer(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}


void CNomal::SetDir(int _iDIr)
{
	m_iDIr = _iDIr;
}