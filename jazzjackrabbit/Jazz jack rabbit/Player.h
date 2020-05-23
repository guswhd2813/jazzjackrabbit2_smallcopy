#pragma once
#include "obj.h"

class CPlayer :
	public CObj
{
private:
	DWORD	m_dwKey;
	DWORD	m_dwDelayKey;
	DWORD	m_dwTime;
	DWORD	m_dwTime2;//파운딩타임
	DWORD m_dwTime3;//(다쳣을때)
	DWORD m_dwTime4;//사망
	DWORD m_dwTimeSliding;//슬라이딩
	DWORD m_dwAttackSpeed;//총알속도
	DWORD   m_HurtTime;
	DWORD	m_dwState;
	FRAME	m_tFrame;
	POINT		m_ptOffset;
	int iSpecialMov;

	bool		bSliding;
	bool		bPounding;
	bool      bHurt;
	bool		bDeath;
	int			iTempHp;
	float		m_fPoundingSpeed;

	int		iAmount1;
	int		iAmount2;
	int		iAmount3;
	int		iAmount4;

	string strAmor1;
	string strAmor2;
		string strAmor3;
	string strAmor4;
		string strAmor5;
	string strAmor6;
	
		int iTemp;
		int iTemp2;
		int iTemp3;
		int iTemp4;
		int iTemp5;
		int iTemp6;

	
	



private:
	void	KeyCheck(void);
	void	Direction(void);
	void	SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime);
	void	ScrollX(void);
	void	ScrollY(void);

	void	SpecialMove(void);



	
public:
	void SetBullet(list<CObj*>* _pBullet);
	int GetSpecialMov();
	void SetHurt(bool _hurt);
	bool GetHurt();
	void SetTempHp(int _iHp);
	void Death(float _X,float _Y);
	DWORD GetTime3(void);
	void SetTime(DWORD _Time);

	
	void SetAmount1(int _Amount1);
	void SetAmount2(int _Amount2);
	void SetAmount3(int _Amount3);
	void ItemCount();

	



public:
	CPlayer(void);
	~CPlayer(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
