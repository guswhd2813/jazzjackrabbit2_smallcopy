#pragma once

extern HWND g_hWnd;

const int WINCX = 800;
const int WINCY = 600;

const int TILEX = 108;
const int TILEY = 48;

const int TILEX2 = 48;
const int TILEY2 = 187;
// 3432/1528

//1539/5968

const int TILECX = 32;
const int TILECY = 32;

// Key °ª

const DWORD		KEY_LEFT			= 0x00000001;
const DWORD		KEY_RIGHT			= 0x00000002;
const DWORD		KEY_UP				= 0x00000004;
const DWORD		KEY_DOWN			= 0x00000008;
const DWORD		KEY_SPACE			= 0x00000010; //°ø°Ý
const DWORD		KEY_CONTROAL	= 0x00000020; //Á¡ÇÁ
const DWORD		KEY_SHIFT			= 0x00000040; //»¡¸®¶Ù±â
const DWORD		KEY_RETURN		= 0x00000080;//¿£ÅÍ



// state °ª

const DWORD		ST_STAND			= 0x00000001;
const DWORD		ST_WALK			= 0x00000002;
const DWORD		ST_RUNNING		= 0x00000004;
const DWORD		ST_ATTACK			= 0x00000008;
const DWORD		ST_JUMP			= 0x00000010;
const DWORD		ST_DAMAGE		= 0x00000020;
const DWORD		ST_SLIDING			= 0x00000040;
const DWORD		ST_DEATH			= 0x00000080;
const DWORD		ST_LOOKUP		= 0x00000100;
const DWORD		ST_SIT				= 0x00000200;
const DWORD		ST_POUND			= 0x00000400;
const DWORD		ST_FALLING			= 0x00000800;
const DWORD		ST_LAND			= 0x00001000;
const DWORD		ST_EFFECT1			= 0x00002000;
const DWORD		ST_EFFECT2			= 0x00004000;
const DWORD		ST_EFFECT3			= 0x00008000;



const DWORD		EF_EFFECT1			= 0x00000001;
const DWORD		EF_EFFECT2			= 0x00000002;


//ÀÌÆÑÆ®




