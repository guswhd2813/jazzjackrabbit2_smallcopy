#include "StdAfx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "Factory.h"
#include "Bullet.h"
#include "Nomal.h"
#include "Guied.h"
#include "Multi.h"
#include "tangtang.h"
#include "Bullet_Effect1.h"
#include "device.h"

CPlayer::CPlayer(void)
: bSliding(0),bPounding(0),m_fPoundingSpeed(0)
, m_dwTime(GetTickCount())
, m_dwTime2(GetTickCount())
,m_dwTime3(GetTickCount())
,m_HurtTime(GetTickCount())
,m_dwTimeSliding(GetTickCount())
,m_dwAttackSpeed(GetTickCount()),iSpecialMov(0),iTempHp(0),bDeath(0),
iAmount1(0),
iAmount2(0),
iAmount3(0),
iAmount4(0),
iTemp(0),
iTemp2(0),
iTemp3(0),
iTemp4(0),
iTemp5(0),
iTemp6(0)
{
}

CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = INFO(150, 150, 50.f, 50.f,0,5);
	//m_tInfo = INFO(2550, 1250, 50.f, 50.f,0,5);
	m_tInfo.iHp=5;
	m_strKey = "Player_RIGHTSTAND";
	m_iDrawID = 0;
	m_fSpeed = 2.f;
	m_iDIr = 1;
	m_dwState = ST_STAND;
	m_ptOffset.x = WINCX / 2;
	m_ptOffset.y = WINCY / 2;
	m_tFrame = FRAME(0, 0, 0, 80);
	iWeaponType=1;
	//점프관련
	m_bOnGround=0;
	m_dwTime=0;
	m_dwTime2=0;
	m_dwTime3=0;
	m_HurtTime=0;
	m_dwTimeSliding=0;
	m_bDoubleJump=false;  // 더블점프
	m_fSpeedY =0.f;	//중력
	m_fSpeedX = 3.f;//슬라이딩	
	
	m_bChange=0; //1-키안먹힘 0 -키먹힘
	bHurt=0; //다치면 1됬다가 잠시후 0으로 초기화
	

	
}
void CPlayer::SetAmount1(int _Amount1)
{
	iAmount1 += _Amount1;
	iTemp+= _Amount1;
}
void CPlayer::SetAmount2(int _Amount2)
{
	iAmount2 += _Amount2;
	iTemp3 +=_Amount2;
}
void CPlayer::SetAmount3(int _Amount3)
{
	iAmount3 += _Amount3;
	iTemp5 += _Amount3;
}
void CPlayer::SpecialMove(void)//슬라이딩태클 / 파운딩시 중력,키움직임무시
{
	
	if(bSliding==1)//슬라이딩
	{		
		bPounding=0;
		
		if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
		{
			m_tInfo.fX += m_fSpeedX;
		}
		else	//왼
		{			
			m_tInfo.fX -= m_fSpeedX;
		}

		if(m_dwTimeSliding + 800 <  GetTickCount())
		{			
			m_dwTimeSliding= GetTickCount();
			bPounding=0;
			m_bChange=0;
			bSliding=0;
			m_fSpeedX=3.f;			
		}
	}
	if(bPounding==1)
	{		
		bSliding=0;
		m_fSpeedY =0;
		m_tInfo.fY +=0;
		m_fPoundingSpeed=2.f;		
		
		if(m_dwTime2 + 1500 < GetTickCount()) 
		{
			m_fPoundingSpeed +=0.3f;
			m_tInfo.fY +=m_fPoundingSpeed;
		}				
		
		if(m_bOnGround)
		{
			CDevice::GetInstance()->SoundPlay(11, 0);
			m_dwTime2= GetTickCount();
			m_fPoundingSpeed=0;
			m_bChange=0;	
			bPounding=0;

		}
	}	
	
}
void CPlayer::SetHurt(bool _hurt)
{
	bHurt = _hurt;
}
bool CPlayer::GetHurt()
{
	return bHurt;
}

