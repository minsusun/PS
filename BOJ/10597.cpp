#include <bits/stdc++.h>
char var[100],len;
int check[100]={0};
int temp[100];
void dfs(int a, int tmpidx){
    if (a==len)
    {
        for (int i=0; i<tmpidx; i++)
            printf("%d ",temp[i]);
        printf("\n");
        exit(0);
    }
    if (var[a]!=0 && check[var[a]]==0) {
        temp[tmpidx]=var[a];
        check[var[a]]=1;
        dfs(a + 1, tmpidx+1);
        check[var[a]]=0;
    }
    if (var[a]*10 + var[a+1]<=9+(len-9)/2 && check[var[a]*10+var[a+1]]==0)
    {
        temp[tmpidx]=var[a]*10 + var[a+1];
        check[var[a]*10+var[a+1]]=1;
        dfs(a + 2, tmpidx+1);
        check[var[a]*10+var[a+1]]=0;
    }
 
}
int main()
{
    scanf("%s",var);
    len=strlen(var);
    for (int i=0; i<len; i++)
        var[i]-='0';
    dfs(0, 0);
}
