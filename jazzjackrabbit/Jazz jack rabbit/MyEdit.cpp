#include "StdAfx.h"
#include "MyEdit.h"
#include "RenderMgr.h"


CMyEdit::CMyEdit(void)
:m_dwTime(GetTickCount()),iPick(0)
{
	memset(m_szUI,0,sizeof(TCHAR)*128);
}

CMyEdit::~CMyEdit(void)
{
	Release();
}

void CMyEdit::Initialize(void)
{
	bStage=0;
	m_BitMap["Back"] = (new CBitBmp)->LoadBmp(L"../Texture/back.bmp");
	m_BitMap["Map"] = (new CBitBmp)->LoadBmp(L"../Texture/Map.bmp");
	m_BitMap["Tile"] = (new CBitBmp)->LoadBmp(L"../Texture/block1.bmp");
	m_BitMap["Back2"] = (new CBitBmp)->LoadBmp(L"../Texture/back5.bmp");
	m_BitMap["Map2"] = (new CBitBmp)->LoadBmp(L"../Texture/Map2.bmp");
	m_BitMap["Tile"] = (new CBitBmp)->LoadBmp(L"../Texture/block1.bmp");

	for(int i = 0; i < TILEY; ++i)
	{
		for(int j = 0; j < TILEX; ++j)
		{
			float fX = j * TILECX + TILECX / 2.f;
			float fY = i * TILECY + TILECY / 2.f;

			m_vecTile.push_back(CreateTile(fX, fY));
		}
	}

	m_fScrollX = 0.f;
	m_fScrollY = 0.f;
	
}

int CMyEdit::Progress(void)
{
	KeyInput();
	
	Scroll();
	if(bStage==0)
	{
		for(int i = 0; i < TILEY; ++i)
		{
			for(int j = 0; j < TILEX; ++j)
			{
				float fX = j * TILECX + TILECX / 2.f;
				float fY = i * TILECY + TILECY / 2.f;

				m_vecTile.push_back(CreateTile(fX, fY));
			}
		}
	}
	else if(bStage==1)
	{
		for(int i = 0; i < TILEY2; ++i)
		{
			for(int j = 0; j < TILEX2; ++j)
			{
				float fX = j * TILECX + TILECX / 2.f;
				float fY = i * TILECY + TILECY / 2.f;

				m_vecTile.push_back(CreateTile(fX, fY));
			}
		}
	}


	//Picking();


	

	return 0;
}

