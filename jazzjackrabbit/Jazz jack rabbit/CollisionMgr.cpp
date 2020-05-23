#include "StdAfx.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "TangTang.h"
#include "Guied.h"
#include "score.h"
#include "device.h"


CCollisionMgr::CCollisionMgr(void )
{
}

CCollisionMgr::~CCollisionMgr(void)
{
}
void CCollisionMgr::CollisionLineToPlayer(list<CObj*>* pObj, vector<TILE*>* pObj2)
{
	RECT rc;
	//bool bCheck = false;

	//�÷��̾� ũ�� 50x 50   ĭũ�� 32x32
	for(list<CObj*>::iterator iter = pObj->begin(); iter != pObj->end(); ++iter)
	{
		for(int i = 0 ; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				int iCullX =  (int) ( (*iter)->GetInfo().fX ) / TILECX;
				int iCullY =	 (int) ( (*iter)->GetInfo().fY )/ TILECY;				
				int iIndex  =  (int)( (i + iCullY - 1) * TILEX + (j + iCullX - 1) );				
	
				if(i + iCullY - 1 < 0)
					continue;
				HDC hdc = GetDC(g_hWnd);	

				if(((*pObj2)[iIndex])->iOption == 0)
				{
				}
				else
				{
				//	TextOut(hdc, (iCullX +j-1) * TILECX + (*iter)->GetScrollX() , (iCullY+i-1)*TILECY + (*iter)->GetScrollY() ,L"X",1);
				}
				ReleaseDC(g_hWnd,hdc);		
				IntersectRect(&rc, &(*iter)->GetRect(), &((*pObj2)[iIndex])->GetRect());

				LONG fLength = rc.right - rc.left;
				LONG fHeight = rc.bottom - rc.top;			

				if (fLength > fHeight)			//�����浹
				{			

					if (rc.top <= ((*pObj2)[iIndex])->GetRect().top && ((*pObj2)[iIndex])->iOption == 2)		//��
					{
						for(double i = -25 ; i< 25 ; i+=0.0001)
						{
							(*iter)->SetOnGround(1);
							(*iter)->SetDoubleJump();
							(*iter)->SetPos( (*iter)->GetInfo().fX, float(rc.top+i));
							break;
						}
					}

					 if (rc.top <= ((*pObj2)[iIndex])->GetRect().top && ((*pObj2)[iIndex])->iOption == 4)	//���浹
					{
						(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-25));				
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);
						(*iter)->SetDoubleJump();
					}

					 if (rc.top <= ((*pObj2)[iIndex])->GetRect().top && ((*pObj2)[iIndex])->iOption == 3)	//���浹
					{
						(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-25));				
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);
						(*iter)->SetDoubleJump();
					}

					if (rc.bottom >= ((*pObj2)[iIndex])->GetRect().bottom && ((*pObj2)[iIndex])->iOption == 3)	//���浹
					{						
						(*iter)->SetPos((*iter)->GetInfo().fX, (*iter)->GetInfo().fY);
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(false);
					
					}

					if (rc.bottom >= ((*pObj2)[iIndex])->GetRect().bottom && ((*pObj2)[iIndex])->iOption == 4)	//���浹
					{						
						(*iter )->SetPos((*iter)->GetInfo().fX, (*iter)->GetInfo().fY);
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);			
					}					
				}

				else if (fLength < fHeight)		//�¿��浹
				{
					if (rc.left <= ((*pObj2)[iIndex])->GetRect().left&& ((*pObj2)[iIndex])->iOption == 2)		// ���浹
					{
						for(double i = -25 ; i< 25 ; i+=0.0001)
						{
							(*iter)->SetOnGround(1);
							(*iter)->SetDoubleJump();
							(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top+i));
							break;
						}
					}
					if (rc.right >= ((*pObj2)[iIndex])->GetRect().right && ((*pObj2)[iIndex])->iOption == 2)		// ���浹
					{
						for(double i = -25 ; i< 25 ;i+=0.0001)
						{
							(*iter)->SetOnGround(1);
							(*iter)->SetDoubleJump();
							(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top+i));
							break;
						}
					}
					if (rc.left <= ((*pObj2)[iIndex])->GetRect().left && ((*pObj2)[iIndex])->iOption == 4)		// ���浹
					{
						(*iter)->SetPos(float(rc.left), ((*pObj2)[iIndex])->fY);
						(*iter)->SetOnGround(1);
					}
				
					if (rc.left <= ((*pObj2)[iIndex])->GetRect().left && ((*pObj2)[iIndex])->iOption == 3)		// ���浹
					{
						(*iter)->SetPos(float(rc.left-25), (*iter)->GetInfo().fY);
					}
					
					if (rc.right >= ((*pObj2)[iIndex])->GetRect().right &&((*pObj2)[iIndex])->iOption == 3)		// ���浹
					{
						(*iter)->SetPos(float((rc.right-rc.left) + (*iter)->GetInfo().fX )  , (*iter)->GetInfo().fY);
					}
					
					if (rc.right >= ((*pObj2)[iIndex])->GetRect().right &&((*pObj2)[iIndex])->iOption == 4)		// ���浹
					{
						(*iter)->SetPos(float( (rc.right-rc.left) + (*iter)->GetInfo().fX )  , ((*pObj2)[iIndex])->fY);
					}
				}
			}
		}
	}
}

