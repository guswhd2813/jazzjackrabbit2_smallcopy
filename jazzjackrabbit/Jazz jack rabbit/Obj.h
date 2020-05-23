#pragma once

#include "Include.h"

class CBitBmp;
class CObj
{
protected:
	INFO		m_tInfo;
	float		m_fSpeed;
	int			m_iDIr;  // 1-���� 2-���� 3-����  4-���� 5-�ƿ� 6-�ƿ�
	string		m_strKey;
	int			m_iDrawID;
	static	map<string, CBitBmp*>*		m_pBitMap;
	static  POINT m_ptScroll;

	//
	CObj*		 m_TempObjptr;
	list<CObj*>* m_pBullet;
	list<CObj*>* m_pTempObjList;

	int					iWeaponType;//����Ÿ��
	DIRECTION	m_eDir;

	//��������
	bool m_bOnGround;  //1=���� 0-����
	DWORD m_dwTime;
	bool	m_bDoubleJump;
	float		m_fSpeedX; //�����̵��ϵ�Ƹ�
	float		m_fSpeedY;

	//���溯��(�Ŀ��,�����̵�) 1�ϰ�� �ƹ�Ű�ȸ��� 0�ϰ�� Ű����
	bool m_bChange;

	list<CObj*>* m_EffectList;//����Ʈ
	list<CObj*>* m_EffectList2;

	int m_iBox;//�ڽ�����

		//�Ѿ� ����

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

	void	SetEffectList(list<CObj*>* _pTempObjList);//����Ʈ
	void SetEffectList2(list<CObj*>* _pTempObjList);
	int		GetWeaponType();
	int     GetItemType();

	
	int GetBox();

//	void SetXY(float _x,float _y);	//����ź
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
