#include <stdio.h>
int k,n,max=-1;
int len[10100];
int f(long long int v)
{
	long long int cnt=0;
	for(int i=1;i<=k;i++)
		cnt+=len[i]/v;
	return cnt>=n;
}
int big(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	long long int ans=-1;
	long long int left,right,mid;
	scanf("%d%d",&k,&n);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&len[i]);
		if(max<len[i])
			max=len[i];
	}
	left=1;
	right=max;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(f(mid))
		{
			left=mid+1;
			ans=mid;
            
          
		}
		else
			right=mid-1;
	}
	printf("%lld",ans);
}