void CCollisionMgr::CollisionLineToMonster(list<CObj*>* pObj, vector<TILE*> *pObj2)
{
	RECT rc;
	//bool bCheck = false;

	//�÷��̾� ũ�� 50x 50   ĭũ�� 32x32
	for(list<CObj*>::iterator iter = pObj->begin(); iter != pObj->end(); ++iter)
	{
		for(int i = 0 ; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				int iCullX =  (int) ( (*iter)->GetInfo().fX ) / TILECX;
				int iCullY =	 (int) ( (*iter)->GetInfo().fY )/ TILECY;				
				int iIndex  =  (int)( (i + iCullY - 1) * TILEX + (j + iCullX - 1) );				
	
				if(i + iCullY - 1 < 0)
					continue;
				HDC hdc = GetDC(g_hWnd);	

				if(((*pObj2)[iIndex])->iOption == 0)
				{
				}
				else
				{
				//	TextOut(hdc, (iCullX +j-1) * TILECX + (*iter)->GetScrollX() , (iCullY+i-1)*TILECY + (*iter)->GetScrollY() ,L"X",1);
				}
				ReleaseDC(g_hWnd,hdc);		
				IntersectRect(&rc, &(*iter)->GetRect(), &((*pObj2)[iIndex])->GetRect());

				LONG fLength = rc.right - rc.left;
				LONG fHeight = rc.bottom - rc.top;			

				if (fLength > fHeight)			//�����浹
				{			

					if (rc.top <= ((*pObj2)[iIndex])->GetRect().top && ((*pObj2)[iIndex])->iOption == 2)		//��
					{
						for(double i = -25 ; i< 25 ; i+=0.0001)
						{
							(*iter)->SetOnGround(1);
							
							(*iter)->SetPos( (*iter)->GetInfo().fX, float(rc.top+i));
							break;
						}
					}

					 if (rc.top <= ((*pObj2)[iIndex])->GetRect().top && ((*pObj2)[iIndex])->iOption == 4)	//���浹
					{
						if((*iter)->GetInfo().fCX >60.f) (*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-32));	
						else (*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-25));	
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);
						
					}

					 if (rc.top <= ((*pObj2)[iIndex])->GetRect().top && ((*pObj2)[iIndex])->iOption == 3)	//���浹
					{
						if((*iter)->GetInfo().fCX >60.f) (*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-32));	
						else (*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-25));	
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);
						
					}

					if (rc.bottom >= ((*pObj2)[iIndex])->GetRect().bottom && ((*pObj2)[iIndex])->iOption == 3)	//���浹
					{						
						(*iter)->SetPos((*iter)->GetInfo().fX, (*iter)->GetInfo().fY);
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(false);
					
					}

					if (rc.bottom >= ((*pObj2)[iIndex])->GetRect().bottom && ((*pObj2)[iIndex])->iOption == 4)	//���浹
					{						
						(*iter )->SetPos((*iter)->GetInfo().fX, (*iter)->GetInfo().fY);
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);			
					}					
				}

				else if (fLength < fHeight)		//�¿��浹
				{
					if (rc.left <= ((*pObj2)[iIndex])->GetRect().left&& ((*pObj2)[iIndex])->iOption == 2)		// ���浹
					{
						for(double i = -25 ; i< 25 ; i+=0.0001)
						{
							(*iter)->SetOnGround(1);
							(*iter)->SetDoubleJump();
							(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top+i));
							break;
						}
					}
					if (rc.right >= ((*pObj2)[iIndex])->GetRect().right && ((*pObj2)[iIndex])->iOption == 2)		// ���浹
					{
						for(double i = -25 ; i< 25 ;i+=0.0001)
						{
							(*iter)->SetOnGround(1);
							(*iter)->SetDoubleJump();
							(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top+i));
							break;
						}
					}
					if (rc.left <= ((*pObj2)[iIndex])->GetRect().left && ((*pObj2)[iIndex])->iOption == 4)		// ���浹
					{
						(*iter)->SetPos(float(rc.left), ((*pObj2)[iIndex])->fY);
						(*iter)->SetOnGround(1);
					}
				
					if (rc.left <= ((*pObj2)[iIndex])->GetRect().left && ((*pObj2)[iIndex])->iOption == 3)		// ���浹
					{
						(*iter)->SetPos(float(rc.left-25), (*iter)->GetInfo().fY);
					}
					
					if (rc.right >= ((*pObj2)[iIndex])->GetRect().right &&((*pObj2)[iIndex])->iOption == 3)		// ���浹
					{
						(*iter)->SetPos(float((rc.right-rc.left) + (*iter)->GetInfo().fX )  , (*iter)->GetInfo().fY);
					}
					
					if (rc.right >= ((*pObj2)[iIndex])->GetRect().right &&((*pObj2)[iIndex])->iOption == 4)		// ���浹
					{
						(*iter)->SetPos(float( (rc.right-rc.left) + (*iter)->GetInfo().fX )  , ((*pObj2)[iIndex])->fY);
					}
				}
			}
		}
	}

}

