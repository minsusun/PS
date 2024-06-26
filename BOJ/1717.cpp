#include <stdio.h>
int n,m;
int parent[1000001];
int h[1000001];
int find(int a)
{
	if(parent[a]==a)
		return a;
	return parent[a]=find(parent[a]);
}
void hap(int a,int b)
{
	int p1,p2;
	p1=find(a);
	p2=find(b);
	if(p1==p2)
		return;
	if(h[p1]>h[p2])
		parent[p2]=p1;
	else
		parent[p1]=p2;
	if(h[p1]==h[p2])
		h[p1]++;
}
bool same(int b,int c)
{
	if(find(b)==find(c))
		return true;
	else
		return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		parent[i]=i;
		h[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		switch(a)
		{
			case 0:
				hap(b,c);
				break;
			case 1:
				if(same(b,c))
					printf("YES\n");
				else
					printf("NO\n");
				break;
		}
	}
}
