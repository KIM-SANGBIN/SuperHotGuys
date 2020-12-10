#define _CRT_SECURE_NO_WARNINGS
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
#include <chrono>

using namespace std;

char screen[HEIGHT][WIDTH];        //    [행][열]
char gamemap[HEIGHT][WIDTH] =
{
   "==============================================================================|\n",
   "(                                                                             )\n",
   ")   )==========)   )==============(   (==================(   (============)   )\n",
   "(   (          (   (              )   )          *       )   )            (   (\n",
   ")   )  *       )   )        *     (   (      *     *     (   (      *     )   )\n",
   "(   (       *  (   (  *           )   )   *              )   ) *       *  (   (\n",
   ")   )     *    )   )    *     *   (   (          *       (   (   *        )   )\n",
   "(   (  *       (   (      *       )   )    *        *    )   )    *       (   (\n",
   ")   )        * )   )              (   (         *        (   (  *      *  )   )\n",
   "(   (          (===(     *        )   )            *     )===)            (   (\n",
   ")   )     *                *      (   (       *              *     *  *   )   )\n",
   "(   (   *         *               )   )     *        *        *           (   (\n",
   ")   )          *    *      *      (   (            *       *       *      )   )\n",
   "(   (                             )   )      *    *    *             *    (   (\n",
   ")   )      *             *        (   (        *     *             *  *   )   )\n",
   "(   (    *           *            )   )           *           *           (   (\n",
   ")   )                             (   (                  *                )   )\n",
   "(   (=============================)   )===================================(   (\n",
   ")                                                                             )\n",
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
   "     @@@@@@*@=====@@@@@@@@                   .@@@@@                            \n",
   "     @@@@@@===!!!====@@@@@                  @!     @@                          \n",
   "     @@@@==;,.,,-,.:==@@@@                 @        @@ -$*                     \n",
   "     @@@=*,---,,,--,.*=@@@               ,@           @= ~!                    \n",
   "     @@==,,-.  @  .,-,*=@@               @            =$ ~~                    \n",
   "     @@=,-,    @    .-,=@@               @            =$:~~                    \n",
   "     @=:--     @@    ,-~=@               @         ,   #@~ :.                  \n",
   "     @=--     .@@@    -,=@              -@       :~#@  ,@@- $                  \n",
   "     @*--     ,@@@@   ,-;@              :@    .=@: .#~  -@$ ,:                 \n",
   "     @;-,      @@@@@  .-:@              :@**@=*~.    #   =@; #.                \n",
   "     @;-.    . @@@@@@ .-~@              ~@@.-~~,,,   #.   @@  :                \n",
   "     @;-, @@@@@@,.    .-:@            . -@@~~~~~~,   #;   !@$ =     .          \n",
   "     @*:-  @@@@@,     ,~!@         .    ,@@;~~~~~~~~ $,    @@  :    .          \n",
   "     @=~-   @@@@.     -:=@         .     @@;~~~~~~~;##     !@= #               \n",
   "     @=:~-   @@@     ,-:=@         .     @@@*****=$;       -@@ @               \n",
   "     @@=:-,   @@    .-;*$@         .     @@@@=!~            #@@*               \n",
   "     @@$*;--.  @   ,-;*=@@         .     @@@@               ,@@:               \n",
   "     @@@==;~--,..--~;*=@@@         .     @@@@                @@.  .            \n",
   "     @@@@==!!;:~~;!!==@@@@               @@@@                @##               \n",
   "     @@@@@@===!!!*==@@@@@@         .     @@@@                @##               \n",
   "     @@@@@@@@$====@@@@@@@@                                                     \n"

};
char mainscreen[HEIGHT][WIDTH] = {

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
char findmap[HEIGHT][WIDTH] =
{
   "                     =@@@ ;=$@                                                \n",
   "                      =@ *@  @              @@@  @@@   @   @@@                \n",
   "                       @   .@               @  @ @    @ @  @  @               \n",
   "                        *  =                @  @ @@@ @@@@@ @  @               \n",
   "                        @  @      @@##      @  @ @   @   @ @  @               \n",
   "                        @. #     @.   #     @@@  @@@ @   @ @@@                \n",
   "                  @@@#@# ,. # ,@#@-    @                                      \n",
   "                  @  ,@#@#$#@@-   @    =    @@@  @@@ @@@@   @@  @@@  @@@@@    \n",
   "                  @               $    *    @  @ @   @   @ @  @ @  @   @      \n",
   "                  @               =    !    @@@  @@@ @@@@  @  @ @@@    @      \n",
   "                  $               $    !    @  @ @   @     @  @ @  @   @      \n",
   "                  @               $    !    @  @ @@@ @      @@  @  @   @      \n",
   "                  @               $    !     ||||     ||||     ||||           \n",
   "                  *               $    !   - @@@@ -   @@@@ -   @@@@ -         \n",
   "                  #               #    @    @   @@   @   @@   @   @@  -       \n",
   "                  @               #   =!    @ @@ @   @ @@ @   @ @@ @  -       \n",
   "                  @   @@@@@@@     #*#@@      @@@@     @@@@     @@@@  -        \n",
   "                  $     @   @     @           @@       @@       @@  -         \n",
   "                  @     @   @     @           ::       :;       ::            \n",
   "                   #    @   @     @           @@       @@       @@            \n",
   "                   @   .-   @     @                                           \n",
   "                   !===@@   @=====*                                           \n"
};
#define Enemy_NUM 10
#define E_COUNT 3
#define Enemy_LINE 3
#define Enemy_FLIGHT 10
#define IMPO_NUM 2

int stagecount = 0;
char startcursor[3] = ">>";
char eUnit[E_COUNT + 1] = "=.=";
int find_dead = 0;

//---------------함수들-------------//
int StartGame_Action2();
int Check_DeadPerson();
int Check_EndGame();
int Check_ClearGame();
int Find_DeadBody();
void StartGame_Action();
void StartGame_Initialobject();
void DrawMain();
void DrawStartGame();
void SetStartPosition();
void Check_ImpoNum();
void Check_PersonNum();
void EnemyAction();
void Drawenemy();
void Draw();
void EnemyInitialObject();
void CheckCrash();
void Select_ImpoObject();
void Select_ImpoAction();
void Select_ImpoAction2();
void Draw_SelectImpo();
void ShowFind();
//----------------------------------------//

//----------------함수들--------------//


struct Impo_Info
{
    int num;
};

struct Person_Info
{
    int num;
};
struct Enemy_Info {
    int x, y;
    int liveFlag;
    char name;
    int isimpo;
    int pathnum;            //경로지정
    int walknum;            //경로 내에서 걸어간 횟수
    int finish = 0;
};

typedef struct Dead_Body {
    int x, y, already = 0;
    char name;
}DeadBody;



struct Start_Info
{
    int x, y;
};

struct Select_Info
{
    int x, y;
};
struct Person_Info person;
struct Start_Info startgame;
struct Impo_Info imposter;
struct Enemy_Info enemy[Enemy_NUM];
struct Select_Info selectimpo;
DeadBody dead_info[Enemy_NUM];
//--------------------struct-----------------------//

int main()
{
    int i, dead_index;
    int report_x, report_y;
    srand((unsigned)time(NULL));
    Initial();
    StartGame_Initialobject();
    while (1)
    {
        int count = 0;
        int lightoff = 0;
        ClearScreen();
        while (stagecount == 0)
        {


            StartGame_Action();
            DrawMain();
            if (StartGame_Action2() == 1)
                stagecount++;
            else if (StartGame_Action2() == 2)
                break;

            Sleep(100);

            SetStartPosition();
            Select_ImpoObject();
        }
        while (stagecount == 1)
        {
            Initial();

            EnemyAction();

            if (find_dead == 0 && (count >= 40) && (count % 40 >= 0) && (count % 100 <= 20))
                lightoff = 1;

            if (!lightoff)
            {
                Draw();
            }
            if (lightoff)           //전등 꺼지는 시간
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
                }
                CheckCrash();
                dead_index = Find_DeadBody();
                if (find_dead)
                {
                    stagecount = 2;
                    ClearScreen();
                    ShowFind();
                    Sleep(4000);
                    find_dead = 0;
                    lightoff = 0;
                    break;
                }


            }
            if (Check_ClearGame() == 1)
                break;
            Sleep(1);
            count++;
        }
        while (stagecount == 2)
        {
            MoveCursor(5, 35);
            cout << "DEAD BODY " << dead_info[dead_index].name << " Founded" << endl;
            MoveCursor(5, 37);
            cout << dead_info[dead_index].name << "가 죽어버렸당께!";
            int i;
            report_x = dead_info[dead_index].y; report_y = dead_info[dead_index].x;
            Draw();
            Draw_SelectImpo();
            MoveCursor(report_y, report_x);
            cout << "♧" << dead_info[dead_index].name << "♧ <=여기 조용히 묻히다..";
            Select_ImpoAction();
            Select_ImpoAction2();
            find_dead = 0;
        }

        if (Check_EndGame() == 1)
            break;
        if (Check_ClearGame() == 1)
            break;

        Sleep(50);

    }
    return 0;
}

