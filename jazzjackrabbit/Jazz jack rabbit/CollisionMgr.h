#pragma once

#include "obj.h"

class CCollisionMgr
{
public:
	static void CollisionLineToPlayer(list<CObj*>* pObj, vector<TILE*> *pObj2);
	static void CollisionRangeOfBullet(list<CObj*>* pBullet, list<CObj*>* pPlayer);
	static void CollisionBulletToMonster(list<CObj*>* pBullet, list<CObj*>* pMonster, list<CObj*>* pScore);
	static void CollisionPlayerToMonster(list<CObj*>* pPlayer, list<CObj*>* pMonsterr, list<CObj*>* pScore);
	static void CollisionBulletToLine(list<CObj*>* pObj, vector<TILE*> *pObj2);

	static void CollisionLineToMonster(list<CObj*>* pObj, vector<TILE*> *pObj2);


	static void CollisionPlayerToItem(list<CObj*>* pPlayer, list<CObj*>* pObj);
	
	

	static int CollisionItem3(list<CObj*>* _pBullet, list<CObj*>* _pObjr, list<CObj*>* pScore);
public:
	CCollisionMgr(void);
	~CCollisionMgr(void);
};