int CPlayer::Progress(void)
{
	
	if(m_bChange)//태클및파운딩땐 조작불가
	{
		SpecialMove();
	}
	else if(m_bChange ==false)
	{	
		
		KeyCheck();
		Direction();		
	
		if(!m_bOnGround) //땅아님  -> 중력작용
		{		
				m_fSpeedY += 0.015f;	//중력증가
				m_tInfo.fY += m_fSpeedY; //항상 중력만큼 떨어짐									
		}
		else //땅임
			m_tInfo.fY += m_fSpeedY; //항상 중력만큼 떨어짐				
	}	
	
	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();
		++m_tFrame.iStart;
	}

	if(m_tFrame.iStart >= m_tFrame.iLast)
	{
		if(m_dwState != ST_STAND)
			m_dwState = ST_STAND;

		m_tFrame.iStart = 0;
	}
	SetState(ST_STAND, 5, 0, 80);				//서있는 동작
	SetState(ST_WALK, 8, 0, 100);				//걷는동작
	SetState(ST_RUNNING, 3, 0, 100);		//달리기
	SetState(ST_ATTACK, 4, 0, 80);			//공격
	SetState(ST_JUMP, 10, 0, 60);				//점프
	SetState(ST_DAMAGE, 11, 0, 80);			//상처
	SetState(ST_SLIDING, 11, 0, 100);			//슬라이딩
	SetState(ST_LOOKUP,2,0,80);				//위에봄
	SetState(ST_SIT,1,0,100);						//엎드림
	SetState(ST_POUND,1,0,100);				//파운딩
	SetState(ST_DEATH,18,0,100);				//사망
	SetState(ST_FALLING,3,0,100);				//떨어짐
	SetState(ST_EFFECT1, 8, 0, 80);			//이팩트1
	
	if(bHurt)
	{
		
		//m_dwState = ST_DAMAGE;
		m_strKey = "Player_HURT";
		m_bChange=1;
		if(m_HurtTime + 2000 <= GetTickCount())
		{
			m_HurtTime = GetTickCount();
			m_bChange=0;
			m_dwState = ST_STAND;
		
			bHurt=0;
		}
		
	}

	


	
	//SetState(ST_DEATH, 4, 0, 80);

	//ST_STAND ST_WALK	ST_RUNNING	ST_ATTACK ST_JUMP
	//	ST_DAMAGE  ST_SLIDING ST_DEATHy
	ScrollX();
	ScrollY();

	

	return 0;

}
void CPlayer::SetTempHp(int _iHp)
{
	iTempHp=_iHp;
}
void CPlayer::SetTime(DWORD _Time)
{
	m_dwTime3 = _Time;
}


void CPlayer::KeyCheck(void)
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if(!m_dwKey ) //키입력 ㄴㄴ- 서있음
	{		
		if(m_iDIr==3) m_iDIr=1;// 오른쪽위보고 있있으면 오른쪽고정
		if(m_iDIr==4) m_iDIr=2;// 왼쪽  위보고 있었으면 왼쪽고정
		if( !m_bOnGround ) //떨어지는중
			m_dwState = ST_FALLING;
		else
			m_dwState = ST_STAND;		
	}

	if(m_dwState & KEY_SPACE)
	{
		m_dwState = ST_ATTACK;
	}

	if(m_dwKey & KEY_LEFT)
	{
		m_dwState = ST_WALK;
		m_tInfo.fX -= m_fSpeed;
		if(m_dwKey & KEY_SHIFT)	m_dwState = ST_RUNNING;
		m_bOnGround=0;		
	}		

	if(m_dwKey & KEY_RIGHT)
	{
		m_dwState = ST_WALK;
		m_tInfo.fX += m_fSpeed;
		if(m_dwKey & KEY_SHIFT)	m_dwState = ST_RUNNING;
		m_bOnGround=0;	
	}

	if(m_dwKey & KEY_UP)
	{
		m_dwState = ST_LOOKUP;		
	}

	if(m_dwKey & KEY_DOWN)
	{
		m_dwState = ST_SIT;
	}
	
	if(  ( m_dwKey & KEY_DOWN) && ( m_dwKey & KEY_CONTROAL) )
	{	
		if(  (m_bOnGround)  ) //땅에 있으면
		{
			
			m_dwTimeSliding=GetTickCount();
			m_dwState = ST_SLIDING;		
			m_bOnGround=0;
		}
	}

	if(m_dwKey & KEY_CONTROAL )
	{
		if(!m_bOnGround && !m_bDoubleJump && m_fSpeedY >-1.f)
		{
			
			m_fSpeedY = -1.5f;
			m_bDoubleJump = true;
		}
		if(m_bDoubleJump)
		{
			CDevice::GetInstance()->SoundPlay(8, 0);
			
			return;
		}
		if(m_bOnGround)
		{
			CDevice::GetInstance()->SoundPlay(7, 0);
			m_fSpeedY = -1.8f;
			m_tInfo.fY -= 1.f;		
			m_bOnGround = false;
		}


	}
	
}

