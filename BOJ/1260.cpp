#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
int visit[1001];
int a,b,c,j,k,a1,a2;
int map[1001][1001];
void dfs(int o)
{
	int i;
	visit[o]=1;
	printf("%d ",o);
	for(i=1;i<=a;i++)
	{
		if(visit[i]!=1&&map[o][i]==1)
			dfs(i);
	}
}
void bfs(int l)
{
	int i,o;
	q.push(l);
	visit[l]=1;
	while(!q.empty())
	{
			o=q.front();
			q.pop();
			printf("%d ",o);
			for(i=1;i<=a;i++)
			{
				if(map[i][o]==1&&visit[i]!=1)
				{
					q.push(i);
					visit[i]=1;
				}
			}
	}
}
int main()
{
	int i;
	scanf("%d %d %d",&a,&b,&c); 
	for(i=1;i<=b;i++)
	{
		scanf("%d %d",&a1,&a2);
		map[a1][a2]=1;
		map[a2][a1]=1;
	}
	dfs(c);
	printf("\n");
	for(int i=0;i<1001;i++)
		visit[i]=0;
	bfs(c);
}
