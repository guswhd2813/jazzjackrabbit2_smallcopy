#include "StdAfx.h"
#include "TangTang.h"

CTangTang::CTangTang(void)

{
}

CTangTang::~CTangTang(void)
{
	Release();
}
void CTangTang::Initialize(void)
{
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 13.f;
	m_fBulletSpd = 3.5f;
	m_fSpeedX=1.5f;
	m_fSpeedY=1.5f;
	
	m_bOnGround=0;
}

void CTangTang::Render(HDC hdc)
{
		TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["tangtang"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));

}
int CTangTang::Progress()
{
	if(m_iDIr == 1)  	
	{
		m_strKey="tangtang";
		m_tInfo.fX += m_fSpeedX;
		m_tInfo.fY -= m_fSpeedY;
		
	}
	else if(m_iDIr == 2)  
	{
		m_strKey="tangtang";
		m_tInfo.fX -= m_fSpeedX;
		m_tInfo.fY += m_fSpeedY;
	}
	else if(m_iDIr == 3)  	
	{
		
		m_strKey="tangtang";
		m_tInfo.fX += m_fSpeedX;
		m_tInfo.fY -= m_fSpeedY;
	}
	
	else if(m_iDIr== 4)  	
	{	
		
		m_strKey="tangtang";
		m_tInfo.fX -= m_fSpeedX;
		m_tInfo.fY -= m_fSpeedY;
	}
	
	else if(m_iDIr == 5)  	
	{	
		m_strKey="tangtang";
		m_tInfo.fX += m_fSpeedX;
		m_tInfo.fY += m_fSpeedY;
	}
	
	else if(m_iDIr == 6)  	
	{	
		m_strKey="tangtang";
		m_tInfo.fX -= m_fSpeedX;
		m_tInfo.fY += m_fSpeedY;
	}


	
	

	
	//m_tInfo.fY += m_fBulletSpd;
	
	return 0;
}
void CTangTang::Release()
{
	CreateEffect1();
}

void CTangTang::SetPlayer(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}


void CTangTang::SetDir(int _iDIr)
{
	m_iDIr = _iDIr;
}
void CTangTang::SetType(int _Type)
{
	iWeaponType = _Type;
}
void CTangTang::SetXS(int _xs)
{
	m_fSpeedX = _xs;
}
void CTangTang::SetYS(int _ys)
{
	m_fSpeedY= _ys;
}
float CTangTang::GetXS()
{
 return m_fSpeedX;
}
float CTangTang::GetYS()
{
return m_fSpeedY;
}