void CPlayer::Direction(void)
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();	

	if(m_dwKey & KEY_RETURN) //무기변경
	{
		if(m_dwTime + 50< GetTickCount())
		{
			m_dwTime = GetTickCount();
			iWeaponType++;
			

			if(iAmount1 == 0 &&  iWeaponType==2 ) iWeaponType =3;

			if(iAmount2 == 0 && iWeaponType==3)	iWeaponType =4;

			if( iAmount3 == 0 && iWeaponType==4) 	iWeaponType ++;

			if(iWeaponType>=5)	iWeaponType=1;
		}
	}

	if(m_dwKey & KEY_LEFT)
	{		
		m_iDIr=2;
		m_fSpeed =2.f;
		if(m_dwKey & KEY_SHIFT)
		{
			m_strKey = "Player_LEFTRUNNING";	
			m_fSpeed *=2;

		}
		else 
		m_strKey = "Player_LEFT";
	}

	if(m_dwKey & KEY_RIGHT)
	{
		m_iDIr=1;
		m_fSpeed =2.f;
		if(m_dwKey & KEY_SHIFT)
		{
			m_strKey = "Player_RIGHTRUNNING";
			m_fSpeed *=2;
		}
		else
		m_strKey = "Player_RIGHT";
	}

	if(m_dwKey & KEY_UP)
	{
		if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
		{
			m_strKey = "Player_RIGHTUP";
			m_iDIr = 3; //위오
		}
		else
		{
			m_strKey = "Player_LEFTUP";
			m_iDIr = 4; //위왼
			
		}
	}

	if(m_dwKey & KEY_DOWN)
	{
		if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
		{
			m_strKey = "Player_RIGHTDOWN";
			m_iDIr = 5; //아오
		}
		else
		{
			m_strKey = "Player_LEFTDOWN";
			m_iDIr = 6;	//아왼
		}
	}
	if(m_dwKey & KEY_SPACE ) 
	{		
		
			if ( !  ( (m_dwKey&KEY_LEFT ) || (m_dwKey&KEY_RIGHT) ) ) //움직이며 발사 금지
			{
				if(m_dwKey & KEY_DOWN)
				{
					if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
						m_strKey = "Player_RIGHTSITSHOOT";
					else
						m_strKey = "Player_LEFTSITSHOOT";
				}
				else if(m_dwKey & KEY_UP)
				{
					if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
						m_strKey = "Player_RIGHTUPSHOOT";		
					else
						m_strKey = "Player_LEFTUPSHOOT";
				}
				else
				{
					if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
						m_strKey = "Player_RIGHTATTACK";
					else
						m_strKey = "Player_LEFTATTACK";
				}
			}
			if(m_dwKey & KEY_SHIFT)
			{	
				if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
					m_strKey = "Player_RIGHTRUNNING";
				else
					m_strKey = "Player_LEFTRUNNING";
			}
			
			if(m_dwAttackSpeed + 500 < GetTickCount()) 
			{
				CDevice::GetInstance()->SoundPlay(6, 0);
				m_dwAttackSpeed = GetTickCount();
				if(iWeaponType==1) //기본탄
				{			
					m_pBullet->push_back(CFactory<CNomal>::CreateObj(m_tInfo.fX,m_tInfo.fY));
					((CNomal*)m_pBullet->back())->SetPlayer(this);
					((CNomal*)m_pBullet->back())->SetDir(m_iDIr);
					m_pBullet->back()->SetEffectList(m_EffectList);//이팩트
					
				}		
				
				if(iWeaponType==2 ) //탱탱
				{			
					if(iAmount1>0)
					{						
						m_pBullet->push_back(CFactory<CTangTang>::CreateObj(m_tInfo.fX,m_tInfo.fY));
						((CTangTang*)m_pBullet->back())->SetPlayer(this);
						((CTangTang*)m_pBullet->back())->SetDir(m_iDIr);
						((CGuied*)m_pBullet->back())->SetType(2);
						m_pBullet->back()->SetEffectList(m_EffectList);//이팩트
						iAmount1--;
						iTemp--;
					}
					else iWeaponType++;
					
				}
				if(iWeaponType==3 )//유도탄
				{
					if(iAmount2>0)
					{					
						m_pBullet->push_back(CFactory<CGuied>::CreateObj(m_tInfo.fX,m_tInfo.fY));
						((CGuied*)m_pBullet->back())->SetPlayer(this);
						((CGuied*)m_pBullet->back())->SetDir(m_iDIr);
						((CGuied*)m_pBullet->back())->SetType(3);
						m_pBullet->back()->SetEffectList(m_EffectList);//이팩트
						iAmount2--;
						iTemp3--;
					}
					else iWeaponType++;				

				}
				if(iWeaponType==4 ) //멀티
				{
					if(iAmount3>0)
					{
						m_pBullet->push_back(CFactory<CMulti>::CreateObj(m_tInfo.fX,m_tInfo.fY,DIR_UP));
						((CMulti*)m_pBullet->back())->SetPlayer(this);
						((CMulti*)m_pBullet->back())->SetDir(m_iDIr);
						m_pBullet->back()->SetEffectList(m_EffectList);//이팩트
						m_pBullet->push_back(CFactory<CMulti>::CreateObj(m_tInfo.fX,m_tInfo.fY,DIR_LU));
						((CMulti*)m_pBullet->back())->SetPlayer(this);
						((CMulti*)m_pBullet->back())->SetDir(m_iDIr);
						m_pBullet->back()->SetEffectList(m_EffectList);//이팩트
						m_pBullet->push_back(CFactory<CMulti>::CreateObj(m_tInfo.fX,m_tInfo.fY,DIR_RU));
						((CMulti*)m_pBullet->back())->SetPlayer(this);
						((CMulti*)m_pBullet->back())->SetDir(m_iDIr);
						m_pBullet->back()->SetEffectList(m_EffectList);//이팩트
 						iAmount3--;
						iTemp5--;
					}
					else iWeaponType++;

					if(iWeaponType>4) iWeaponType=1;
					

				}
			}
			ItemCount();
		
	}
	if(    ( m_dwKey & KEY_CONTROAL)  &&  (m_dwKey & KEY_DOWN)  )
	{
		
		m_bChange =1;					
		bSliding = 1;
		CDevice::GetInstance()->SoundPlay(13, 0);
		if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
		{	

			m_strKey = "Player_RIGHTSLIDING";
		}
		else m_strKey = "Player_LEFTSLIDING";
	}

	if( ( m_dwKey & KEY_CONTROAL)  &&  !(m_dwKey & KEY_DOWN )  )
	{
		if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
		{	
			m_strKey = "Player_RIGHTJUMP";			
		}
		else
		{							
				m_strKey = "Player_LEFTJUMP";
		}
	}

	if(!m_dwKey)
	{	
			if( ( m_iDIr%2 ) == 1)  //m_iDIr =1,3,5는 오른쪽
				m_strKey = "Player_RIGHTSTAND";
			else 
				m_strKey = "Player_LEFTSTAND";
			if(  (!m_bOnGround) && m_fSpeedY >= 0)	
			{			
				m_strKey = "Player_FALLING";
				
			}
	}
	if(!m_bOnGround && ( m_dwKey & KEY_DOWN ) && bSliding==0 )
	{
		
		m_strKey = "Player_POUND";
		m_tInfo.fY +=0;
		m_fSpeedY=0;
		m_fPoundingSpeed=0;
		m_bChange =1;
		bPounding=1;
	}	

	//0서서오 /1서서왼 2/위오른 3/위왼 4/오른아래 5/왼아래 6/
	/*if(b_right)
	{
		if(b_up)	iDir=2;
		else if(b_down) iDir = 4;
		else iDir=0;
	}
	if(b_left)
	{
		if(b_up) iDir=3;
		else if(b_down)	iDir = 5;
		else iDir=1;
	}
	*/
	


}	