void CMyEdit::Render(HDC hdc)
{
	//UI
	if(bStage==0)
	{
		wsprintf(m_szUI, L"L버튼: pick ,R버튼 : change , q:세이브 w:로드");
		TextOut(hdc, 500, 40,m_szUI, lstrlen(m_szUI));

		//BitBlt(m_BitMap["Back"]->GetMemDC(), int( 0+m_fScrollX), int(0 + m_fScrollY), (int)3432, (int)1528,
		//	m_BitMap["Map"]->GetMemDC(), 0, 0, SRCCOPY);
		BitBlt(m_BitMap["Back"]->GetMemDC(), 0,0, WINCX, WINCY,
		m_BitMap["Map"]->GetMemDC(), -m_fScrollX, -m_fScrollY, SRCCOPY);	
		
		TCHAR	szBuf[128] = L"";

		int iCountY = WINCY / TILECY + 1;
		int iCountX = WINCX / TILECX + 1;

		for(int i = 0; i < iCountY; ++i)
		{
			for(int j = 0; j < iCountX; ++j)
			{
				int	iCullX = int(-m_fScrollX) / TILECX;
				int	iCullY = int(-m_fScrollY) / TILECY;
				int iIndex = (i  + iCullY) * TILEX + (j+ iCullX);

				if(iIndex < 0 || iIndex >= TILEX * TILEY)
					break;

				
				TransparentBlt(m_BitMap["Back"]->GetMemDC(), 
					int(m_vecTile[iIndex]->fX - TILECX / 2 + m_fScrollX),
					int(m_vecTile[iIndex]->fY - TILECY / 2 + m_fScrollY),
					int(TILECX), int(TILECY),
					m_BitMap["Tile"]->GetMemDC(),
					int(m_vecTile[iIndex]->iDrawID * TILECX), 0,
					int(TILECX), int(TILECY),RGB(255, 255, 255));
				//BitBlt(m_BitMap["Back"]->GetMemDC(), 
				//	int(m_vecTile[iIndex]->fX - TILECX / 2 + m_fScrollX),
				//	int(m_vecTile[iIndex]->fY - TILECY / 2 + m_fScrollY),
				//	int(TILECX), int(TILECY),
				//	m_BitMap["Tile"]->GetMemDC(), 
				//	int(m_vecTile[iIndex]->iDrawID * TILECX), 0, SRCCOPY);

				
			}
		}
		
		
	BitBlt(hdc, 0, 0,WINCX, WINCY, m_BitMap["Back"]->GetMemDC(), 0, 0, SRCCOPY);

	}

	else if(bStage==1)
	{
		wsprintf(m_szUI, L"L버튼: pick ,R버튼 : change , q:세이브 w:로드");
		TextOut(hdc, 500, 40,m_szUI, lstrlen(m_szUI));

		//BitBlt(m_BitMap["Back"]->GetMemDC(), int( 0+m_fScrollX), int(0 + m_fScrollY), (int)3432, (int)1528,
		//	m_BitMap["Map"]->GetMemDC(), 0, 0, SRCCOPY);
		BitBlt(m_BitMap["Back2"]->GetMemDC(), 0,0, WINCX, WINCY,
			m_BitMap["Map2"]->GetMemDC(), -m_fScrollX, -m_fScrollY, SRCCOPY);	
		
		TCHAR	szBuf[128] = L"";

		int iCountY = WINCY / TILECY + 1;
		int iCountX = WINCX / TILECX + 1;

		for(int i = 0; i < iCountY; ++i)
		{
			for(int j = 0; j < iCountX; ++j)
			{
				int	iCullX = int(-m_fScrollX) / TILECX;
				int	iCullY = int(-m_fScrollY) / TILECY;
				int iIndex = (i  + iCullY) * TILEX2 + (j+ iCullX);

				if(iIndex < 0 || iIndex >= TILEX2 * TILEY2)
					break;

				
				TransparentBlt(m_BitMap["Back2"]->GetMemDC(), 
					int(m_vecTile[iIndex]->fX - TILECX / 2 + m_fScrollX),
					int(m_vecTile[iIndex]->fY - TILECY / 2 + m_fScrollY),
					int(TILECX), int(TILECY),
					m_BitMap["Tile"]->GetMemDC(),
					int(m_vecTile[iIndex]->iDrawID * TILECX), 0,
					int(TILECX), int(TILECY),RGB(255, 255, 255));
				//BitBlt(m_BitMap["Back"]->GetMemDC(), 
				//	int(m_vecTile[iIndex]->fX - TILECX / 2 + m_fScrollX),
				//	int(m_vecTile[iIndex]->fY - TILECY / 2 + m_fScrollY),
				//	int(TILECX), int(TILECY),
				//	m_BitMap["Tile"]->GetMemDC(), 
				//	int(m_vecTile[iIndex]->iDrawID * TILECX), 0, SRCCOPY);

				
			}
		}
		
		
	BitBlt(hdc, 0, 0,WINCX, WINCY, m_BitMap["Back2"]->GetMemDC(), 0, 0, SRCCOPY);


	}

}
void CMyEdit::Picking(void)
{
	if(bStage==0)
	{
		int	iX = int(GetMouse().x - m_fScrollX) / TILECX;
		int	iY = int(GetMouse().y - m_fScrollY) / TILECY;

		int iIndex = iY * TILEX + iX;

		if(iIndex < 0 || iIndex >= TILEX * TILEY)
			return;

		m_vecTile[iIndex]->iDrawID = iPick;
		m_vecTile[iIndex]->iOption = iPick;
	}
	else if(bStage==1)
	{
		int	iX = int(GetMouse().x - m_fScrollX) / TILECX;
		int	iY = int(GetMouse().y - m_fScrollY) / TILECY;

		int iIndex = iY * TILEX + iX;

		if(iIndex < 0 || iIndex >= TILEX2 * TILEY2)
			return;

		m_vecTile[iIndex]->iDrawID = iPick;
		m_vecTile[iIndex]->iOption = iPick;

	}
	
	//if(iPick ==1 || iPick == 2)//라인
	//{
	//	LINEPOINT TilePoint = LINEPOINT(
	//	//m_LineList.push_back(new LINE(m_LineList.back()->
	//	//( m_vecTile[iIndex]->fX-( m_vecTile[iIndex]->fCX/2 ) )
	//	//( m_vecTile[iIndex]->fY-( m_vecTile[iIndex]->fCY/2 ) ) //스타팅


	//}
}
void CMyEdit::Change(void)
{

	if(iPick ==5)
	{
		
		iPick=0;
	}
	else
	{
		
		iPick++;
	}


}

