#include <stdio.h>
int C,M,N,c,i,j,S;
short VA[1000001],PA[1001],PB[1001];
int main(){
    scanf("%d%d%d",&C,&M,&N);
    for(i=0;i<M;i++) scanf("%d",&PA[i]);
    for(i=0;i<N;i++) scanf("%d",&PB[i]);
    for(i=0;i<M;i++){ S=0; for(j=0;j<M-1;j++) VA[S+=PA[(i+j)%M]]++; }
    VA[0]=1,VA[S+PA[M-2]]++,c+=(C>=1000001)?0:VA[C];
    for(i=0;i<N;i++){ S=0; for(j=0;j<N-1;j++) if((S+=PB[(i+j)%N])<=C&&C-S<=1000000) c+=VA[C-S]; }
    if((S+=PB[N-2])<=C) c+=VA[C-S];
    printf("%d",c);
}