void CPlayer::SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime)
{
	
	if(m_dwState & dwState)
	{
		if(m_tFrame.iScene != iScene)
			m_tFrame.iStart = 0;

		m_tFrame.iLast = iLast;
		m_tFrame.iScene = iScene;
		m_tFrame.dwTime = dwTime;
	}
	
	
}

void CPlayer::ScrollX(void)
{
	// 좌측 끝
	if(m_tInfo.fX < m_ptOffset.x)
	{
		if(m_ptScroll.x > 0 - m_fSpeed)
		{
			if(m_tInfo.fX < 0)
				m_tInfo.fX = 0.f;

			return;
		}

		m_ptScroll.x += (long)m_fSpeed;
		m_ptOffset.x -= (long)m_fSpeed;
	}

	// 우측 끝
	if(m_tInfo.fX > m_ptOffset.x)
	{
		if(m_ptScroll.x < WINCX - 3432.f + m_fSpeed)
		{
			if(m_tInfo.fX > 3432.f)
				m_tInfo.fX = 3432.f;

			return;
		}

		m_ptScroll.x -= (long)m_fSpeed;
		m_ptOffset.x += (long)m_fSpeed;
	}
}

void CPlayer::ScrollY(void)
{
	// 상단 끝
	if(m_tInfo.fY < m_ptOffset.y)
	{
		if(m_ptScroll.y > 0 - m_fSpeed)
		{
			if(m_tInfo.fY < 0)
				m_tInfo.fY = 0.f;

			return;
		}

		m_ptScroll.y += (long)m_fSpeed;
		m_ptOffset.y -= (long)m_fSpeed;
	}

	// 하단 끝
	if(m_tInfo.fY > m_ptOffset.y)
	{
		if(m_ptScroll.y < WINCY - 1528.f + m_fSpeed)
		{
			if(m_tInfo.fY > 1528.f)
				m_tInfo.fY = 1528.f;

			return;
		}

		m_ptScroll.y -= (long)m_fSpeed;
		m_ptOffset.y += (long)m_fSpeed;
	}
}

