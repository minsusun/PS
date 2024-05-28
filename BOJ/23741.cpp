#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> v[1005];
vector<int> q;
int n,m,x,y;
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<v[x].size();i++)
		q.push_back(v[x][i]);
	for(int i=0;i<y-1;i++)
	{
		int visit[1005]={0,};
		int l=q.size();
		for(int j=0;j<l;j++)
		{
			int a=q[0];
			q.erase(q.begin());
			for(int k=0;k<v[a].size();k++)
			{
				if(visit[v[a][k]]==0)
				{
					q.push_back(v[a][k]);
					visit[v[a][k]]++;
				}
				
			}
		}
	}
	if(!q.size())
		printf("-1");
	else
	{
		sort(q.begin(),q.end());
		for(int i=0;i<q.size();i++)
			printf("%d ",q[i]);
	}
}
