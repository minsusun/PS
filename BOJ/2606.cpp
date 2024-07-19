#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n,p,cnt,visit[101];
vector<short> computer[101];
queue<short> q;
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=0;i<p;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		computer[a].push_back(b),computer[b].push_back(a);
	}
	visit[1]=1;
    for(auto &e:computer[1]) q.push(e);
	while(q.size())
	{
		int a=q.front();
		q.pop();
		if(visit[a]==0)	visit[a]=1,cnt++;
        for(auto &e:computer[a]) if(!visit[e]) q.push(e);
	}
	printf("%d",cnt);
}
