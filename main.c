#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "screen.h"
 
typedef struct _PLAYER
{
	int x, y; //출력기준좌표
}PLAYER;
 
PLAYER player;
 
void init() {
	player.x = 20;
	player.y = 10;
}
void update() {
}
void render()
{
	ScreenClear(); //대기하고 있는 화면 버퍼를 지운다.
	ScreenPrint(player.x, player.y, "♀"); //(player.x, player.y) 좌표에 문자를 출력한다.
	ScreenFlipping(); //활성화된 화면 버퍼와 비활성화된 화면 버퍼의 상태를 바꾼다
}
 
void release() {
}
 
int main(void) {
	int nKey, nRemain;
 
	ScreenInit(); //버퍼를 2개 생성한다.
	init();
 
	while (1) 
    {
		if (_kbhit()) //키보드가 눌렸는지 체크
        {
			nKey = _getch(); //눌린값 대입

			if (nKey == 'q') //q를 눌렀다면 break
			{	
                break;
            }
            else if (nKey == 224 || nKey == 0) 
            {
				nKey = _getch();
                switch (nKey) 
                {                    
                    case 75: player.x--; break; //왼쪽 방향키를 눌렀다면
                    case 77: player.x++; break; //오른쪽 방향키를 눌렀다면                    
                    case 72: player.y--; break; //위쪽 방향키를 눌렀다면                   
                    case 80: player.y++; break; //아래쪽 방향키를 눌렀다면
                }
			}
		}
		update();
		render();
	} 
 
	release();
	ScreenRelease(); //화면 버퍼 초기화 함수에서 생성한 두 개의 화면 버퍼를 모두 해제한다.
	return 0;
}