#include <cstdio>
#include <cmath>
#include <algorithm>
#include<iostream>
using namespace std;
#include <cstdio>
int N, M, nSpike;
char mapaGlobal[41][41];
int global_visited[41][41];
int global_not[41][41];
bool flag = false;
typedef struct a{
	int x;
	int y;
}a;
int main()
{
	int mx[4] = {0, 0, 1, -1};
	int my[4] = {1, -1, 0, 0};
	bool IsValid(int x,int y);
	int recursive(int mx[4],int my[4],int x, int y, int count, int direct);
	a a;
	a.x = 0;
	a.y = 0;
	//int a = 0;
	//int b = 0;
	int aux;
	scanf("%d %d %d", &N, &M, &nSpike);
	for(int i=0; i<N; i++)
	{
		scanf("%s", mapaGlobal[i]);
		for(int j=0; j<M; j++)
		{
			if(mapaGlobal[i][j]=='@')
			{
				a.x = i;
				a.y = j;
			}
		}
	}
	flag = false;
	recursive(mx,my,a.x, a.y, 0, 1);
	flag ? aux = 1 : aux = 0;
	aux ? cout<<"SUCCESS" : cout<<"IMPOSSIBLE";
	return 0;
}
bool IsValid(int x,int y)
{
	if(x>=0){
		if(y>=0){
			if(x<N){
				if(y<M){
					return true;
				}
			}
		}
	}
	return false;
}
int recursive(int mx[4],int my[4],int x, int y, int count, int direct)
{
	if(count>nSpike){
		return 0;
	}
	direct==1 ? global_visited[x][y] = 1 : global_not[x][y] = 1;
	
	
	if(mapaGlobal[x][y]=='@'&&direct == 2)
	{
		flag = true;
		return 0;
	}
	if(mapaGlobal[x][y]=='x'&&direct == 1)
	{
		recursive(mx,my,x, y, count, 2);
		return 0;
	}
	for(int i=0; i<4; i++)
	{
		int tempx = x + mx[i];
		int tempy = y + my[i];
		if(IsValid(tempx,tempy))
		{
			if(mapaGlobal[tempx][tempy]!='#'){
			if((direct==1&&global_visited[tempx][tempy]==0)||(direct==2&&global_not[tempx][tempy]==0))
			{
					if(mapaGlobal[tempx][tempy]=='s'){
						recursive(mx,my,tempx, tempy, count + 1, direct);
					}
					else{ recursive(mx,my,tempx, tempy, count, direct);}
			}
			if(flag){
				return 0;
			}
			}
		}
	}
	direct==1 ? global_visited[x][y] = 0 : global_not[x][y] = 0;
} 