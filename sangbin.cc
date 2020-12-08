
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
	"===============================================================================\n"
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
void PlayerInitialObject();
void PlayerAction();
void EnemyAction();
void DrawEnemy();
void Draw();
int CheckEndGame();
int CheckClearGame();
void EnemyInitialObject();
//----------------------------------------//

//----------------함수들--------------//


struct PlayerInfo
{
	int x, y;
	int liveFlag;        // 플레이어가 살았는지를 나타낸다. 1로초기화시키고 죽으면 0이되어 게임을 끝낸다.
};

struct EnemyInfo {
	int x, y;
	int liveFlag;
	int StartX;           //    기준점좌표값 x - StartX 절대값을 구해서.
	int StartY;
	int movex;
	int movey;
	int ismoving;
	char name;
	int isimpo;
	int pathnum;            //경로지정
	int walknum;            //경로 내에서 걸어간 횟수
};

struct startinfo
{
	int x, y;
};


struct startinfo startgame;
struct PlayerInfo player;
struct EnemyInfo enemy[ENEMY_NUM];

//--------------------struct-----------------------//

void main()
{
	srand((unsigned)time(NULL));
	Initial();
	startgameinitialobject();
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
	while (stagecount == 1)
	{
		if (stagecount == 1)
		{
			EnemyAction();
			//PlayerAction();

			Draw();
			/*if (CheckEndGame() == 1)
				break;
				if (CheckClearGame() == 1)
				stagecount++;*/
		}
		Sleep(5);
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

void startgameinitialobject()
{
	startgame.x = 32;
	startgame.y = 21;
	int x = startgame.x;
	int y = startgame.y;
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

void PlayerInitialObject()
{        //플레이어 비행기 좌표설정 (1대이므로 지정해준다.)
	player.x = 39;
	player.y = 19;

	player.liveFlag = 1;        // 1로 설정해주어 죽으면 0으로 바뀌게끔 설정
}

void SetStartPosition() {

	Initial();                    // 커서 안보이게
	PlayerInitialObject();        // 플레이어 비행기 시작 좌표 설정
	EnemyInitialObject();

}

void PlayerAction() {            // 플레이어 비행기 이동 함수

	if (player.liveFlag == 1)
	{
		if ((GetAsyncKeyState(VK_UP) & 0x8000))        //GetAsyncKeyState는 short값으로 입력이 되었으면 맨앞비트가 1 아니면 0을 리턴
		{                                                //0x8000은 16진수로 short값의 맨앞만 1인상태이므로

		}
		if ((GetAsyncKeyState(VK_DOWN) & 0x8000))
		{

		}

		if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
		{

		}
	}
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

	Sleep(100);
	for (i = 0; i < HEIGHT; i++)
	{
		MoveCursor(0, i);        //  커서의 시작 지점 즉 y축을 바꾸어주며 한줄단위로 출력
		printf(screen[i]);        //    화면의 i번째행 을 출력   ==  printf("%s",screen[i]);

		MoveCursor(70, 23);
		printf("%d", 1000000);

	}
}

void DrawEnemy() 
{       
	/*
		 int i, j;
		 int x, y;

		 for (i = 0; i < ENEMY_NUM; i++)
		 {
		 if (enemy[i].liveFlag == 1)
		 {
		 x = enemy[i].x - E_COUNT / 2;
		 y = enemy[i].y;

		 if (y < 0 || y >= HEIGHT)
		 continue;

		 for (j = 0; j < E_COUNT; j++)
		 {
		 if (x >= 0 && x < WIDTH - 1)
	//screen[y][x] = eUnit[j];
	screen[y][x] = enemy[i].name;
	x++;
	}
	}
	}*/
	int i, j;
	int x=0, y=0;
	for (i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].liveFlag == 1)
		{
			x = enemy[i].x;
			y = enemy[i].y;
		}
		while (screen[y][x] != ' ' && screen[y][x] != '=' && screen[y][x] != '|' )
			x = x + 1;
		screen[y][x] = enemy[i].name;

	}
}

void EnemyInitialObject() 
{        // 적 비행기 좌표설정    ( i 는 적비행기 객체, j 행 , k 열 ) 
	/*
		 int i = 0;
		 for (int j = 0; j < ENEMY_LINE; j++)
		 {
		 for (int k = 0; k < ENEMY_FLIGHT; k++)
		 {
		 enemy[i].x = 17 + 5 * k;
		 enemy[i].y = 3 + 2 * j;
		 enemy[i].liveFlag = 1;
		 enemy[i].StartX = enemy[i].x;    //enemy[i]의 x좌표와 처음 동일시
		 enemy[i].StartY = enemy[i].y;
		 enemy[i].MoveFlag = 1;

		 i++;
		 }
		 }
	 */
	int i = 0;
	for (i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].x = 1;
		enemy[i].y = 1;
		enemy[i].liveFlag = 1;
		enemy[i].StartX = enemy[i].x;
		enemy[i].StartY = enemy[i].y;
		enemy[i].isimpo = 0;
		enemy[i].ismoving = 0;
		enemy[i].movex = 0;
		enemy[i].movey = 0;
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

int CheckEndGame()
{

	if (player.liveFlag == 0)
	{
		MoveCursor(36, 12);
		printf(" Game Over ");
		Sleep(1000);
		MoveCursor(0, 24);
		return 1;
	}
}


int CheckClearGame()
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
}
//------------------------------------------------------//




