#include <stdio.h>
int surab[300001];
int chk[300001];
int n,l;
int find(int a)
{
	if(surab[a]==a)
		return a;
	return surab[a]=find(surab[a]);
}
bool _union(int a,int b)
{
	if(chk[find(a)]==0)
	{
		chk[find(a)]=1;
		surab[find(a)]=find(b);
	}
	else if(chk[find(b)]==0)
	{
		chk[find(b)]=1;
		surab[find(b)]=find(a);
	}
	else
		return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=l;i++)
		surab[i]=i;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(_union(a,b))
			printf("LADICA\n");
		else
			printf("SMECE\n");
	}
}
