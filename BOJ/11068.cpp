#include <stdio.h>
int t,len;
int s[21];
int conv(int n,int base)
{
	int i=0;
	while(n!=0)
	{
		s[i++]=n%base;
		n/=base;
	}
	return i;
}
bool cmp(int l)
{
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[l-i-1])
			return false;
	}
	return true;
}
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int tmp,result;
		scanf("%d",&tmp);
		for(int b=2;b<65;b++)
		{
			len=conv(tmp,b);
			result=cmp(len);
			if(result==true)
				break;
		}
		printf("%d\n",result);
	}
}