void CMyEdit::Release(void)
{
	for(size_t i = 0; i < m_vecTile.size(); ++i)
	{
		::Safe_Delete(m_vecTile[i]);
	}
	m_vecTile.clear();
	vector<TILE*>().swap(m_vecTile);
}

TILE* CMyEdit::CreateTile(float _fX, float _fY)
{
	TILE*	pTile = new TILE;

	pTile->fX = _fX;
	pTile->fY = _fY;
	pTile->fCX = TILECX;
	pTile->fCY = TILECY;

	pTile->iOption = 0;
	pTile->iDrawID = 0;

	return pTile;
}



void CMyEdit::KeyInput(void)
{
	if(GetAsyncKeyState(VK_LEFT))
		m_fScrollX += 10.f;

	if(GetAsyncKeyState(VK_RIGHT))
		m_fScrollX -= 10.f;

	if(GetAsyncKeyState(VK_UP))
		m_fScrollY += 10.f;

	if(GetAsyncKeyState(VK_DOWN))
		m_fScrollY -= 10.f;
	if(GetAsyncKeyState(VK_LBUTTON))
		Picking();
	if(GetAsyncKeyState(VK_RBUTTON))
	{
		if(m_dwTime + 1000 < GetTickCount())
		{
			m_dwTime = GetTickCount();
			Change();
		}
	}
	if(GetAsyncKeyState(0x51) || GetAsyncKeyState(0x71))
	{
		SaveMap();
		return;
		
	}
	if(GetAsyncKeyState(0x57) || GetAsyncKeyState(0x77))
	{

		LoadMap();
		return;
	}
	if(GetAsyncKeyState(VK_TAB))
	{
		if(bStage==0) bStage=1;
		else bStage=0;

	}
	
}

void CMyEdit::Scroll(void)
{
	if(bStage==0)
	{
		if(m_fScrollY > 0.f)
			m_fScrollY = 0.f;

		if(m_fScrollY < WINCY - (1528))
			m_fScrollY = WINCY - (1528);


		if(m_fScrollX > 0.f)
			m_fScrollX = 0.f;

		if(m_fScrollX < WINCX - 3432)
			m_fScrollX = WINCX - 3432;
	}
	else if(bStage==1)
	{
		if(m_fScrollY > 0.f)
			m_fScrollY = 0.f;

		if(m_fScrollY < WINCY - (5968))
			m_fScrollY = WINCY - (5968);


		if(m_fScrollX > 0.f)
			m_fScrollX = 0.f;

		if(m_fScrollX < WINCX - 1539)
			m_fScrollX = WINCX - 1539;

		//1539/5968

	}
}

void CMyEdit::SaveMap(void)
{
	if(bStage==0)
	{
	HANDLE		 hFile = NULL;
	DWORD		dwByte= 0;

	hFile  =  CreateFile(L"../Data/TileMap.dat",
						GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);

	for(vector<TILE*>::iterator iter = m_vecTile.begin();
		iter != m_vecTile.end(); ++iter)
	{
		WriteFile(hFile,(*iter),sizeof(TILE),&dwByte,NULL);
	}
	CloseHandle(hFile);
	}
	else if(bStage==1)
	{
			HANDLE		 hFile = NULL;
	DWORD		dwByte= 0;

	hFile  =  CreateFile(L"../Data/TileMap2.dat",
						GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);

	for(vector<TILE*>::iterator iter = m_vecTile.begin();
		iter != m_vecTile.end(); ++iter)
	{
		WriteFile(hFile,(*iter),sizeof(TILE),&dwByte,NULL);
	}
	CloseHandle(hFile);

	}


}

void CMyEdit::LoadMap(void)
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
		
		m_vecTile.push_back(pTILE);

		
	}

	CloseHandle(hFile);



}


