#include "StdAfx.h"
#include "Stage.h"
#include "Player.h"
#include "Factory.h"
#include "Back.h"
#include "ObjMgr.h"
#include "Monster.h"
#include "RenderMgr.h"
#include "CollisionMgr.h"
#include "Lizard.h"
#include "Bullet_Effect1.h"
#include "item.h"
#include "turtle.h"
#include "Devil.h"
#include "score.h"
#include "device.h"
#include "SceneMgr.h"

CStage::CStage(void)
:m_MobTime(GetTickCount())
{
}

CStage::~CStage(void)
{
	Release();
}

void CStage::Initialize(void)
{
	
	
	//배경
	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/back.bmp");
	m_BitMap["stage"] = (new CBitBmp)->LoadBmp(L"../Texture/map.bmp");
	//서있는 동작
	m_BitMap["Player_RIGHTSTAND"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/stand.bmp");
	m_BitMap["Player_LEFTSTAND"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/stand2.bmp");
	//방향별 움직임
	m_BitMap["Player_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/walking2.bmp");
	m_BitMap["Player_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/walking.bmp");
	m_BitMap["Player_RIGHTUP"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/LookingUp.bmp");
	m_BitMap["Player_LEFTUP"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/LookingUp2.bmp");
	m_BitMap["Player_RIGHTDOWN"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/sit.bmp");
	m_BitMap["Player_LEFTDOWN"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/sit2.bmp");
	//공격
	m_BitMap["Player_RIGHTATTACK"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/shoot.bmp");
	m_BitMap["Player_LEFTATTACK"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/shoot2.bmp");
	m_BitMap["Player_RIGHTUPSHOOT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/LookingUpShoot.bmp");
	m_BitMap["Player_LEFTUPSHOOT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/LookingUpShoot2.bmp");
	m_BitMap["Player_RIGHTSITSHOOT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/SitShoot.bmp");
	m_BitMap["Player_LEFTSITSHOOT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/SitShoot2.bmp");
	//점프관련동작
	m_BitMap["Player_FALLING"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/falling.bmp");
	m_BitMap["Player_POUND"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/GroundPound.bmp");
	m_BitMap["Player_RIGHTJUMP"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/jump.bmp");
	m_BitMap["Player_LEFTJUMP"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/jump2.bmp");
	m_BitMap["Player_RIGHTLAND"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/Land.bmp");
	m_BitMap["Player_LEFTLAND"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/Land2.bmp");

	//다침
	m_BitMap["Player_HURT"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/Hurt.bmp");
	m_BitMap["Player_DEATH"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/death.bmp");
	//달리기				
	m_BitMap["Player_RIGHTRUNNING"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/running.bmp");
	m_BitMap["Player_LEFTRUNNING"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/running2.bmp");
	//슬라이딩
	m_BitMap["Player_RIGHTSLIDING"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/sliding.bmp");
	m_BitMap["Player_LEFTSLIDING"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/sliding2.bmp");
	//UI
	m_BitMap["Face"] = (new CBitBmp)->LoadBmp(L"../Texture/spaz/face.bmp");//38x41
	//무기그림
	m_BitMap["Weapon1"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/gun2.bmp");
	m_BitMap["Weapon2"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/tangtang.bmp");
	m_BitMap["Weapon3"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/guied.bmp");
	m_BitMap["Weapon4"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/multi.bmp");
	//기본불렛 
	m_BitMap["Nomal"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/nomal.bmp");
	m_BitMap["Nomal_up"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/nomal-up.bmp");
	//유도탄
	m_BitMap["Guied_right"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/guied_right.bmp");
	m_BitMap["Guied_down"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/Guied_down.bmp");
	m_BitMap["Guied_left"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/Guied_left.bmp");
	m_BitMap["Guied_up"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/guied_up.bmp");
	//탱탱볼
	m_BitMap["tangtang"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/tangtang.bmp");
	//멀티탄
	m_BitMap["multi-right"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/multi-right.bmp");
	m_BitMap["multi-up"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/multi-up.bmp");
	m_BitMap["multi-left"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/multi-left.bmp");
	//불렛이팩트
	m_BitMap["effect1"] = (new CBitBmp)->LoadBmp(L"../Texture/item/effect/effect1.bmp");
	m_BitMap["effect2"] = (new CBitBmp)->LoadBmp(L"../Texture/item/effect/effect2.bmp");
	m_BitMap["effect3"] = (new CBitBmp)->LoadBmp(L"../Texture/item/effect/effect3.bmp");
	//하트
	m_BitMap["life"] = (new CBitBmp)->LoadBmp(L"../Texture/item/life.bmp");
	//당근
	//m_BitMap["carrot"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/carriot.bmp");
	//x ,무한
	m_BitMap["x"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/x.bmp");
	m_BitMap["infinity"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/infinity.bmp");

	m_BitMap["lizard"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/lizard 75 55.bmp");
	m_BitMap["mogi"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/mogi 41 30.bmp");
	m_BitMap["turtle"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/turtle.bmp");	
	m_BitMap["lizard1"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/lizard 75 551.bmp");
	m_BitMap["mogi1"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/mogi 41 301.bmp");
	m_BitMap["turtle1"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/turtle1.bmp");
	m_BitMap["devil"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/devel.bmp");
	m_BitMap["devil1"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/devel1.bmp");

	//무기박스
	m_BitMap["TangBox"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/tangtangup.bmp");
	m_BitMap["GuiedBox"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/guiedup.bmp");
	m_BitMap["mulBox"] = (new CBitBmp)->LoadBmp(L"../Texture/item/weapon/multiup.bmp");

	//숫자
	m_BitMap["1"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/1.bmp");
	m_BitMap["2"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/2.bmp");
	m_BitMap["3"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/3.bmp");
	m_BitMap["4"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/4.bmp");
	m_BitMap["5"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/5.bmp");
	m_BitMap["6"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/6.bmp");
	m_BitMap["7"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/7.bmp");
	m_BitMap["8"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/8.bmp");
	m_BitMap["9"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/9.bmp");	
	m_BitMap["0"] = (new CBitBmp)->LoadBmp(L"../Texture/item/number/0.bmp");


	// 사운드 파일 추가

	// 사운드 파일


	CDevice::GetInstance()->SoundStop(0);
	// 사운드 재생
	CDevice::GetInstance()->SoundPlay(1, 1);

	m_pBack = CFactory<CBack>::CreateObj();

	
	m_ObjList[OBJ_PLAYER].push_back(CFactory<CPlayer>::CreateObj());
	((CPlayer*)m_ObjList[OBJ_PLAYER].back())->SetBullet(&m_ObjList[OBJ_BULLET]);
	((CPlayer*)m_ObjList[OBJ_PLAYER].back())->SetEffectList(&m_ObjList[OBJ_EFFECT]);
	

	m_ObjList[OBJ_SCORE].push_back(CFactory<CScore>::CreateObj());
	

	//이팩특

	//몹생성

	

	 m_MobTime = GetTickCount();
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(600),float(150)));

	m_ObjList[OBJ_MONSTER].push_back(CFactory<CDevil>::CreateObj(float(550),float(645)));

	
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(1450),float(165)));

	//
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(1100),float(1035)));		
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(1200),float(1035)));	

	m_ObjList[OBJ_MONSTER].push_back(CFactory<CDevil>::CreateObj(float(1350),float(1035)));
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CDevil>::CreateObj(float(1150),float(750)));
	//	
	

	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(3000),float(400)));	

	m_ObjList[OBJ_MONSTER].push_back(CFactory<CTurtle>::CreateObj(float(2550),float(1200)));
	

	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(2550),float(1200)));
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(2450),float(1180)));
	m_ObjList[OBJ_MONSTER].push_back(CFactory<CTurtle>::CreateObj(float(3000),float(400)));




	m_ObjList[OBJ_ITEM].push_back(CFactory<CItem>::CreateObj(float(300),float(175),2));
	((CItem*)m_ObjList->back())->SetType(1);

	m_ObjList[OBJ_ITEM].push_back(CFactory<CItem>::CreateObj(float(1450),float(500),1));
	((CItem*)m_ObjList->back())->SetType(2);

	m_ObjList[OBJ_ITEM].push_back(CFactory<CItem>::CreateObj(float(200),float(660),3));
	((CItem*)m_ObjList->back())->SetType(3);

	LoadMap();

	CObjMgr::GetInst()->SetObjList(m_ObjList);
	CObj::SetBitMap(&m_BitMap);




}
void CStage::SaveScore()
{
	int _point = 	((CScore*)m_ObjList->back())->GetScorePoint() ;

	HANDLE		 hFile = NULL;
	DWORD		dwByte= 0;

	hFile  =  CreateFile(L"../Data/score.txt",
						GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);

	
	
		WriteFile(hFile,&_point,sizeof(int),&dwByte,NULL);
	
	CloseHandle(hFile);


}

int CStage::Progress(void)
{
	if(m_MobTime + 40000 < GetTickCount())
	{

		 m_MobTime = GetTickCount();
		m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(600),float(150)));

		m_ObjList[OBJ_MONSTER].push_back(CFactory<CDevil>::CreateObj(float(550),float(645)));

		
		m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(1450),float(165)));

		//
		m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(1100),float(1035)));		
		m_ObjList[OBJ_MONSTER].push_back(CFactory<CLizard>::CreateObj(float(1200),float(1035)));	

		m_ObjList[OBJ_MONSTER].push_back(CFactory<CDevil>::CreateObj(float(1350),float(1035)));
		m_ObjList[OBJ_MONSTER].push_back(CFactory<CDevil>::CreateObj(float(1150),float(750)));
		//	
	}
	if(GetAsyncKeyState(VK_F12))
		CDevice::GetInstance()->SoundStop(1);
	if(GetAsyncKeyState(VK_F11))
		CDevice::GetInstance()->SoundPlay(1,1);

 	if( (m_ObjList[OBJ_PLAYER].back()->GetInfo().fX>=2880.f ))
	{
		
		SaveScore();
		Release();
		exit(1);
		//CSceneMgr::GetInst()->SetScene(SC_STAGE2);
		
		
		return 0;
	}
	CCollisionMgr::CollisionLineToPlayer(&m_ObjList[OBJ_PLAYER],&m_Line);	
	CCollisionMgr::CollisionRangeOfBullet(&m_ObjList[OBJ_BULLET],&m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::CollisionBulletToMonster(&m_ObjList[OBJ_BULLET],&m_ObjList[OBJ_MONSTER],&m_ObjList[OBJ_SCORE]);
	CCollisionMgr::CollisionPlayerToMonster(&m_ObjList[OBJ_PLAYER],&m_ObjList[OBJ_MONSTER],&m_ObjList[OBJ_SCORE]);
	CCollisionMgr::CollisionBulletToLine(&m_ObjList[OBJ_BULLET],&m_Line);
	CCollisionMgr::CollisionPlayerToItem(&m_ObjList[OBJ_PLAYER],&m_ObjList[OBJ_ITEM]);
	CCollisionMgr::CollisionLineToMonster(&m_ObjList[OBJ_MONSTER],&m_Line);

	iItem=CCollisionMgr::CollisionItem3(&m_ObjList[OBJ_BULLET], &m_ObjList[OBJ_ITEM],&m_ObjList[OBJ_SCORE]);

	switch(iItem)
	{
		
	case 1:
		{
			((CPlayer*)m_ObjList[OBJ_PLAYER].back())->SetAmount1(30);
			break;
		}
	case 2:
		{
			((CPlayer*)m_ObjList[OBJ_PLAYER].back())->SetAmount2(30);
			break;
		}
	case 3:
		{
			((CPlayer*)m_ObjList[OBJ_PLAYER].back())->SetAmount3(30);
			break;
		}
	}


	m_pBack->Progress();

	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			if(i == OBJ_EFFECT)
			{
				if(((CBullet_Effect1*)(*iter))->GetTime() + 800 < GetTickCount())
				{
  					::Safe_Delete(*iter);
					iter = m_ObjList[i].erase(iter);

					if(iter == m_ObjList[i].end())
						break;
				}
			}
			
			(*iter)->Progress();

			CRenderMgr::GetInst()->AddObject(*iter);
		}
	}

	CCollisionMgr::CollisionLineToPlayer(&m_ObjList[OBJ_PLAYER],&m_Line);	

	return 0;
}

void CStage::Render(HDC hdc)
{



	m_pBack->Render(m_BitMap["back"]->GetMemDC());

	/*for(size_t i = 0; i < OBJ_END; ++i)
	{
	for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
	iter !=	m_ObjList[i].end(); ++iter)
	{
	(*iter)->Render(m_BitMap["back"]->GetMemDC());
	}
	}*/

	CRenderMgr::GetInst()->RenderObj(m_BitMap["back"]->GetMemDC());



	BitBlt(hdc, 
		0, 0, 
		WINCX,
		WINCY, 
		m_BitMap["back"]->GetMemDC(), 
		0, 0, SRCCOPY);
	/*
	TransparentBlt(hdc, 
	0,
	0,
	WINCX, WINCY
	, m_BitMap["back"]->GetMemDC(),
	0, 0, 
	WINCX, WINCY, 
	RGB(72, 68, 168));*/



	CRenderMgr::GetInst()->ObjClear();
}

void CStage::Release(void)
{
	::Safe_Delete(m_pBack);

	for(size_t i = 1; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			::Safe_Delete(*iter);
		}
		m_ObjList[i].clear();
	}

	for(list<CObj*>::iterator	iter = m_ObjList[OBJ_EFFECT].begin();
		iter !=	m_ObjList[OBJ_EFFECT].end(); ++iter)
	{
		::Safe_Delete(*iter);
	}
	m_ObjList[OBJ_EFFECT].clear();

	for(vector<TILE*>::iterator	iter = m_Line.begin();
		iter !=	m_Line.end(); ++iter)
	{
		::Safe_Delete(*iter);
	}
	m_Line.clear();

}

void CStage::LoadMap(void)
{
	
	HANDLE		hFile = NULL;
	DWORD		dwByte = 0;

	hFile = CreateFile(L"../Data/TileMap.dat", 
		GENERIC_READ, 
		0, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL);

	while(true)
	{
		TILE*		pTILE = new TILE;

		ReadFile(hFile, pTILE, sizeof(TILE), &dwByte, NULL);

		if(dwByte == 0)
		{
			::Safe_Delete(pTILE);
			break;
		}

		m_Line.push_back(pTILE);


	}

	CloseHandle(hFile);

}