void CPlayer::Render(HDC hdc)
{
	
		TransparentBlt(hdc, 
			int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
			int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
			int(m_tInfo.fCX), int(m_tInfo.fCY)
			, (*m_pBitMap)[m_strKey]->GetMemDC(),
			int(m_tInfo.fCX * m_tFrame.iStart), 
			int(m_tInfo.fCY * m_tFrame.iScene), 
			(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
			RGB(32, 96, 128));


		//얼굴탄생
		TransparentBlt(hdc, 
			40,550,
			38,41, (*m_pBitMap)["Face"]->GetMemDC(),
			0, 
			0, 
			38, 41, 
			RGB(32, 96, 128));
			//X
		TransparentBlt(hdc, 
				70,570,
				29,31, (*m_pBitMap)["x"]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));
		//무한
		TransparentBlt(hdc, 
				90,568,
				29,31, (*m_pBitMap)["infinity"]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));
		//무기
		//X
		TransparentBlt(hdc, 
				660,570,
				29,31, (*m_pBitMap)["x"]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));
		//무한
		if(iWeaponType==1)
		{
		TransparentBlt(hdc, 
				680,568,
				29,31, (*m_pBitMap)["infinity"]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));
		}
		else if(iWeaponType==2)
		{
			TransparentBlt(hdc, 
			680,568,
			29,31, (*m_pBitMap)[strAmor2]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
			TransparentBlt(hdc, 
			700,568,
			29,31, (*m_pBitMap)[strAmor1]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		

		}
		else if(iWeaponType==3)
		{
		TransparentBlt(hdc, 
				680,568,
				29,31, (*m_pBitMap)[strAmor4]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));
		TransparentBlt(hdc, 
				700,568,
				29,31, (*m_pBitMap)[strAmor3]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));

		}
		else if(iWeaponType==4)
		{
		TransparentBlt(hdc, 
				680,568,
				29,31, (*m_pBitMap)[strAmor6]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));
		TransparentBlt(hdc, 
				700,568,
				29,31, (*m_pBitMap)[strAmor5]->GetMemDC(),
				0, 
				0, 
				29, 31, 
				RGB(150, 150, 150));

		}


		if( iWeaponType==1)
		{
			TransparentBlt(hdc, 
				640,570,
				19,21, (*m_pBitMap)["Weapon1"]->GetMemDC(),
				0, 
				0, 
				19, 21, 
				RGB(150, 150, 150));
		}
		if( iWeaponType==2)
		{
			TransparentBlt(hdc, 
				640,570,
				16,13, (*m_pBitMap)["Weapon2"]->GetMemDC(),
				0, 
				0, 
				16, 13, 
				RGB(150, 150, 150));
		}

		if( iWeaponType==3)
		{
			TransparentBlt(hdc, 
				640,570,
				22,22, (*m_pBitMap)["Weapon3"]->GetMemDC(),
				0, 
				0, 
				22, 22, 
				RGB(150, 150, 150));
		}
		if( iWeaponType==4)
		{
			TransparentBlt(hdc, 
				640,570,
				21,17, (*m_pBitMap)["Weapon4"]->GetMemDC(),
				0, 
				0, 
				21, 17, 
				RGB(150, 150, 150));
		}
		
		if(m_tInfo.iHp>4)
		{
			TransparentBlt(hdc, 
				760,40,
				15,12, (*m_pBitMap)["life"]->GetMemDC(),
				0, 
				0, 
				15, 12, 
				RGB(150, 150, 150));
		}
		if(m_tInfo.iHp>3)
		{
			TransparentBlt(hdc, 
				740,40,
				15,12, (*m_pBitMap)["life"]->GetMemDC(),
				0, 
				0, 
				15, 12, 
				RGB(150, 150, 150));
		}
		if(m_tInfo.iHp>2)
		{
			TransparentBlt(hdc, 
				720,40,
				15,12, (*m_pBitMap)["life"]->GetMemDC(),
				0, 
				0, 
				15, 12, 
				RGB(150, 150, 150));
		}
		if(m_tInfo.iHp>1)
		{
			TransparentBlt(hdc, 
				700,40,
				15,12, (*m_pBitMap)["life"]->GetMemDC(),
				0, 
				0, 
				15, 12, 
				RGB(150, 150, 150));
		}
		if(m_tInfo.iHp>0)
		{
			TransparentBlt(hdc, 
				680,40,
				15,12, (*m_pBitMap)["life"]->GetMemDC(),
				0, 
				0, 
				15, 12, 
				RGB(150, 150, 150));
		}
	
}

