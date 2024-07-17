#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[101];
vector<int> ans;
bool visit[101];
void dfs(int node,int start)
{
	if(visit[node]==true&&node==start)
	{
		ans.push_back(node);
		return;
	}
	else if(visit[node]==true)
		return;
	visit[node]=true;
	for(int i=0;i<v[node].size();i++)
		dfs(v[node][i],start);
	visit[node]=false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[i].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,i);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
}




