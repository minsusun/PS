#include <iostream>
using namespace std;
typedef short s;
char vis[51][51],board[51][51],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
s N,M,dp[51][51];
s move(s x,s y){
    if(x>=N||x<0||y>=M||y<0||board[x][y]=='H') return 0;
    if(vis[x][y]){ cout<<-1; exit(0); }
    if(!dp[x][y]){
        vis[x][y]=true;
        s d=board[x][y]-'0';
        for(s i=0;i<4;i++)  dp[x][y]=max(dp[x][y],(s)(move(x+d*dx[i],y+d*dy[i])+1));
        vis[x][y]=false;
    }
    return dp[x][y];
}
int main(){
    cin>>N>>M; for(s i=0;i<N;i++) cin>>board[i];
    cout<<move(0,0);
}