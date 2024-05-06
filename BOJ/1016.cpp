#include <cstdio>
#define lli long long int
lli s,e,j; int i,c; bool p[1000005];
int main(){
    scanf("%lld%lld",&s,&e);
    for(i=2;i<=1000000;i++){
        lli sq=(lli)i*i;
        for(j=s/sq*sq;j<=e;j+=sq){
            if(j>=s)
                p[j-s]=1;
        }
    }
    for(i=0;i<e-s+1;i++){
        if(!p[i])
            c++;
    }
    printf("%d",c);
}
