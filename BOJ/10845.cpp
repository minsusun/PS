#include <stdio.h>
#include <string.h>

int que[10000];
int f=0,r=0;

void push(int a)
{
	que[r++]=a;
}

int pop()
{
	if(f==r)
	{
		return -1;
	}
	else
	{
		return que[(f++)];
	}
}

int front()
{
	if(f==r)
	{
		return -1;
	}
	else
	{
		return que[f];
	}
}

int back()
{
	if(f==r)
	{
		return -1;
	}
	else
	{
		return que[r-1];
	}
}

int empty()
{
	if(f==r)
		return 1;
	else
		return 0;
}

int size()
{
	return r-f;
}

int main()
{
	char str[10];
	int n;
	int a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		if(!strcmp(str,"push"))
		{
			scanf("%d",&a);
			push(a);
		}
		else if(!strcmp(str,"pop"))
			printf("%d\n",pop());
		else if(!strcmp(str,"front"))
			printf("%d\n",front());
		else if(!strcmp(str,"back"))
			printf("%d\n",back());
		else if(!strcmp(str,"size"))
			printf("%d\n",size());
		else if(!strcmp(str,"empty"))
			printf("%d\n",empty());
	}
}
