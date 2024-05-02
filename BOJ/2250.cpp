#include <iostream>
using namespace std;
bool nR[10002];
short T[10002][2],N,M,I[10002][2],mx,lv,w,a,b,c,i;
void src(short l,short V){
    mx=max(mx,l);
    if(T[V][0]!=-1) src(l+1,T[V][0]);
    I[l][0]=(!I[l][0])?++M:min(I[l][0],++M);
    I[l][1]=(!I[l][1])?M:max(I[l][1],M);
    if(T[V][1]+1) src(l+1,T[V][1]);
}
int main(){
    scanf("%hd",&N);
    for(i=0;i<N;i++){
        scanf("%hd%hd%hd",&a,&b,&c);
        T[a][0]=b,T[a][1]=c;
        if(b+1) nR[b]=true;
        if(c+1) nR[c]=true;
    }
    for(i=1;i<=N;i++) if(!nR[i]){ src(1,i); break; }
    for(i=1;i<=mx;i++) if(w<I[i][1]-I[i][0]+1) lv=i,w=I[i][1]-I[i][0]+1;
    printf("%hd %hd",lv,w);
}