void CPlayer::Release(void)
{
	
}


void CPlayer::SetBullet(list<CObj*>* _pBullet)
{
	m_pBullet = _pBullet;
}
int CPlayer::GetSpecialMov()
{
	if(bSliding) iSpecialMov=1;
	else if(bPounding) iSpecialMov=2;
	else iSpecialMov=0;

	return iSpecialMov;
}

void CPlayer::Death(float _X,float _Y)
{
	m_dwState= ST_DEATH;
	m_strKey = "Player_DEATH";	
	bDeath=1;

	if(m_dwTime4 + 6000 < GetTickCount())
	{
		m_dwTime4 = GetTickCount();
		SetPos(150,150);
		bDeath=0;

	}
}

DWORD CPlayer::GetTime3()
{
	return m_dwTime3;
}

void CPlayer::ItemCount()
{	
	 iTemp =iAmount1 %10;
	iTemp2 =iAmount1 /10 ;
	iTemp3 =iAmount2 %10 ;
	iTemp4 =iAmount2 /10 ;
	iTemp5 =iAmount3 %10 ;
	iTemp6 =iAmount3 /10 ;

		switch(iTemp2)
		{
		case 1: 
			strAmor2 = "1";
			break;
		case 2: 
			strAmor2 = "2";
			break;
		case 3: 
			strAmor2 = "3";
			break;
		case 4: 
			strAmor2 = "4";
			break;
		case 5: 
			strAmor2 = "5";
			break;
		case 6: 
			strAmor2 = "6";
			break;
		case 7: 
			strAmor2 = "7";
			break;
		case 8: 
			strAmor2 = "8";
			break;
		case 9: 
			strAmor2 = "9";
			break;
		case 0: 
			strAmor2 = "0";
			break;
		}
		switch(iTemp)
		{
			case 1: 
				strAmor1 = "1";
				break;
			case 2: 
				strAmor1 = "2";
				break;
			case 3: 
				strAmor1 = "3";
				break;
			case 4: 
				strAmor1 = "4";
				break;
			case 5: 
				strAmor1 = "5";
				break;
			case 6: 
				strAmor1 = "6";
				break;
			case 7: 
				strAmor1 = "7";
				break;
			case 8: 
				strAmor1 = "8";
				break;
			case 9: 
				strAmor1 = "9";
				break;
			case 0: 
				strAmor1 = "0";
				break;
		}

  

 
		

		
			switch(iTemp4)
		{
			case 1: 
				strAmor4 = "1";
				break;
			case 2: 
				strAmor4 = "2";
				break;
			case 3: 
				strAmor4 = "3";
				break;
			case 4: 
				strAmor4 = "4";
				break;
			case 5: 
				strAmor4 = "5";
				break;
			case 6: 
				strAmor4 = "6";
				break;
			case 7: 
				strAmor4 = "7";
				break;
			case 8: 
				strAmor4 = "8";
				break;
			case 9: 
				strAmor4 = "9";
				break;
			case 0: 
				strAmor4 = "0";
				break;
		}
		switch(iTemp3)
		{
			case 1: 
				strAmor3 = "1";
				break;
			case 2: 
				strAmor3 = "2";
				break;
			case 3: 
				strAmor3 = "3";
				break;
			case 4: 
				strAmor3 = "4";
				break;
			case 5: 
				strAmor3 = "5";
				break;
			case 6: 
				strAmor3 = "6";
				break;
			case 7: 
				strAmor3 = "7";
				break;
			case 8: 
				strAmor3 = "8";
				break;
			case 9: 
				strAmor3 = "9";
				break;
			case 0: 
				strAmor3 = "0";
				break;
		}

  
	

		
			switch(iTemp6)
		{
			case 1: 
				strAmor6 = "1";
				break;
			case 2: 
				strAmor6 = "2";
				break;
			case 3: 
				strAmor6 = "3";
				break;
			case 4: 
				strAmor6 = "4";
				break;
			case 5: 
				strAmor6 = "5";
				break;
			case 6: 
				strAmor6 = "6";
				break;
			case 7: 
				strAmor6 = "7";
				break;
			case 8: 
				strAmor6 = "8";
				break;
			case 9: 
				strAmor6 = "9";
				break;
			case 0: 
				strAmor6 = "0";
				break;
		}
		switch(iTemp5)
		{
			case 1: 
				strAmor5 = "1";
				break;
			case 2: 
				strAmor5 = "2";
				break;
			case 3: 
				strAmor5 = "3";
				break;
			case 4: 
				strAmor5 = "4";
				break;
			case 5: 
				strAmor5 = "5";
				break;
			case 6: 
				strAmor5 = "6";
				break;
			case 7: 
				strAmor5 = "7";
				break;
			case 8: 
				strAmor5 = "8";
				break;
			case 9: 
				strAmor5 = "9";
				break;
			case 0: 
				strAmor5 = "0";
				break;
		}

  
	
	

}