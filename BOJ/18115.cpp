#include <stdio.h>
#include <deque>
using namespace std;
deque<int> dq;
int cmd[1000005];
void one(int n)
{
	dq.push_back(n);
}
void two(int n)
{
	int a=dq.back();
	dq.pop_back();
	dq.push_back(n);
	dq.push_back(a);
}
void three(int n)
{
	dq.push_front(n);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&cmd[i]);
	for(int i=n-1;i>=0;i--)
	{
		switch(cmd[i])
		{
			case 1:
				one(n-i);
				break;
			case 2:
				two(n-i);
				break;
			case 3:
				three(n-i);
				break;
		}
	}
	int l=dq.size();
	for(int i=0;i<l;i++)
	{
		int a=dq.back();
		printf("%d ",a);
		dq.pop_back();
	}
}
