#include "StdAfx.h"
#include "Back.h"

CBack::CBack(void)
{
}

CBack::~CBack(void)
{
	Release();
}

void CBack::Initialize(void)
{
	m_strKey = "stage";
	m_tInfo = INFO(0.f, 0.f, 3432.f, 1528.f,0,0);

}

int CBack::Progress(void)
{
	return 0;
}

void CBack::Render(HDC hdc)
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

void CBack::Release(void)
{
	
}
