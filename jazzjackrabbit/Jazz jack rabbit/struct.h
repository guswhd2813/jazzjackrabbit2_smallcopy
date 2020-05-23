#pragma once

typedef	 struct tagInfo
{
	float		fX;
	float		fY;
	float		fCX;
	float		fCY;
	int			iAttack;
	int			iHp;

	tagInfo(void){}
	tagInfo(float _fX, float _fY, float _fCX, float _fCY, int _iAttack, int _iHp)
		: fX(_fX), fY(_fY), fCX(_fCX), fCY(_fCY),iAttack(_iAttack),iHp(_iHp)
	{

	}

}INFO;



typedef struct tagTile
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;
	int		iOption;
	int		iDrawID;

	RECT GetRect(void)
	{
		RECT	rc = {

			int(fX - fCX / 2.f),
			int(fY - fCY / 2.f),
			int(fX + fCX / 2.f),
			int(fY + fCY / 2.f)
		};

	return rc;
	}

}TILE;

typedef struct tagFrame
{
	int		iStart;
	int		iLast;
	int		iScene;
	DWORD	dwTime;

	tagFrame(){}
	tagFrame(int _iStart, int _iLast, int _iScene, DWORD _dwTime)
		: iStart(_iStart), iLast(_iLast), iScene(_iScene), dwTime(_dwTime) 
	{

	}

}FRAME;

typedef struct tagLinePoint
{
	float		fX;
	float		fY;

	tagLinePoint(){}
	tagLinePoint(float _fX, float _fY) 
		: fX(_fX), fY(_fY)
	{

	}

}LINEPOINT;
typedef	struct tagLine
{
	LINEPOINT		tLPoint;
	LINEPOINT		tRPoint;

	tagLine(void){}
	tagLine(LINEPOINT	_tLpoint, LINEPOINT _tRpoint)
		: tLPoint(_tLpoint), tRPoint(_tRpoint)
	{

	}
}LINE;