void StartGame_Action()
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

void Select_ImpoAction()
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

void StartGame_Initialobject()
{
    startgame.x = 32;
    startgame.y = 21;
    int x = startgame.x;
    int y = startgame.y;
}

void Select_ImpoObject()
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
            mainscreen[y][x] = startcursor[i];
        x++;
    }
}

void Draw_SelectImpo()
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


void ShowFind()
{
    int i;
    for (i = 0; i < HEIGHT; i++)            // HEIGHT = 24
    {
        memset(screen[i], ' ', WIDTH);        //화면의  i번째 행들을 ' ' 공백으로 width의 길이만큼 넣어주고
        for (int j = 0; j < WIDTH; j++)
        {
            screen[i][j] = findmap[i][j];
        }
        screen[i][WIDTH - 1] = NULL;            // 마지막 width칸에 NULL을 넣어준다.
    }
    for (i = 0; i < HEIGHT; i++)
    {
        MoveCursor(0, i);        //  커서의 시작 지점 즉 y축을 바꾸어주며 한줄단위로 출력
        printf(screen[i]);        //    화면의 i번째행 을 출력   ==  printf("%s",screen[i]);
    }
}


void DrawMain()
{
    int i;
    for (i = 0; i < HEIGHT; i++)
    {
        strcpy(mainscreen[21], "                                  Start Game                                   \n");
        strcpy(mainscreen[22], "                                  End Game                                     \n");
        mainscreen[i][WIDTH - 1] = NULL;
    }

    DrawStartGame();

    for (i = 0; i < HEIGHT; i++)
    {
        MoveCursor(0, i);
        printf(mainscreen[i]);
    }
}

