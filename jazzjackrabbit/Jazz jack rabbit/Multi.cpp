#include "StdAfx.h"
#include "Multi.h"

CMulti::CMulti(void)
:bUp(0),bLR(0)
{
}

CMulti::~CMulti(void)
{
	Release();
}
void CMulti::Initialize(void)
{
	m_tInfo.fCX = 19.f;
	m_tInfo.fCY = 9.f;
	m_fBulletSpd = 3.f;
	
	
	
}

void CMulti::Render(HDC hdc)
{
	if(bLR==1 && bUp==0)
	{
		TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["multi-right"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));
	}
	 else if(bLR==0 && bUp==0)
	{
	TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["multi-left"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));
	}
	else if(bUp==1)
	{
		TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["multi-up"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));
	}

}
int CMulti::Progress()
{
	
	if(m_iDIr == 1)  	
	{
		m_strKey="multi-right";
		m_tInfo.fCX = 19.f;
		m_tInfo.fCY = 9.f;
		bUp=0;
		bLR=1;
		switch(m_eDir)
		{
		case DIR_UP:
			
				m_tInfo.fX += m_fBulletSpd;
			break;
			
		case DIR_LU:
			
				m_tInfo.fX += m_fBulletSpd;
				m_tInfo.fY -= 0.9f;

			break;
		case DIR_RU:			
				m_tInfo.fX += m_fBulletSpd;
				m_tInfo.fY += 0.9f;

			break;
		}
	}
	if(m_iDIr == 2)  	
	{
		m_strKey="multi-left";
		m_tInfo.fCX = 19.f;
		m_tInfo.fCY = 9.f;
		bUp=0;
		bLR=0;
		switch(m_eDir)
		{
		case DIR_UP:
			
				m_tInfo.fX -= m_fBulletSpd;
			break;
			
		case DIR_LU:
			
				m_tInfo.fX -= m_fBulletSpd;
				m_tInfo.fY -= 0.9f;

			break;
		case DIR_RU:			
				m_tInfo.fX -= m_fBulletSpd;
				m_tInfo.fY += 0.9f;

			break;
		}
	}
	if(m_iDIr == 3)  	
	{
		m_strKey="multi-up";
		m_tInfo.fCX = 9.f;
		m_tInfo.fCY = 19.f;
		bUp=1;
		bLR=0;
		switch(m_eDir)
		{
		case DIR_UP:
			
				m_tInfo.fY -= m_fBulletSpd;
			break;
			
		case DIR_LU:
			
				m_tInfo.fY -= m_fBulletSpd;
				m_tInfo.fX -= 0.9f;

			break;
		case DIR_RU:			
				m_tInfo.fY -= m_fBulletSpd;
				m_tInfo.fX += 0.9f;

			break;
		}
	}
	if(m_iDIr == 4)  	
	{
		m_strKey="multi-up";
		m_tInfo.fCX = 9.f;
		m_tInfo.fCY = 19.f;
		bUp=1;
		bLR=1;
		switch(m_eDir)
		{
		case DIR_UP:
			
				m_tInfo.fY -= m_fBulletSpd;
			break;
			
		case DIR_LU:
			
				m_tInfo.fY -= m_fBulletSpd;
				m_tInfo.fX -= 0.9f;

			break;
		case DIR_RU:			
				m_tInfo.fY -= m_fBulletSpd;
				m_tInfo.fX += 0.9f;

			break;
		}
	}
	if(m_iDIr == 5)  	
	{
		m_strKey="multi-right";
		m_tInfo.fCX = 19.f;
		m_tInfo.fCY = 9.f;
		bUp=0;
		bLR=1;
		switch(m_eDir)
		{
		case DIR_UP:
			
				m_tInfo.fX += m_fBulletSpd;
			break;
			
		case DIR_LU:
			
				m_tInfo.fX += m_fBulletSpd;
				m_tInfo.fY -= 0.9f;

			break;
		case DIR_RU:			
				m_tInfo.fX += m_fBulletSpd;
				m_tInfo.fY += 0.9f;

			break;
		}
	}
	if(m_iDIr == 6)  	
	{
		m_strKey="multi-left";
		m_tInfo.fCX = 19.f;
		m_tInfo.fCY = 9.f;
		bUp=0;
		bLR=0;
		switch(m_eDir)
		{
		case DIR_UP:
			
				m_tInfo.fX -= m_fBulletSpd;
			break;
			
		case DIR_LU:
			
				m_tInfo.fX -= m_fBulletSpd;
				m_tInfo.fY -= 0.9f;

			break;
		case DIR_RU:			
				m_tInfo.fX -= m_fBulletSpd;
				m_tInfo.fY += 0.9f;

			break;
		}
	}
	
	
	
	

	
	//m_tInfo.fY += m_fBulletSpd;
	
	return 0;
}
void CMulti::Release()
{
	CreateEffect1();
}

void CMulti::SetPlayer(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}


void CMulti::SetDir(int _iDIr)
{
	m_iDIr = _iDIr;
}