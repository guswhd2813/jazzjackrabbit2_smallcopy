#include "StdAfx.h"
#include "Score.h"

CScore::CScore(void)
:m_dwTime(GetTickCount())
{
}

CScore::~CScore(void)
{
}

void CScore::Initialize(void)
{
	m_dwTime = GetTickCount();
	iTimer=0;
	iTimer2=0;
	iTimer3=0;
	iTimer4=0;
	iScore1 = 0;
	iScore2 = 0;
	iScore3 = 0;
	iScore4 = 0;
	iScore5 = 0;
	iScore6 = 0;
	iScore7 = 0;
	iScore8 = 0;
	iTotalscore=0;
}
int	 CScore::Progress(void)
{
	
	ScoreMark();
	TimeMark();

	return 0;
}
void CScore::Render(HDC hdc)
{
		TransparentBlt(hdc, 
			10,10,
			29,31, (*m_pBitMap)[strScore1]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			30,10,
			29,31, (*m_pBitMap)[strScore2]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			50,10,
			29,31, (*m_pBitMap)[strScore3]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			70,10,
			29,31, (*m_pBitMap)[strScore4]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			90,10,
			29,31, (*m_pBitMap)[strScore5]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			110,10,
			29,31, (*m_pBitMap)[strScore6]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			130,10,
			29,31, (*m_pBitMap)[strScore7]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			150,10,
			29,31, (*m_pBitMap)[strScore8]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
			//X
		TransparentBlt(hdc, 
			350,10,
			29,31, (*m_pBitMap)[strTime]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
			TransparentBlt(hdc, 
			370,10,
			29,31, (*m_pBitMap)[strTime2]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			410,10,
			29,31, (*m_pBitMap)[strTime3]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
		TransparentBlt(hdc, 
			430,10,
			29,31, (*m_pBitMap)[strTime4]->GetMemDC(),
			0, 
			0, 
			29, 31, 
			RGB(150, 150, 150));
}
void CScore::Release(void)
{

}
void CScore::TimeMark(void)
{
	if(m_dwTime + 1000 < GetTickCount())
	{		
		iTimer4 ++;
		m_dwTime = GetTickCount();

	}
	if(iTimer4==10)
	{
		iTimer3++;
		iTimer4=0;
	}
	
	if(iTimer3 ==6)
	{
		iTimer2++;
		iTimer3 =0;
	}
	if(iTimer2 ==10)
	{
		iTimer ++;
		iTimer2=0;
	}

	switch(iTimer)
	{
		case 1: 
			strTime = "1";
			break;
			case 2: 
			strTime = "2";
			break;

			case 3: 
			strTime = "3";
			break;

			case 4: 
			strTime = "4";
			break;

			case 5: 
			strTime = "5";
			break;

			case 6: 
			strTime = "6";
			break;

			case 7: 
			strTime = "7";
			break;

			case 8: 
			strTime = "8";
			break;

			case 9: 
			strTime = "9";
			break;

			case 0: 
			strTime = "0";
			break;


	}

	switch(iTimer2)
	{
		case 1: 
			strTime2 = "1";
			break;
			case 2: 
			strTime2 = "2";
			break;

			case 3: 
			strTime2 = "3";
			break;

			case 4: 
			strTime2 = "4";
			break;

			case 5: 
			strTime2 = "5";
			break;

			case 6: 
			strTime2= "6";
			break;

			case 7: 
			strTime2 = "7";
			break;

			case 8: 
			strTime2 = "8";
			break;

			case 9: 
			strTime2 = "9";
			break;

			case 0: 
			strTime2 = "0";
			break;


	}
	switch(iTimer3)
	{
		case 1: 
			strTime3 = "1";
			break;
			case 2: 
			strTime3 = "2";
			break;

			case 3: 
			strTime3 = "3";
			break;

			case 4: 
			strTime3 = "4";
			break;

			case 5: 
			strTime3 = "5";
			break;

			case 6: 
			strTime3 = "6";
			break;

			case 7: 
			strTime3 = "7";
			break;

			case 8: 
			strTime3 = "8";
			break;

			case 9: 
			strTime3 = "9";
			break;

			case 0: 
			strTime3 = "0";
			break;


	}
	switch(iTimer4)
	{
		case 1: 
			strTime4 = "1";
			break;
			case 2: 
			strTime4 = "2";
			break;

			case 3: 
			strTime4 = "3";
			break;

			case 4: 
			strTime4 = "4";
			break;

			case 5: 
			strTime4 = "5";
			break;

			case 6: 
			strTime4 = "6";
			break;

			case 7: 
			strTime4 = "7";
			break;

			case 8: 
			strTime4 = "8";
			break;

			case 9: 
			strTime4 = "9";
			break;

			case 0: 
			strTime4 = "0";
			break;


	}
}

void CScore::ScoreMark()
{

	if(iScore8>=10)
	{
		iScore8-=10;
		iScore7++;
	}
	if(iScore7==10)
	{
		iScore7-=10;
		iScore6++;
	}
	if(iScore6==10)
	{
		iScore6=0;
		iScore5++;
	}
	if(iScore5==10)
	{
		iScore5=0;
		iScore4++;
	}
	if(iScore4==10)
	{
		iScore4=0;
		iScore3++;
	}
	if(iScore3==10)
	{
		iScore3=0;
		iScore2++;
	}
	if(iScore2==10)
	{
		iScore2=0;
		iScore1++;
	}
	switch(iScore1)
	{
		case 1: 
			strScore1 = "1";
			break;
			case 2: 
			strScore1 = "2";
			break;

			case 3: 
			strScore1 = "3";
			break;

			case 4: 
			strScore1 = "4";
			break;

			case 5: 
			strScore1 = "5";
			break;

			case 6: 
			strScore1 = "6";
			break;

			case 7: 
			strScore1 = "7";
			break;

			case 8: 
			strScore1 = "8";
			break;

			case 9: 
			strScore1 = "9";
			break;

			case 0: 
			strScore1 = "0";
			break;


	}

	switch(iScore2)
	{
		case 1: 
			strScore2 = "1";
			break;
			case 2: 
			strScore2 = "2";
			break;

			case 3: 
			strScore2 = "3";
			break;

			case 4: 
			strScore2 = "4";
			break;

			case 5: 
			strScore2 = "5";
			break;

			case 6: 
			strScore2 = "6";
			break;

			case 7: 
			strScore2 = "7";
			break;

			case 8: 
			strScore2 = "8";
			break;

			case 9: 
			strScore2 = "9";
			break;

			case 0: 
			strScore2 = "0";
			break;


	}

	switch(iScore3)
	{
		case 1: 
			strScore3 = "1";
			break;
			case 2: 
			strScore3 = "2";
			break;

			case 3: 
			strScore3 = "3";
			break;

			case 4: 
			strScore3 = "4";
			break;

			case 5: 
			strScore3 = "5";
			break;

			case 6: 
			strScore3 = "6";
			break;

			case 7: 
			strScore3 = "7";
			break;

			case 8: 
			strScore3 = "8";
			break;

			case 9: 
			strScore3 = "9";
			break;

			case 0: 
			strScore3 = "0";
			break;


	}

	switch(iScore4)
	{
		case 1: 
			strScore4 = "1";
			break;
			case 2: 
			strScore4 = "2";
			break;

			case 3: 
			strScore4 = "3";
			break;

			case 4: 
			strScore4 = "4";
			break;

			case 5: 
			strScore4 = "5";
			break;

			case 6: 
			strScore4 = "6";
			break;

			case 7: 
			strScore4 = "7";
			break;

			case 8: 
			strScore4 = "8";
			break;

			case 9: 
			strScore4 = "9";
			break;

			case 0: 
			strScore4 = "0";
			break;


	}

	switch(iScore5)
	{
		case 1: 
			strScore5 = "1";
			break;
			case 2: 
			strScore5 = "2";
			break;

			case 3: 
			strScore5 = "3";
			break;

			case 4: 
			strScore5 = "4";
			break;

			case 5: 
			strScore5 = "5";
			break;

			case 6: 
			strScore5 = "6";
			break;

			case 7: 
			strScore5 = "7";
			break;

			case 8: 
			strScore5 = "8";
			break;

			case 9: 
			strScore5 = "9";
			break;

			case 0: 
			strScore5 = "0";
			break;


	}

	switch(iScore6)
	{
		case 1: 
			strScore6 = "1";
			break;
			case 2: 
			strScore6 = "2";
			break;

			case 3: 
			strScore6 = "3";
			break;

			case 4: 
			strScore6 = "4";
			break;

			case 5: 
			strScore6 = "5";
			break;

			case 6: 
			strScore6 = "6";
			break;

			case 7: 
			strScore6 = "7";
			break;

			case 8: 
			strScore6 = "8";
			break;

			case 9: 
			strScore6 = "9";
			break;

			case 0: 
			strScore6 = "0";
			break;


	}

	switch(iScore7)
	{
		case 1: 
			strScore7 = "1";
			break;
			case 2: 
			strScore7 = "2";
			break;

			case 3: 
			strScore7 = "3";
			break;

			case 4: 
			strScore7 = "4";
			break;

			case 5: 
			strScore7 = "5";
			break;

			case 6: 
			strScore7 = "6";
			break;

			case 7: 
			strScore7 = "7";
			break;

			case 8: 
			strScore7 = "8";
			break;

			case 9: 
			strScore7 = "9";
			break;

			case 0: 
			strScore7 = "0";
			break;


	}

	switch(iScore8)
	{
		case 1: 
			strScore8 = "1";
			break;
			case 2: 
			strScore8 = "2";
			break;

			case 3: 
			strScore8 = "3";
			break;

			case 4: 
			strScore8 = "4";
			break;

			case 5: 
			strScore8 = "5";
			break;

			case 6: 
			strScore8 = "6";
			break;

			case 7: 
			strScore8 = "7";
			break;

			case 8: 
			strScore8 = "8";
			break;

			case 9: 
			strScore8 = "9";
			break;

			case 0: 
			strScore8 = "0";
			break;
	}

}

void CScore::SetScore(int _iScorePoint)
{
	iScore8 = _iScorePoint;
}

int CScore::GetScorePoint()
{
	iTotalscore =  ( iScore8 * 1 )+  ( iScore7 * 10 )+  ( iScore6 * 100 )+  ( iScore5 * 1000 )+  ( iScore4 * 10000 )+  ( iScore3 * 100000 )+  ( iScore2 * 1000000 )+  ( iScore1 * 10000000 );
	return iTotalscore;
}

