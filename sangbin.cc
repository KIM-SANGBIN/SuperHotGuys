
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <windows.h>
#include "console.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

char screen[HEIGHT][WIDTH];        //    [행][열]
char gamemap[HEIGHT][WIDTH] =
{
	"==============================================================================|\n",
	"|                                                                             |\n",
	"|   |==========|   |==============|   |==================|   |============|   |\n",
	"|   |          |   |              |   |                  |   |            |   |\n",
	"|   |          |   |              |   |                  |   |            |   |\n",
	"|   |          |   |              |   |                  |   |            |   |\n",
	"|   |          |   |              |   |                  |   |            |   |\n",
	"|   |          |   |              |   |                  |   |            |   |\n",
	"|   |          |   |              |   |                  |   |            |   |\n",
	"|   |           ===               |   |                   ===             |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |                             |   |                                   |   |\n",
	"|   |=============================|   |===================================|   |\n",
	"|                                                                             |\n",
	"===============================================================================\n",
	"                     Who is the Imposter?               A                      \n",
	" Dead :                                                 B                      \n",
	"                                                        C                      \n",
	"                                                        D                      \n",
	"                                                        E                      \n",
	"                                                        F                      \n",
	"                                                        G                      \n",
	"                                                        H                      \n",
	"                                                        I                      \n",
	"                                                        J                      \n"

};
char sabotagemap[HEIGHT][WIDTH] =
{
	"     @@@@@@*@=====@@@@@@@@                   .-!=;-                            \n",
	"     @@@@@@===!!!====@@@@@                  *!     #,                          \n",
	"     @@@@==;,.,,-,.:==@@@@                 *        ,$ -$*                     \n",
	"     @@@=*,---,,,--,.*=@@@               ,!           @= ~!                    \n",
	"     @@==,,-.  .  .,-,*=@@               !            =$  ~~                   \n",
	"     @@=,-,    ,    .-,=@@               !            =$  ~~                   \n",
	"     @=:--     ,     ,-~=@               @         ,   #@~ :.                  \n",
	"     @=--     .,.     -,=@              -@       :~#@  ,@@- $                  \n",
	"     =*--     ,,.     ,-;=              :@    .=@: .;~  -@$ ,:                 \n",
	"     =;-,     ,,.,    .-:=              :@**@=*~.    ;   =@; #.                \n",
	"     =;-.    .,,,,    .-~=              ~@@.-~~,,,   =.   @@  :                \n",
	"     =;-,    ,.,,.    .-:=            . -@@~~~~~~,   =;   !@$ =     .          \n",
	"     =*:-     .,,     ,~!=         .    ,@@;~~~~~~~~ $,    @@  :    .          \n",
	"     @=~-      ,.     -:=@         .     @@;~~~~~~~;;-     !@= #               \n",
	"     @=:~-     ,     ,-:=@         .     @@@*****=$;       -@@ @               \n",
	"     @@=:-,    ,    .-;*$@         .     @@@@=!~            #@@*               \n",
	"     @@$*;--.  .   ,-;*=@@         .     @@@@               ,@@:               \n",
	"     @@@==;~--,..--~;*=@@@         .     @@@@                @@.  .            \n",
	"     @@@@==!!;:~~;!!==@@@@               @@@@                ::                \n",
	"     @@@@@@===!!!*==@@@@@@         .     *!!=                ;.                \n",
	"     @@@@@@@@$====@@@@@@@@                                                     \n"

};
char MainScreen[HEIGHT][WIDTH] = {

	"                                                               ~;***!!:        \n",
	"     @@@.  @@.    @@.  @@@@@.  @@.     @.   @@@@@@.          .#@@@@@@@@#.      \n",
	"    @@:@@. @:@.  @'@. @@'''@@. @:@.    @.  @@''''@@@.       ~@@@*~..,:=@@      \n",
	"   @@.  @@.@.'@.@' @. @.    @. @. @@.  @. @@:    '''       :@@*.       ;@=     \n",
	"   @@@@@@@.@. '@'  @. @.    @. @. @@.  @. @:     @@@@.    ,@@!..        @@     \n",
	"   @.    @.@.  '   @. @.    @. @.  @@. @. @@.      @:     ;@@@@@@@#:.   ~@-    \n",
	"   @.    @.@.      @. @@.  @@. @.   @@.@. .@@.    @@.    :@@###$$#@@$   .@@    \n",
	"   @.    @.@.      @. '@@@@@:  @.     @@.  .@@@@@@@:    ~@#       -*@*  .@@    \n",
	"   '     ' '       .   '''''   '      ''    '''''''     @#         ;#@   #@.   \n",
	"                                                       -@-        -;$@   ;@@@@,\n",
	"     @@.        @@.      @@@@@@@@@@.                   :@;       .;;@#   ;@@@@@\n",
	"     @@.        @@.    @@:''''''''@@@.                 -@#;;;;;;;;;!@=   :@- .@\n",
	"     @@.        @@.    @@.         @@.                  @@#;;;;;;;!@@.   ;@:  @\n",
	"     @@.        @@.    @@.         ...                  .@@@@#=*$#@@~   .;@$;:#\n",
	"     @@.        @@.     @@@@@@@@@@@                      @$:@@@@@$~.    ,;@$;;$\n",
	"     @@.        @@.     '''''''''''@@.                   @=   ..        :;@#;;$\n",
	"     '@@.      @@:     @@          @@.                  .@=             ::@#;;$\n",
	"      '@@@@@@@@@:      '@@@@@@@@@@@@:                   .@*            .;:@$;;=\n",
	"       '''''''''        ''''''''''''                    .@=            ~;:@$;;=\n",
	"                                                        .@=-          .;;;@=;;=\n"

};

