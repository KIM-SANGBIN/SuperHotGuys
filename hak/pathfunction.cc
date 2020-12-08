#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct locate
{
	int x, y;
} locate;

void path(locate a, locate b, locate c, int i);
void printmap(locate a);
locate playerA, playerB;
locate sexparty = {1,2};
locate livingroom = {3,4};
int map[50][50];

void printmap(locate player)
{
	cout << player.x << " " << player.y << endl;
}




void path(locate start, locate end , locate player, int direction)
{

	int tmp_x = abs(start.x - end.x);
	int tmp_y = abs(start.y - end.y);
	int xidx = start.x > end.x ? -1 : 1;
	int yidx = start.y > end.y ? -1 : 1;

	if (direction == 1)
	{
		while (tmp_x--)
		{
			player.x += xidx * 1;
			printmap(player);
		}

		while (tmp_y--)
		{
			player.y += yidx * 1;
			printmap(player);
		}
	}

	else
	{


		while (tmp_y--)
		{
			player.y += yidx * 1;
			printmap(player);
		}

		while (tmp_x--)
		{
			player.x += xidx * 1;
			printmap(player);
		}


	}

}


int main()
{
	srand(time(NULL));
	playerA = livingroom;
	playerB = sexparty;

	//path(livingroom, sexparty, playerA, rand()%2);
	//	//path(sexparty, livingroom, playerB, rand()%2);
	//
	//		for (int i = 0; i < 1000; i++) {
	//				printf("난수 : %d \n", rand() % 2);
	//					}
	//						return 0;
	//						}
