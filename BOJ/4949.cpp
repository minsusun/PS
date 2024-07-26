#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
char input[1000005];
bool chk()
{
	stack<int> st;
    int i;
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]=='['||input[i]==']'||input[i]=='('||input[i]==')')
		{
			if(input[i]=='(')
		{
			st.push(1);
		}
		else if(input[i]=='[')
		{
			st.push(2);
		}
		else if(st.size()==0)
		{
			return false;
		}
		else if(input[i]==')'&&st.top()==1)
		{
			st.pop();
		}
		else if(input[i]==']'&&st.top()==2)
		{
			st.pop();
		}
		else
		{
			return false;
		}
		}
		else
			continue;
	}
	if(input[i]=='\0')
	{
		if(st.size()==0)
			return true;
		else
			return false;
	}
}
int main()
{
	for(int i=0;;i++)
	{
		gets(input);
		if(!strcmp(input,"."))
			break;
		if(chk())
			printf("yes\n");
		else
			printf("no\n");
	}
}