int StartGame_Action2()
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

void Select_ImpoAction2()
{
    if (stagecount == 2)
    {
        if ((GetAsyncKeyState(VK_RETURN) & 0x8000))
        {
            if (selectimpo.y == 20)
            {
                if (enemy[0].isimpo == 1)
                {
                    enemy[0].liveFlag = 0;
                    enemy[0].finish = 1;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[0].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[0].liveFlag = 0;
                    enemy[0].finish = 1;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[0].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 21)
            {
                if (enemy[1].isimpo == 1)
                {
                    enemy[1].liveFlag = 0;
                    enemy[1].finish = 1;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[1].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[1].liveFlag = 0;
                    enemy[1].finish = 1;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[1].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 22)
            {
                if (enemy[2].isimpo == 1)
                {
                    enemy[2].finish = 1;
                    enemy[2].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[2].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[2].finish = 1;
                    enemy[2].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[2].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 23)
            {
                if (enemy[3].isimpo == 1)
                {
                    enemy[3].finish = 1;
                    enemy[3].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[3].name);


                    Sleep(1000);
                }
                else
                {
                    enemy[3].finish = 1;
                    enemy[3].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[3].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 24)
            {
                if (enemy[4].isimpo == 1)
                {
                    enemy[4].finish = 1;
                    enemy[4].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[4].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[4].finish = 1;
                    enemy[4].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[4].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 25)
            {
                if (enemy[5].isimpo == 1)
                {
                    enemy[5].finish = 1;
                    enemy[5].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[5].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[5].finish = 1;
                    enemy[5].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[5].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 26)
            {
                if (enemy[6].isimpo == 1)
                {
                    enemy[6].finish = 1;
                    enemy[6].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[6].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[6].finish = 1;
                    enemy[6].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[6].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 27)
            {
                if (enemy[7].isimpo == 1)
                {
                    enemy[7].finish = 1;
                    enemy[7].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[7].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[7].finish = 1;
                    enemy[7].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[7].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 28)
            {
                if (enemy[8].isimpo == 1)
                {
                    enemy[8].finish = 1;
                    enemy[8].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[8].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[8].finish = 1;
                    enemy[8].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[8].name);

                    Sleep(1000);
                }
            }
            if (selectimpo.y == 29)
            {
                if (enemy[9].isimpo == 1)
                {
                    enemy[9].finish = 1;
                    enemy[9].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is Imposter!", enemy[9].name);

                    Sleep(1000);
                }
                else
                {
                    enemy[9].finish = 1;
                    enemy[9].liveFlag = 0;
                    MoveCursor(30, 25);
                    printf("%c is not Imposter!", enemy[9].name);

                    Sleep(1000);
                }
            }

            stagecount = 1;
            for (int z = 0; z < Enemy_NUM; z++)
            {
                if (enemy[z].liveFlag == 1)
                {
                    enemy[z].x = 35;
                    enemy[z].y = 1;
                    enemy[z].walknum = 0;
                    enemy[z].pathnum = 0;
                }
            }
            ClearScreen();
        }

    }
}



void SetStartPosition() {

    Initial();                    // 커서 안보이게
    imposter.num = IMPO_NUM;
    person.num = Enemy_NUM;
    EnemyInitialObject();
}

void EnemyAction()
{
    int i;
    for (i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].liveFlag && enemy[i].finish == 0)
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

                if (enemy[i].walknum >= 15 && enemy[i].walknum < 22)
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
                    enemy[i].pathnum = 0;
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

    Drawenemy();
    Draw_SelectImpo();

    Sleep(100);
    for (i = 0; i < HEIGHT; i++)
    {
        MoveCursor(0, i);        //  커서의 시작 지점 즉 y축을 바꾸어주며 한줄단위로 출력
        printf(screen[i]);        //    화면의 i번째행 을 출력   ==  printf("%s",screen[i]);

        MoveCursor(60, 23);
        Check_ImpoNum();
        printf("Left Imposter : %d", imposter.num);
        MoveCursor(60, 24);
        Check_PersonNum();
        printf("Left Person : %d", person.num);

    }
}

void Drawenemy()
{

    int i;
    int x = 0, y = 0;
    for (i = 0; i < Enemy_NUM; i++)
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
        while (screen[y][x] != ' ' && screen[y][x] != '=' && screen[y][x] != '|')
            x = x + 1;
        screen[y][x] = enemy[i].name;

    }
}


void EnemyInitialObject()
{
    int i = 0;
    for (i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].finish != 1)
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
    }
    Check_ImpoNum();

    if (imposter.num == 0)
    {
        int imponum = 0;
        while (imponum != IMPO_NUM)
        {
            int random = rand() % Enemy_NUM;
            if (enemy[random].isimpo == 0)
            {
                enemy[random].isimpo = 1;
                imponum++;
            }
            else
                continue;
        }
    }
}

void Check_ImpoNum()
{
    int count = 0;
    for (int i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].isimpo && enemy[i].liveFlag)
        {
            count++;
        }
    }
    imposter.num = count;
}

