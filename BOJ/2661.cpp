#include<stdio.h>
int n,arr[81] {0,1},done;
int g(int a)
{
    int i,j,k,q=0;
    for(k=1; k<=a/2; k++)
    {
        q=0;
        for(i=a-k,j=a; j>a-k; i--,j--)
        {
            if(arr[i]!=arr[j]) q++;
        }
        if(q==0) return 0;
    }
    return 1;
}
void f(int a)
{
    int i,j,t;
    if(done) return;
    if(a>n)
    {
        for(i=1; i<=n; i++)
        {
            printf("%d",arr[i]);
        }
        done=1;
        return;
    }
    for(i=1; i<4; i++)
    {
        arr[a]=i;
        if(g(a)) f(a+1);
        if(done) return;
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    f(2);
}
