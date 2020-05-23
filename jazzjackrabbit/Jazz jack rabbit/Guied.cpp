#include "StdAfx.h"
#include "Guied.h"

CGuied::CGuied(void)
{
}

CGuied::~CGuied(void)
{
	Release();
}
void CGuied::Initialize(void)
{
	m_tInfo.fCX = 18.f;
	m_tInfo.fCY = 9.f;
	m_fSpeedY = -1.5f;
	m_fSpeedX = 0.5f;
	bDir=0;
	m_fBulletSpd = 3.f;
	m_tInfo.iAttack=2;
	fGuidedX=0;
	fGuidedY=0;
	

}

void CGuied::Render(HDC hdc)
{
	if( bDir == 1)  
	{
		TransparentBlt(hdc,
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY),
			(*m_pBitMap)["Guied_right"]->GetMemDC(),
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
			(*m_pBitMap)["Guied_up"]->GetMemDC(),
			0, 0,
			(int)m_tInfo.fCX,(int)m_tInfo.fCY,
			RGB(150, 150, 150));
	}
}
int CGuied::Progress()
{
	//m_tInfo.fX -= cosf(fGuidedY) * m_fBulletSpd;	
//	m_tInfo.fY -= sinf(fGuidedY) * m_fBulletSpd;


	if(m_iDIr == 1)  	
	{
		m_tInfo.fCX = 18.f;
		m_tInfo.fCY = 9.f;
		m_strKey="Guied_right";

		bDir=1;
	}
	else if(m_iDIr == 2)  
	{
		m_tInfo.fCX = 18.f;
		m_tInfo.fCY = 9.f;
		m_strKey="Guied_right";

			bDir=1;
	}
	else if(m_iDIr == 3)  	
	{
		m_tInfo.fCX = 9.f;
		m_tInfo.fCY = 18.f;
		m_strKey="Guied_up";

			bDir=0;
	}
	
	else if(m_iDIr== 4)  	
	{	
		
		m_tInfo.fCX = 9.f;
		m_tInfo.fCY = 18.f;
		m_strKey="Guied_up";

			bDir=0;
	}
	
	else if(m_iDIr == 5)  	
	{	
		m_tInfo.fCX = 18.f;
		m_tInfo.fCY = 9.f;
		m_strKey="Guied_right";

			bDir=1;
	}
	
	else if(m_iDIr == 6)  	
	{	
		m_tInfo.fCX = 18.f;
		m_tInfo.fCY = 9.f;
		m_strKey="Guied_right";

		bDir=1;
	}
	
	m_tInfo.fX += fGuidedX * m_fBulletSpd/3000;
	m_tInfo.fY += fGuidedY * m_fBulletSpd/15000;
	
	//m_tInfo.fY += m_fBulletSpd;
	
	return 0;
}
void CGuied::Release()
{
	CreateEffect1();
}

void CGuied::SetPlayer(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}
void CGuied::SetMonster(CObj* _pMonster)
{
	m_pMonster = _pMonster;
}

void CGuied::SetDir(int _iDIr)
{
	m_iDIr = _iDIr;
}
void CGuied::SetType(int _Type)
{
	iWeaponType = _Type;
}
void CGuied::SetXY(float _x,float _y)
{
	fGuidedX += _x;
	fGuidedY -= _y;
}