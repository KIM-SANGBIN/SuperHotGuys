#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<queue>
#include "path.h"

using namespace std;

typedef struct ITEM{
	int destination;
	pair<int, int> position;
	int player;
	int is_impo;
}item;


vector<item> v;

void Delay(int sec){
	clock_t start = clock();
	sec--;
	while(1){
		if((clock() - start)/CLOCKS_PER_SEC > sec)
			break;
	}
}

void Select_Impo(int player , int impo)
{
	int i=0 , random;
	while(1)
	{
		if(i==impo)
			return;
		srand(time(NULL));
		random = rand()% player;
		if(v[random].is_impo == 1)
			continue;
		else{
			v[random].is_impo = 1;
			i++;
		}		
	}


}

int main()
{
	char map[24][81], i, j;
	int map_player[24][81] ={0,};
	int player, imposter;
	for(i=0;i<24;i++){
		for(j=0;j<81;j++){
			map[i][j] = ' ';
		}
	}
	for(i=0;i<81;i++)
	{
		map[0][i] = '-';
		map[23][i] = '-';
	}
	for(i=0;i<24;i++)
	{
		map[i][0] = '-';
		map[i][80] = '-';
	
	}
	cout << "How many people play? : ";
	cin >> player;
	cout << "imposter number : ";
	cin >> imposter;
	

	item a;
	for(i=0;i<player;i++)
	{
		a.position = {0, 40};
		a.player = i+1;
		a.is_impo = 0;
		v.push_back(a);
	}

	Select_Impo(player, imposter);
	for(i=0;i<v.size();i++){
		cout << v[i].player << " "<< v[i].is_impo << endl;
	}

/*	for(int k=0;k<10;k++)
	{
		for(i=0;i<24;i++){
			cout<< "								";
			for(j=0;j<81;j++){
				cout << map[i][j];
			}
			cout << endl << endl;

		}
		for(i=0;i<1;i++)
			cout << endl;
		Delay(1);
		map[a.position.first][a.position.second] = ' ';
		map[b.position.first][b.position.second] = ' ';
		map[c.position.first][c.position.second] = ' ';
		a.position.first++;
		b.position.first++;
		c.position.first++;
		map[a.position.first][a.position.second] = a.player;
		map[b.position.first][b.position.second] = b.player;
		map[c.position.first][c.position.second] = c.player;
	}

	*/
	return 0;
}