#define ENEMY_NUM 10
#define E_COUNT 3
#define ENEMY_LINE 3
#define ENEMY_FLIGHT 10
#define IMPO_NUM 2

int stagecount = 0;
char startcursor[3] = ">>";
char eUnit[E_COUNT + 1] = "=.=";


//---------------함수들-------------//
int StartGameAction2();
void startgameaction();
void startgameinitialobject();
void DrawMain();
void DrawStartGame();
void SetStartPosition();


void EnemyAction();
void DrawEnemy();
void Draw();
int CheckEndGame();
int CheckClearGame();
void EnemyInitialObject();
void CheckCrash();
void selectimpoobject();
void selectimpoaction();
int selectimpoaction2();
void drawselectimpo();
//----------------------------------------//

//----------------함수들--------------//




struct EnemyInfo {
	int x, y;
	int liveFlag;
	/*int StartX;           //    기준점좌표값 x - StartX 절대값을 구해서.
		int StartY;
		int movex;
		int movey;
		int ismoving;*/
	char name;
	int isimpo;
	int pathnum;            //경로지정
	int walknum;            //경로 내에서 걸어간 횟수
};

struct startinfo
{
	int x, y;
};

struct selectinfo
{
	int x, y;
};

struct startinfo startgame;

struct EnemyInfo enemy[ENEMY_NUM];
struct selectinfo selectimpo;

//--------------------struct-----------------------//

void main()
{
	srand((unsigned)time(NULL));
	Initial();
	startgameinitialobject();
	int count = 0;
	while (stagecount == 0)
	{
		if (stagecount == 0)
		{
			startgameaction();
			DrawMain();
			if (StartGameAction2() == 1)
				stagecount++;
			else if (StartGameAction2() == 2)
				break;
		}
		Sleep(100);
	}
	SetStartPosition();
	selectimpoobject();
	while (stagecount == 1)
	{
		if (stagecount == 1)
		{
			EnemyAction();            
			selectimpoaction();
			Draw();


			/*if (CheckEndGame() == 1)
				break;
				if (CheckClearGame() == 1)
				stagecount++;*/
			/*if(count<30 || count>=51)
				Draw();
				if (count >= 30 && count <50)           //전등 꺼지는 시간
				{
				int i;
				for (i = 0; i < HEIGHT; i++)            // HEIGHT = 24
				{
				memset(screen[i], ' ', WIDTH);        //화면의  i번째 행들을 ' ' 공백으로 width의 길이만큼 넣어주고
				for (int j = 0; j < WIDTH; j++)
				{
				screen[i][j] = sabotagemap[i][j];
				}

				screen[i][WIDTH - 1] = NULL;            // 마지막 width칸에 NULL을 넣어준다.
				}
				for (i = 0; i < HEIGHT; i++)
				{
				MoveCursor(0, i);        //  커서의 시작 지점 즉 y축을 바꾸어주며 한줄단위로 출력
				printf(screen[i]);        //    화면의 i번째행 을 출력   ==  printf("%s",screen[i]);

				MoveCursor(70, 23);
				printf("%d", 1000000);

				}
				}*/
			if (count > 100)
			{
				CheckCrash();
			}
		}
		Sleep(1);
		count++;
	}


}

