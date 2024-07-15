#include <stdio.h>
#include <stack>
using namespace std;
stack<int> st;
int k,a,sum=0;
int main()
{
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a);
		if(a==0)
			st.pop();
		else
			st.push(a);
	}
	int l=st.size();
	for(int i=0;i<l;i++)
	{
		sum+=st.top();
		st.pop();
	}
	printf("%d",sum);
}