void CCollisionMgr::CollisionBulletToLine(list<CObj*>* pObj, vector<TILE*> *pObj2)
{
	RECT rc;
	bool	bCheck = false;
	for(list<CObj*>::iterator iter = pObj->begin(); iter != pObj->end();  )
	{
		for(int i = 0 ; i < 10; ++i)
		{
			for(int j = 0; j < 10; ++j)
			{
				int iCullX =    (int)(  (*iter)->GetInfo().fX) / TILECX;
				int iCullY =	(int)(  (*iter)->GetInfo().fY) / TILECY;
				
				int iIndex  =  (int)( (i + iCullY - 1) * TILEX + (j + iCullX - 1) );				

				if(iIndex < 0 || iIndex >= TILEX * TILEY)
				break;
									
				if( ( IntersectRect( &rc, &(*iter)->GetRect(), &( (*pObj2)[iIndex])->GetRect() )) && ( ((*pObj2)[iIndex])->iOption !=0) )
				{							

					LONG fLength = rc.right - rc.left;        
					LONG fHeight = rc.bottom - rc.top;      

							
					if((*iter)->GetWeaponType()==2 &&( ((*pObj2)[iIndex])->iOption =3) )
					{

						bCheck = false;
						if (fLength > fHeight)			//�����浹
						{

							((CTangTang*)(*iter))->SetYS( (int)(       ((CTangTang*)(*iter))->GetYS() * (-1)));

						}
						if (fLength < fHeight)		//�¿��浹
						{							
								((CTangTang*)(*iter))->SetXS( (int)( ((CTangTang*)(*iter))->GetXS() * (-1)));						

						}						
					}
					else bCheck = true;		
				}			
			}
		}
		
		if(bCheck == true)
		{
			::Safe_Delete(*iter);
			iter = pObj->erase(iter);

		}
		else iter++;

	}


	//�ø��ȵȰ�
	/*RECT rc;
	for(list<CObj*>::iterator iter = pObj->begin(); iter != pObj->end(); ++iter)
	{
		for(vector<TILE*>::iterator iter2 = pObj2->begin(); iter2 != pObj2->end();)
		{

			if( (IntersectRect(&rc, &(*iter)->GetRect(), &((*iter2)->GetRect()))) && (*iter2)->iOption !=0 )
			{						
				::Safe_Delete(*iter);
				iter = pObj->erase(iter);
			}			
			else
			{
				++iter2;
			}				
			if(iter == pObj->end())
			{
				break;
			}
		}

		if(iter == pObj->end())
		{
			break;
		}

	}*/
	
}
 void CCollisionMgr::CollisionRangeOfBullet(list<CObj*>* pBullet, list<CObj*>* pPlayer)
{
	for(list<CObj*>::iterator iter = pBullet->begin(); iter != pBullet->end(); ++iter)
	{
		for(list<CObj*>::iterator iter2 = pPlayer->begin(); iter2 != pPlayer->end();)
		{
			

			if(((*iter)->GetInfo().fX >= (*iter2)->GetInfo().fX + 300))
			{		
				::Safe_Delete(*iter);
				iter = pBullet->erase(iter);
			}
			else if(((*iter)->GetInfo().fX <= (*iter2)->GetInfo().fX - 300))
			{		
				::Safe_Delete(*iter);
				iter = pBullet->erase(iter);
			}
			else if(((*iter)->GetInfo().fY <= (*iter2)->GetInfo().fY - 300))
			{		
				::Safe_Delete(*iter);
				iter = pBullet->erase(iter);
			}
			else if(((*iter)->GetInfo().fX <= 0.f))
			{
				::Safe_Delete(*iter);
				iter = pBullet->erase(iter);
			}
			else if(((*iter)->GetInfo().fY <= 0.f))
			{
				::Safe_Delete(*iter);
				iter = pBullet->erase(iter);
			}
			else
			{
				++iter2;
			}				
			if(iter == pBullet->end())
			{
				break;
			}
		}	

		if(iter == pBullet->end())
		{
			break;
		}

	}
}
 void CCollisionMgr::CollisionBulletToMonster(list<CObj*>* pBullet, list<CObj*>* pMonster, list<CObj*>* pScore)
 {
	 RECT rcCol;	
	 float posX = 0;
	 float posY = 0;
	 float Angle=0;

	for(list<CObj*>::iterator iter = pBullet->begin(); iter != pBullet->end(); )
	{
		for(list<CObj*>::iterator iter2 = pMonster->begin();
				iter2 != pMonster->end(); )
			{
				
				if((*iter)->GetWeaponType()==3)//�����̻��ϱ��
				{
					float	fWidth = (*iter2)->GetInfo().fX - (*iter)->GetInfo().fX;
					float	fHeight =  (*iter2)->GetInfo().fY -(*iter)->GetInfo().fY;
					float   fDistance = sqrtf(fWidth * fWidth + fHeight * fHeight);

					Angle = acosf(fWidth / fDistance) * 180.f / PI;

					Angle = acosf(fWidth / fDistance);

					if((*iter2)->GetInfo().fY > (*iter)->GetInfo().fY)
					{
						Angle = 2* PI - Angle;
					}

					posX = cosf(Angle);
					posY = sinf(Angle); 
					((CGuied*)(*iter))->SetXY(posX,posY);

				}
				
					if(IntersectRect(&rcCol,&((*iter)->GetRect()),&((*iter2)->GetRect())))
					{
						(*iter2)->SetHp((*iter2)->GetInfo().iHp - (*iter)->GetInfo().iAttack);

						if (rcCol.left <= (*iter2)->GetRect().left ) //�Ѿ˹��� ��->��
							(*iter2)->SetPos((*iter2)->GetInfo().fX+12.5f,(*iter2)->GetInfo().fY);//�ݵ�(���� ��->��)
						else 
							(*iter2)->SetPos((*iter2)->GetInfo().fX-12.5f,(*iter2)->GetInfo().fY);//�ݵ� (���� ��->��)
						if((*iter2)->GetInfo().iHp <= 0)
						{
       						((CScore*)pScore->back())->SetScore(100);
							::Safe_Delete(*iter2);
							iter2 = pMonster->erase(iter2);
						}
						
						::Safe_Delete(*iter);
						iter = pBullet->erase(iter);
					}
					
					if(iter == pBullet->end() || iter2 == pMonster->end())
					break;
					++iter2;	
			}
			
			if(iter == pBullet->end())
				break;
			++iter;	
		
	}

 }
 void CCollisionMgr::CollisionPlayerToMonster(list<CObj*>* pPlayer, list<CObj*>* pMonster, list<CObj*>* pScore)
 {
	 RECT rc;
	 

	for(list<CObj*>::iterator iter = pPlayer->begin(); iter != pPlayer->end(); ++iter)
	{
		for(list<CObj*>::iterator iter2 = pMonster->begin();
				iter2 != pMonster->end(); )
		{
				if(IntersectRect(&rc,&((*iter)->GetRect()),&((*iter2)->GetRect())))
				{
					
					LONG fLength = rc.right - rc.left;
					LONG fHeight = rc.bottom - rc.top;
					if( ((CPlayer*)(*iter))->GetHurt() == true )
					{
						
						if( ((CPlayer*)(*iter))->GetTime3() + 2000 <= GetTickCount()     )
						{
							((CPlayer*)(*iter))->SetTime(GetTickCount());
							((CPlayer*)(*iter))->SetHurt(0);
						}
							
					}
					if( ((CPlayer*)(*iter))->GetHurt() == false ) 
					{
						 if( ((CPlayer*)(*iter))->GetSpecialMov() ==0) //������
						{
							CDevice::GetInstance()->SoundPlay(9, 0);
							(*iter)->SetHp((*iter)->GetInfo().iHp - (*iter2)->GetInfo().iAttack);			
							(*iter)->SetPos((*iter)->GetInfo().fX-100.f,(*iter)->GetInfo().fY );
							((CPlayer*)(*iter))->SetHurt(1);
							
					
							if((*iter)->GetInfo().iHp <= 0)
							{
								((CPlayer*)(*iter))->Death((*iter)->GetInfo().fX,(*iter)->GetInfo().fY);
								(*iter)->SetHp(5);	//���¾߹���
							}								
						}
					}
					if( ((CPlayer*)(*iter))->GetSpecialMov() ==1) //��Ŭ 
					{
						CDevice::GetInstance()->SoundPlay(10, 0);
						if (fLength < fHeight)		//�¿��浹
						{
							if (rc.right >= (*iter2)->GetRect().right  || ((*iter)->GetDIRECTION() %2 ) == 0 ) //���ͱ��� ���浹
							{
								(*iter2)->SetHp((*iter2)->GetInfo().iHp - 2); //��Ŭ�������ϴ�2����
								
								if((*iter2)->GetInfo().iHp <= 0)
								{
									((CScore*)pScore->back())->SetScore(300);
									::Safe_Delete(*iter2);
									iter2 = pMonster->erase(iter2);
								
								}		
								
							}
							if (rc.left <= (*iter2)->GetRect().left  || ((*iter)->GetDIRECTION() %2 ) == 1 ) //���ͱ��� ���浹
							{
								(*iter2)->SetHp((*iter)->GetInfo().iHp - 2);
								
								if((*iter2)->GetInfo().iHp <= 0)
								{
									(*iter)->SetScore(300);
									::Safe_Delete(*iter2);
									iter2 = pMonster->erase(iter2);
								}		
							}
									
						}
						
					}
					else if( ((CPlayer*)(*iter))->GetSpecialMov() ==2) //�Ŀ��
					{
						CDevice::GetInstance()->SoundPlay(10, 0);
						if (fLength > fHeight)			//�����浹
						{
							if (rc.top <= ((*iter2))->GetRect().top)
							{			
								(*iter2)->SetHp((*iter2)->GetInfo().iHp - 2); //�Ŀ��������ũ��
								
								if((*iter2)->GetInfo().iHp <= 0)
								{
									((CScore*)pScore->back())->SetScore(300);
									::Safe_Delete(*iter2);
									iter2 = pMonster->erase(iter2);
								}										
								(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-120)); //�ݵ�
								(*iter)->SetSpeedY(0);
								(*iter)->SetOnGround(0);							
							}					
						}						
					}
					break;
				}
				
			if(iter == pPlayer->end() || iter2 == pMonster->end())
					break;
					++iter2;	
			}				
	}		
 }