void startgameaction()
{
	if (stagecount == 0)
	{
		if ((GetAsyncKeyState(VK_UP) & 0x8000))
		{
			if (startgame.y > 21)
			{
				startgame.y--;
			}
		}
		if ((GetAsyncKeyState(VK_DOWN) & 0x8000))
		{
			if (startgame.y <= 21)
			{
				startgame.y++;
			}
		}
	}
}

void selectimpoaction()
{

	if ((GetAsyncKeyState(VK_UP) & 0x8000))
	{
		if (selectimpo.y > 20)
		{
			selectimpo.y--;
		}
	}
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000))
	{
		if (selectimpo.y < 29)
		{
			selectimpo.y++;
		}
	}

}

void startgameinitialobject()
{
	startgame.x = 32;
	startgame.y = 21;
	int x = startgame.x;
	int y = startgame.y;
}

void selectimpoobject()
{
	selectimpo.x = 50;
	selectimpo.y = 20;
	int x = selectimpo.x;
	int y = selectimpo.y;
}

void DrawStartGame()
{
	int i;
	int x = startgame.x - 1;
	int y = startgame.y;

	for (i = 0; i < 2; i++)
	{
		if (x >= 31 && x < 33 && y >= 21 && y <= 22)
			MainScreen[y][x] = startcursor[i];
		x++;
	}
}

void drawselectimpo()
{
	int i;
	int x = selectimpo.x - 1;
	int y = selectimpo.y;

	for (i = 0; i < 2; i++)
	{
		if (x >= 49 && x < 51 && y >= 20 && y <= 29)
			screen[y][x] = startcursor[i];
		x++;
	}
}

void DrawMain()
{
	int i;
	for (i = 0; i < HEIGHT; i++)
	{
		strcpy(MainScreen[21], "                                  Start Game                                   \n");
		strcpy(MainScreen[22], "                                  End Game                                     \n");
		MainScreen[i][WIDTH - 1] = NULL;
	}

	DrawStartGame();

	for (i = 0; i < HEIGHT; i++)
	{
		MoveCursor(0, i);
		printf(MainScreen[i]);
	}
}

int StartGameAction2()
{
	if (stagecount == 0)
	{
		if ((GetAsyncKeyState(VK_RETURN) & 0x8000))
		{
			if (startgame.y == 21)
			{
				return 1;
			}
			else if (startgame.y == 22)
			{
				return 2;
			}
		}
	}
}

int selectimpoaction2()
{
	if (stagecount == 0)
	{
		if ((GetAsyncKeyState(VK_RETURN) & 0x8000))
		{
			if (startgame.y == 21)
			{
				return 1;
			}
			else if (startgame.y == 22)
			{
				return 2;
			}
		}
	}
}



void SetStartPosition() {

	Initial();                    // 커서 안보이게

	EnemyInitialObject();

}

