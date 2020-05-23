#include "StdAfx.h"
#include "Obj.h"

map<string, CBitBmp*>*		CObj::m_pBitMap = NULL;
POINT CObj::m_ptScroll = {};

CObj::CObj(void)
:m_iDIr(0)
{

}

CObj::~CObj(void)
{
	
}

void CObj::SetEffectList(list<CObj*>* _pTempObjList)
{
	m_EffectList = _pTempObjList;
}
void CObj::SetEffectList2(list<CObj*>* _pTempObjList)
{
	m_EffectList2 = _pTempObjList;
}
DIRECTION CObj::GetDIRECTION(void)
{
	return m_eDir;
}

void	CObj::SetJumpLimit(void)
{
	m_bDoubleJump = false;
}


void CObj::SetBitMap(map<string, CBitBmp*>* pBitMap)
{
	m_pBitMap = pBitMap;
}

void CObj::SetDrawKey(string strKey)
{
	m_strKey = strKey;
}

INFO CObj::GetInfo(void)
{
	return m_tInfo;
}

void CObj::SetPos(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

RECT CObj::GetRect(void)
{
	RECT	rc = {

		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fX + m_tInfo.fCX / 2.f),
		int(m_tInfo.fY + m_tInfo.fCY / 2.f)
	};

	return rc;
}



void CObj::SetBulletList(std::list<CObj*> *_pBullet)
{
	m_pBullet = _pBullet;

}



void CObj::SetDirection(DIRECTION _eDir) //무기방향
{
	m_eDir = _eDir;
}

void CObj::SetBox(int _Box) 
{
	m_iBox = _Box;
}

int CObj::GetBox()
{
	return m_iBox;
}

void CObj::SetDoubleJump(void)
{
	m_bDoubleJump = false;
}
int		CObj::GetWeaponType()
{
	return iWeaponType;
}
int    CObj::GetItemType()
{
	return m_iBox;
}


int CObj::GetScrollX()
{
	return m_ptScroll.x;
}
int CObj::GetScrollY()
{
	return m_ptScroll.y;
}
void CObj::SetOnGround(bool _bOnGround)
{
	m_bOnGround  = _bOnGround;
}
void CObj::SetXS(int _xs)
{
	m_fSpeedX = _xs;
}
void CObj::SetYS(int _ys)
{
	m_fSpeedY= _ys;
}
float CObj::GetXS()
{
 return m_fSpeedX;
}
float CObj::GetYS()
{
return m_fSpeedY;
}
void		CObj::SetAttack(int _iAttack)
{
	m_tInfo.iAttack = _iAttack;
}
void		CObj::SetHp(int _iHp)
{
	m_tInfo.iHp = _iHp;
}
void	CObj::SetSpeedY(float _SpeedY)
{
	m_fSpeedY = _SpeedY;
}
//
//void CObj::SetXY(float _x,float _y)
//{
//	fGuidedX -= _x;
//	fGuidedY -= _y;
//}
int CObj::GetScore(void)
{
	return iScorePoint;
}
void CObj::SetScore(int _iScorePoint)
{
	iScorePoint = _iScorePoint;
}

