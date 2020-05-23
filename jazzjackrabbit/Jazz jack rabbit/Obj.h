#pragma once

#include "Include.h"

class CBitBmp;
class CObj
{
protected:
	INFO		m_tInfo;
	float		m_fSpeed;
	int			m_iDIr;  // 1-서오 2-서왼 3-위오  4-위왼 5-아오 6-아왼
	string		m_strKey;
	int			m_iDrawID;
	static	map<string, CBitBmp*>*		m_pBitMap;
	static  POINT m_ptScroll;

	//
	CObj*		 m_TempObjptr;
	list<CObj*>* m_pBullet;
	list<CObj*>* m_pTempObjList;

	int					iWeaponType;//무기타입
	DIRECTION	m_eDir;

	//점프관련
	bool m_bOnGround;  //1=땅위 0-공중
	DWORD m_dwTime;
	bool	m_bDoubleJump;
	float		m_fSpeedX; //슬라이딩일듯아마
	float		m_fSpeedY;

	//변경변수(파운드,슬라이딩) 1일경우 아무키안먹힘 0일경우 키먹힘
	bool m_bChange;

	list<CObj*>* m_EffectList;//이팩트
	list<CObj*>* m_EffectList2;

	int m_iBox;//박스종류

		//총알 수량

	//float fGuidedX;
	//float fGuidedY;

	int iScorePoint;


	



public:
	void		SetJumpLimit(void);
	void		SetOnGround(bool _bOnGround);
	void		SetDoubleJump(void);
	void		SetAttack(int _iAttack);
	void		SetHp(int _iHp);
	void		SetSpeedY(float _SpeedY);

	void	SetEffectList(list<CObj*>* _pTempObjList);//이팩트
	void SetEffectList2(list<CObj*>* _pTempObjList);
	int		GetWeaponType();
	int     GetItemType();

	
	int GetBox();

//	void SetXY(float _x,float _y);	//유도탄
	void SetXS(int _xs);
	void SetYS(int _ys);
	float GetXS();
	float GetYS();
	
	int GetScore(void);
	void SetScore(int _iScorePoint);
	


		

	
	


public:
	static void SetBitMap(map<string, CBitBmp*>* pBitMap);
	void		SetDrawKey(string strKey);
//
	
	//

	void		SetBulletList(list<CObj*>* _pBullet);

	void		SetDirection(DIRECTION _eDir);
	void		SetBox(int _Box);

	
	


public:
	INFO		GetInfo(void);
	void		SetPos(float _fX, float _fY);
	RECT		GetRect(void);
	DIRECTION	GetDIRECTION(void);
	
	
	int GetScrollX();
	int GetScrollY();

public:
	CObj(void);
	virtual ~CObj(void);

public:
	virtual void	Initialize(void)PURE;
	virtual int		Progress(void)PURE;
	virtual void	Render(HDC hdc)PURE;
	virtual void	Release(void)PURE;
};