void EnemyAction() 
{            
	int i;
	for (i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].liveFlag)
		{
			if (enemy[i].pathnum == 0)
			{
				if (enemy[i].x == 1 && enemy[i].y == 1)         //현재위치가 1번이라면
				{
					enemy[i].pathnum = rand() % 3 + 1;          //pathnumber가 1-3중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 35 && enemy[i].y == 1)         //현재위치가 2번이라면
				{
					enemy[i].pathnum = rand() % 5 + 4;          //pathnumber가 4-8중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 75 && enemy[i].y == 1)         //현재위치가 3번이라면
				{
					enemy[i].pathnum = rand() % 3 + 9;          //pathnumber가 9-11중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 16 && enemy[i].y == 8)         //현재위치가 4번이라면
				{
					enemy[i].pathnum = rand() % 2 + 12;          //pathnumber가 12-13중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 58 && enemy[i].y == 8)         //현재위치가 5번이라면
				{
					enemy[i].pathnum = rand() % 2 + 14;          //pathnumber가 14-15중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 1 && enemy[i].y == 18)         //현재위치가 6번이라면
				{
					enemy[i].pathnum = rand() % 2 + 16;          //pathnumber가 16-17중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 35 && enemy[i].y == 18)         //현재위치가 7번이라면
				{
					enemy[i].pathnum = rand() % 3 + 18;          //pathnumber가 18-20중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
				if (enemy[i].x == 75 && enemy[i].y == 18)         //현재위치가 8번이라면
				{
					enemy[i].pathnum = rand() % 2 + 21;          //pathnumber가 21-22중 하나로 결정
					enemy[i].walknum = 0;                       //walknumber은 0부터 시작
				}
			}

			if (enemy[i].pathnum == 1)
			{
				enemy[i].x++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 34)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 2)
			{
				enemy[i].y++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 17)
				{
					enemy[i].pathnum = 0;
				}
			}
			if (enemy[i].pathnum == 3)
			{
				if (enemy[i].walknum < 15)
				{
					enemy[i].x++;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 15 && enemy[i].walknum<22)
				{
					enemy[i].y++;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 22)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 4)
			{
				enemy[i].x--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 34)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 5)
			{
				if (enemy[i].walknum < 19)
				{
					enemy[i].x--;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 19 && enemy[i].walknum < 26)
				{
					enemy[i].y++;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 26)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 6)
			{
				enemy[i].y++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 17)
				{
					enemy[i].pathnum = 0;
				}
			}
			if (enemy[i].pathnum == 7)
			{
				if (enemy[i].walknum < 23)
				{
					enemy[i].x++;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 23 && enemy[i].walknum < 30)
				{
					enemy[i].y++;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 30)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 8)
			{
				enemy[i].x++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 40)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 9)
			{
				enemy[i].x--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 40)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 10)
			{
				if (enemy[i].walknum < 17)
				{
					enemy[i].x--;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 17 && enemy[i].walknum < 24)
				{
					enemy[i].y++;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 24)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 11)
			{
				enemy[i].y++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 17)
				{
					enemy[i].pathnum = 0;
				}
			}
			if (enemy[i].pathnum == 12)
			{
				if (enemy[i].walknum < 7)
				{
					enemy[i].y--;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 7 && enemy[i].walknum < 22)
				{
					enemy[i].x--;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 22)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 13)
			{
				if (enemy[i].walknum < 7)
				{
					enemy[i].y--;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 7 && enemy[i].walknum < 26)
				{
					enemy[i].x++;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 26)
				{
					enemy[i].pathnum =0;
				}

			}
			if (enemy[i].pathnum == 14)
			{
				if (enemy[i].walknum < 7)
				{
					enemy[i].y--;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 7 && enemy[i].walknum < 30)
				{
					enemy[i].x--;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 30)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 15)
			{
				if (enemy[i].walknum < 7)
				{
					enemy[i].y--;
					enemy[i].walknum++;
				}

				if (enemy[i].walknum >= 7 && enemy[i].walknum < 24)
				{
					enemy[i].x++;
					enemy[i].walknum++;
				}
				if (enemy[i].walknum == 24)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 16)
			{
				enemy[i].y--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 17)
				{
					enemy[i].pathnum = 0;
				}
			}
			if (enemy[i].pathnum == 17)
			{
				enemy[i].x++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 34)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 18)
			{
				enemy[i].x--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 34)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 19)
			{
				enemy[i].y--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 17)
				{
					enemy[i].pathnum = 0;
				}
			}
			if (enemy[i].pathnum == 20)
			{
				enemy[i].x++;
				enemy[i].walknum++;
				if (enemy[i].walknum == 40)
				{
					enemy[i].pathnum = 0;
				}

			}
			if (enemy[i].pathnum == 21)
			{
				enemy[i].y--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 17)
				{
					enemy[i].pathnum = 0;
				}
			}
			if (enemy[i].pathnum == 22)
			{
				enemy[i].x--;
				enemy[i].walknum++;
				if (enemy[i].walknum == 40)
				{
					enemy[i].pathnum = 0;
				}

			}

		}
	}
}

