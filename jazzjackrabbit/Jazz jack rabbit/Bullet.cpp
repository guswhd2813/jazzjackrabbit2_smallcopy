#include "StdAfx.h"
#include "Bullet.h"
#include "Factory.h"
#include "Bullet_Effect1.h"
#include "Bullet_Effect2.h"

CBullet::CBullet(void)
{
}

CBullet::~CBullet(void)
{
}

void CBullet::CreateEffect1()
{
	m_EffectList->push_back(CFactory<CBullet_Effect1>::CreateObj(m_tInfo.fX,m_tInfo.fY));
	(m_EffectList->back())->SetEffectList(m_EffectList);
}
void CBullet::SetEffect(list<CObj*>* _pEffect)
{
	m_pEffect = _pEffect;
}

