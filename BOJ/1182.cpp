#include <stdio.h>
#include <algorithm>
using namespace std;
int n,s;
int cnt;
int in[20];
void src(int p,int sum)
{
    if(sum==s)
    {
        cnt++;
    }
    if(p+1<n&&sum>s&&in[p+1]>0)
    {
        return;
    }
    for(int i=p+1;i<n;i++)
    {
        src(i,sum+in[i]);
    }
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    for(int i=0;i<n;i++)
        src(i,in[i]);
    printf("%d",cnt);
}
