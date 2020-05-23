#include "StdAfx.h"
#include "Back2.h"

CBack2::CBack2(void)
{
}

CBack2::~CBack2(void)
{
}

void CBack2::Initialize(void)
{
	m_strKey = "stage2";
	m_tInfo = INFO(0.f, 0.f, 1539.f, 5968.f,0,0);

}

int CBack2::Progress(void)
{
	return 0;
}

void CBack2::Render(HDC hdc)
{
	//TransparentBlt(hdc, 
	//	int(m_tInfo.fX + m_ptScroll.x),
	//	int(m_tInfo.fY + m_ptScroll.y),
	//	int(m_tInfo.fCX), int(m_tInfo.fCY)
	//	, (*m_pBitMap)[m_strKey]->GetMemDC(),
	//	0, 0, 
	//	(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
	//	RGB(255, 255, 255));3

		TransparentBlt(hdc, 
		0,
		0,
		WINCX, WINCY
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		-m_ptScroll.x, -m_ptScroll.y, 
		WINCX, WINCY, 
		RGB(72,48,168));//72,48,168

}

void CBack2::Release(void)
{
	
}