void Check_PersonNum()
{
    int count = 0;
    for (int i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].isimpo == 0 && enemy[i].liveFlag)
        {
            count++;
        }
    }
    person.num = count;
}

int Check_DeadPerson()
{
    int count = 0;
    for (int i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].isimpo == 0 && enemy[i].liveFlag == 0)
        {
            count++;
        }
    }
    return count;
}

void CheckCrash()
{
    int i, j;
    for (i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].isimpo == 1)
        {
            for (j = 0; j < Enemy_NUM; j++)
            {
                if (abs(enemy[i].x - enemy[j].x) <= 1 && abs(enemy[i].y - enemy[j].y) <= 1 && enemy[j].isimpo == 0)
                {
                    DeadBody a;
                    a.x = enemy[j].x;
                    a.y = enemy[j].y;
                    a.name = enemy[j].name;
                    enemy[j].finish = 1;
                    enemy[j].liveFlag = 0;
                    dead_info[j] = a;
                    Sleep(100);
                    break;
                }
            }
        }
    }
}

int Find_DeadBody()
{
    int i, x, y, j;
    for (i = 0; i < Enemy_NUM; i++)
    {
        if (enemy[i].isimpo == 0 && enemy[i].liveFlag == 1)
        {
            for (j = 0; j < Enemy_NUM; j++)
            {
                if (dead_info[j].already == 0 && enemy[i].x == dead_info[j].x && enemy[i].y == dead_info[j].y && find_dead == 0)
                {
                    for (int p = 0; p < Enemy_NUM; p++)
                    {
                        if (enemy[p].liveFlag == 0) dead_info[p].already = 1;
                    }
                    find_dead = 1;
                    return j;
                }
            }
        }
    }
    return 0;
}



