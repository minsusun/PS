#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

stack<char> st;
stack<int> ln;

char arr[52];


int main()
{
	int sum=0;
	scanf("%s",arr);
	for(int i=0;i<strlen(arr);i++)
	{
		if(arr[i]==')')
		{
			int cnt=0;
			while(st.top()!='(')
			{
				if(st.top()=='/')
				{
					cnt+=ln.top();
					ln.pop();
				}
				else
					cnt++;
				st.pop();
			}
			st.pop();
			ln.push((st.top()-'0')*cnt);
			st.pop();
			st.push('/');
		}
		else
			st.push(arr[i]);
	}
	while(ln.size()!=0)
	{
		sum+=ln.top();
		ln.pop();
	}
	while(st.size()!=0)
	{
		if(st.top()=='/')
		{
			st.pop();
			continue;
		}
		sum++;
		st.pop();
	}
	printf("%d",sum);
}
