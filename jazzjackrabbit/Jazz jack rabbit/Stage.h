#pragma once
#include "scene.h"

class CObj;
class CStage :
	public CScene
{
private:
	list<CObj*>		m_ObjList[OBJ_END];
	
	DWORD m_MobTime;
		
	
	vector<TILE*>		m_Line;
	CObj*			m_pBack;
	
	int iItem;

	


private:
	void  Scroll(void);
	void LoadMap();
	void SaveScore();


public:
	CStage(void);
	~CStage(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
