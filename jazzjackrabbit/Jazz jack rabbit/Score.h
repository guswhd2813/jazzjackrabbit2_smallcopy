#pragma once
#include "obj.h"
#include "Player.h"

class CScore :
	public CObj
{
private:
	
	string strTime;
	string strTime2;
	string strTime3;
	string strTime4;

	int iTempTime;
	int iTimer;
	int iTimer2;
	int iTimer3;
	int iTimer4;
	DWORD	m_dwTime;
	//
	
	string strScore1;
	string strScore2;
	string strScore3;
	string strScore4;
	string strScore5;
	string strScore6;
	string strScore7;
	string strScore8;

	int iScore1;
	int iScore2;
	int iScore3;
	int iScore4;
	int iScore5;
	int iScore6;
	int iScore7;
	int iScore8;

	int iTotalscore;




	void ScoreMark(void);
	void TimeMark(void);
	CObj*				m_pPlayer;

public:
	void Initialize(void);
	int	 Progress(void);
	void Render(HDC hdc);
	void Release(void);
	
	void SetScore(int _iScorePoint);

	int GetScorePoint();


public:
	CScore(void);
	~CScore(void);
};