void Draw()
{
	int i;
	for (i = 0; i < HEIGHT; i++)            // HEIGHT = 24
	{
		memset(screen[i], ' ', WIDTH);        //화면의  i번째 행들을 ' ' 공백으로 width의 길이만큼 넣어주고
		for (int j = 0; j < WIDTH; j++)
		{
			screen[i][j] = gamemap[i][j];
		}

		screen[i][WIDTH - 1] = NULL;            // 마지막 width칸에 NULL을 넣어준다.
	}


	DrawEnemy();        // 적비행기 출력
	drawselectimpo();

	Sleep(100);
	for (i = 0; i < HEIGHT; i++)
	{
		MoveCursor(0, i);        //  커서의 시작 지점 즉 y축을 바꾸어주며 한줄단위로 출력
		printf(screen[i]);        //    화면의 i번째행 을 출력   ==  printf("%s",screen[i]);

		MoveCursor(70, 23);
		printf("Left Imposter : %d", IMPO_NUM);
		MoveCursor(70, 24);
		printf("selectimpo.y : %d", selectimpo.y);

	}
}

void DrawEnemy() 
{       

	int i, j;
	int x=0, y=0;
	for (i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].liveFlag == 1)
		{
			x = enemy[i].x;
			y = enemy[i].y;
		}
		else if (enemy[i].liveFlag == 0)
		{
			x = 8;
			y = 21;
		}
		while (screen[y][x] != ' ' && screen[y][x] != '=' && screen[y][x] != '|' )
			x = x + 1;
		screen[y][x] = enemy[i].name;

	}
}

void EnemyInitialObject() 
{       
	int i = 0;
	for (i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].x = 35;
		enemy[i].y = 1;
		enemy[i].liveFlag = 1;       
		enemy[i].isimpo = 0;        
		enemy[i].pathnum = 0;
		enemy[i].walknum = 0;
		if (i == 0)
		{
			enemy[i].name = 'A';
		}
		if (i == 1)
		{
			enemy[i].name = 'B';
		}
		if (i == 2)
		{
			enemy[i].name = 'C';
		}
		if (i == 3)
		{
			enemy[i].name = 'D';
		}
		if (i == 4)
		{
			enemy[i].name = 'E';
		}
		if (i == 5)
		{
			enemy[i].name = 'F';
		}
		if (i == 6)
		{
			enemy[i].name = 'G';
		}
		if (i == 7)
		{
			enemy[i].name = 'H';
		}
		if (i == 8)
		{
			enemy[i].name = 'I';
		}
		if (i == 9)
		{
			enemy[i].name = 'J';
		}
	}
	int imponum=0;

	while (imponum != IMPO_NUM)
	{
		int random = rand() % ENEMY_NUM;
		if (enemy[random].isimpo == 0)
		{
			enemy[random].isimpo = 1;
			imponum++;
		}
		else
			continue;

	}
}

void CheckCrash()
{
	int i,j;
	for (i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].isimpo == 1)
		{
			for (j = 0; j < ENEMY_NUM; j++)
			{
				if (abs(enemy[i].x - enemy[j].x) <= 1 && abs(enemy[i].y - enemy[j].y) <= 1 && enemy[j].isimpo == 0)
				{
					enemy[j].liveFlag = 0;
				}
			}
		}
	}
}

/*int CheckEndGame()
	{

	}
 */

/*int CheckClearGame()
	{
	int i;
	for (i = 0; i < ENEMY_NUM; i++)
	{
	if (enemy[i].liveFlag == 1)
	{
	return 0;
	}
	}
	MoveCursor(36, 12);
	printf(" Stage Clear ");
	MoveCursor(0, 24);
	Sleep(1000);
	return 1;
	}*/
//------------------------------------------------------//