int Check_EndGame()
{
    Check_PersonNum();
    Check_ImpoNum();
    if (person.num == imposter.num)
    {
        MoveCursor(1, 1);

        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("   @@@@@@@@@@@@@@@@@      @@@        @@@@@@@@@@   @@              @@@@            \n");
        printf("   @@@@@@@@@@@@@@@@@     @@ @@       @@@@@@@@@@   @@              @@@@            \n");
        printf("   @@                    @@ @@           @@       @@              @@@@            \n");
        printf("   @@                   @@   @@          @@       @@              @@@@            \n");
        printf("   @@                  @@     @@         @@       @@              @@@@            \n");
        printf("   @@                 @@       @@        @@       @@              @@@@            \n");
        printf("   @@@@@@@@@@@@@@@@@  @@@@@@@@@@@        @@       @@              @@@@            \n");
        printf("   @@@@@@@@@@@@@@@@@  @@@@@@@@@@@        @@       @@              @@@@            \n");
        printf("   @@                @@         @@       @@       @@              @@@@            \n");
        printf("   @@                @@         @@       @@       @@              @@@@            \n");
        printf("   @@                @@         @@       @@       @@              @@@@            \n");
        printf("   @@                @@         @@       @@       @@                              \n");
        printf("   @@                @@         @@   @@@@@@@@@@   @@@@@@@@@@@@@@  @@@@            \n");
        printf("   @@                @@         @@   @@@@@@@@@@   @@@@@@@@@@@@@@  @@@@            \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        MoveCursor(0, 24);
        Sleep(10000);

        return 1;

    }

    else
        return 0;
}


int Check_ClearGame()
{
    Check_ImpoNum();
    if (imposter.num == 0)
    {
        MoveCursor(1, 1);

        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("     @@@@@@@@@  @@        @@@@@@@@@@      @@@       @@@@@@@@@@@@@      @@@@       \n");
        printf("    @@@@@@@@@@  @@        @@@@@@@@@@     @@ @@      @@          @@     @@@@       \n");
        printf("   @@           @@        @@            @@   @@     @@           @@    @@@@       \n");
        printf("   @@           @@        @@           @@     @@    @@           @@    @@@@       \n");
        printf("   @@           @@        @@@@@@@@@@  @@       @@   @@           @@    @@@@       \n");
        printf("   @@           @@        @@@@@@@@@@  @@@@@@@@@@@   @@          @@     @@@@       \n");
        printf("   @@           @@        @@          @@@@@@@@@@@   @@@@@@@@@@@@@      @@@@       \n");
        printf("   @@           @@        @@         @@         @@  @@          @@     @@@@       \n");
        printf("   @@           @@        @@         @@         @@  @@           @@ .             \n");
        printf("   @@           @@        @@         @@         @@  @@           @@    @@@@       \n");
        printf("    @@@@@@@@@@  @@@@@@@@@ @@@@@@@@@@ @@         @@  @@           @@    @@@@       \n");
        printf("     @@@@@@@@@  @@@@@@@@@ @@@@@@@@@@ @@         @@  @@           @@    @@@@       \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");
        printf("                                                                                  \n");


        Sleep(10000);
        return 1;
    }
    else return 0;
}
//------------------------------------------------------//