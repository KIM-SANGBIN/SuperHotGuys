#include <Windows.h>
#include <stdio.h>
#include "path.h"
#include <iostream>

HANDLE hPath;
using namespace std;

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
			//printmap(player);
			//			cout << player.x << " " <<player.y << endl;
			//					}
			//
			//							while (tmp_y--)
			//									{
			//												player.y += yidx * 1;
			//															cout << player.x << " " << player.y << endl;
			//																		//printmap(player);
			//																				}
			//																					}
			//
			//																						else
			//																							{
			//
			//
			//																									while (tmp_y--)
			//																											{
			//																														player.y += yidx * 1;
			//																																	//printmap(player);
			//																																			}
			//
			//																																					while (tmp_x--)
			//																																							{
			//																																										player.x += xidx * 1;
			//																																													//printmap(player);
			//																																															}
			//
			//
			//																																																}
			//
			//																																																}
			//
