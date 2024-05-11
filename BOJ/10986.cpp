#include <iostream>
int n,m,bef,aft,cnt[1001];
long long int sum;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&aft);
        aft=(bef+aft%m)%m,cnt[aft]++,bef=aft;
    }
    sum=cnt[0];
    for(int i=0;i<m;i++)
        sum+=std::max(cnt[i]*(cnt[i]-1LL)/2,0LL);
    printf("%lld",sum);
}