int CCollisionMgr::CollisionItem3(list<CObj*>* _pBullet, list<CObj*>* _pObj, list<CObj*>* pScore)
{
	RECT rc;
	bool  Check = false;
	int	  iBox=0;

	for(list<CObj*>::iterator iter = _pBullet->begin(); iter != _pBullet->end();)
	{
		for(list<CObj*>::iterator iter2 = _pObj->begin();
				iter2 != _pObj->end(); )
		{
				if(IntersectRect(&rc,&((*iter)->GetRect()),&((*iter2)->GetRect())))
				{				
					if((*iter2)->GetItemType() == 1) iBox =1;
					else if((*iter2)->GetItemType() == 2) iBox =2;
					else if((*iter2)->GetItemType() == 3) iBox =3;
				
					((CScore*)pScore->back())->SetScore(1000);
					::Safe_Delete(*iter2);
					iter2 = _pObj->erase(iter2);
					::Safe_Delete(*iter);
					iter = _pBullet->erase(iter);	
					

					Check=1;
					
				}						
				
				if(iter == _pBullet->end() || iter2 == _pObj->end())
					break;
					++iter2;	
					
		}
		if(iter == _pBullet->end())
		break;
		++iter;	
		
					
	}
	if(Check==1)
	{
		CDevice::GetInstance()->SoundPlay(12, 0);
		if(iBox==1)	
			return 1;
		else if(iBox==2)	
			return 2;
		else if(iBox==3)	
			return 3; 
	}
	else 
	return 0;
}

