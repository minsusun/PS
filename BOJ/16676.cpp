#include <stdio.h>
int main()
{
    int n,i,j,a;
    scanf("%d",&n);
    for(i=9;i>=1;i--)
    {
        a=1;
        for(j=1;j<=i;j++)
            a*=10;
             
        if(n>=(a-1)/9)
        {
            printf("%d",i);
            break;
        }
        else if(n==0)
        {
            printf("1");
            break;
        }
    }
}
