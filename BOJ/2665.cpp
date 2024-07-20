#include <stdio.h>
#include <deque>
using namespace std;
deque<pair<int,int> > q;
int n; 
int map[50][50];
int min_map[50][50];
int min=-1;
bool visit[50][50];
int d_x[4]={1,0,-1,0};
int d_y[4]={0,1,0,-1};
inline bool chk(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n)
		return true;
	return false;
}
void src(int x,int y)
{
	q.push_back(make_pair(x,y));
	while(q.size()!=0)
	{
		pair<int,int> a=q.front();
		q.pop_front();
		for(int i=0;i<4;i++)
		{
			int newx=a.first+d_x[i];
			int newy=a.second+d_y[i];
			if(chk(newx,newy))
			{
				if(map[newx][newy]==1&&min_map[newx][newy]>min_map[a.first][a.second])
				{
					min_map[newx][newy]=min_map[a.first][a.second];
					q.push_front(make_pair(newx,newy));
				}
				if(map[newx][newy]==0&&min_map[newx][newy]>min_map[a.first][a.second]+1)
				{
					min_map[newx][newy]=min_map[a.first][a.second]+1;
					q.push_back(make_pair(newx,newy));
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
            char c;
            scanf(" %c",&c);
			map[i][j]=c-'0';
			min_map[i][j]=2500;
		}
	}
	min_map[0][0]=0;
	src(0,0);
	printf("%d",min_map[n-1][n-1]);
}
