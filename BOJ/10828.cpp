#include <stdio.h>
#include <string.h>

int stack[10000];
int t=0;

void push(int a)
{
	stack[t++]=a;
}

int pop()
{
	if(t<=0)
	{
		return -1;
	}
	else
	{
		return stack[(t--)-1];
	}
}

int top()
{
	if(t==0)
		return -1;
	else
		return stack[t-1];
}

int empty()
{
	if(t==0)
		return 1;
	else
		return 0;
}

int size()
{
	return t;
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
		else if(!strcmp(str,"top"))
			printf("%d\n",top());
		else if(!strcmp(str,"size"))
			printf("%d\n",size());
		else if(!strcmp(str,"empty"))
			printf("%d\n",empty());
	}
}