void CCollisionMgr::CollisionPlayerToItem(list<CObj*>* pPlayer, list<CObj*>* pObj2)
{
	RECT rc;
	//bool bCheck = false;

	//�÷��̾� ũ�� 50x 50   ĭũ�� 32x32
	for(list<CObj*>::iterator iter = pPlayer->begin(); iter != pPlayer->end(); ++iter)
	{
			for(list<CObj*>::iterator iter2 = pObj2->begin(); iter2 != pObj2->end();++iter2)
			{

				IntersectRect(&rc, &(*iter)->GetRect(), &(*iter2)->GetRect());

				LONG fLength = rc.right - rc.left;
				LONG fHeight = rc.bottom - rc.top;			
				

				if (fLength > fHeight)			//�����浹
				{			
					 if (rc.top <= (*iter2)->GetRect().top )	//���浹
					{
						(*iter)->SetPos((*iter)->GetInfo().fX, float(rc.top-25));				
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(1);
						(*iter)->SetDoubleJump();
					
					}
				
					if (rc.bottom >= (*iter2)->GetRect().bottom )	//���浹
					{						
						(*iter)->SetPos((*iter)->GetInfo().fX, (*iter)->GetInfo().fY);
						(*iter)->SetSpeedY(0);
						(*iter)->SetOnGround(false);
					}			
				}
				else if (fLength < fHeight)		//�¿��浹
				{
					if (rc.left <= (*iter2)->GetRect().left )		// ���浹
					{
						(*iter)->SetPos(float(rc.left)-25.f, (*iter2)->GetInfo().fY);
						(*iter)->SetOnGround(1);
					}				
					
					if (rc.right >= (*iter2)->GetRect().right )		// ���浹
					{
						(*iter)->SetPos(float((rc.right-rc.left) + (*iter)->GetInfo().fX )  , (*iter)->GetInfo().fY);
					}	
					
					}
				
				}
			
			}	
	
}