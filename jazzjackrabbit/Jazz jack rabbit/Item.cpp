#include "StdAfx.h"
#include "Item.h"

CItem::CItem(void)
{
}

CItem::~CItem(void)
{
	Release();
}

void CItem::Initialize()
{
	m_tInfo.fCX = 32.f;
	m_tInfo.fCY = 32.f;
	m_tInfo.iHp = 2;
	m_bOnGround = false;
}

int CItem::Progress()
{

	return 1;	
}

void CItem::Render(HDC hdc)
{
	if(m_iBox==1) //ÅÊÅÊº¼
	{
		TransparentBlt(hdc, 
				int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
				int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
				int(m_tInfo.fCX), int(m_tInfo.fCY)
				, (*m_pBitMap)["TangBox"]->GetMemDC(),
				0,0,
				(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
				RGB(150,150,150));
	}

	else if(m_iBox == 2) //À¯µµÅº
	{
			TransparentBlt(hdc, 
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY)
			, (*m_pBitMap)["GuiedBox"]->GetMemDC(),
			0,0, 
			(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
			RGB(150,150,150));
	}

	else if(m_iBox == 3) //¸ÖÆ¼Åº
	{
			TransparentBlt(hdc, 
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY)
			, (*m_pBitMap)["mulBox"]->GetMemDC(),
			0,0,
			(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
			RGB(150,150,150));
	}



}

void CItem::Release()
{
}
void CItem::SetType(int _Type)
{
	m_iBox = _Type;
}
