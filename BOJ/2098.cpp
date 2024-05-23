#include <iostream>
#define M 20000000
using namespace std;
int n,FULL;
int w[17][17];
int dp[17][1<<16];
int value(int dst,int mask){
    int tmp=M;
    if(mask==FULL)
        return w[dst][0]==0?M:w[dst][0];
    if(dp[dst][mask]!=-1)
        return dp[dst][mask];
    for(int i=0;i<n;i++){
        if(w[dst][i]!=0&&(mask&(1<<i))==0)
            tmp=min(tmp,value(i,mask|(1<<i))+w[dst][i]);
    }
    dp[dst][mask]=tmp;
    return dp[dst][mask];
}
int main(){
    cin >> n;
    FULL=(1<<n)-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<1<<16;j++)
            dp[i][j]=-1;
        for(int j=0;j<n;j++)
            cin >> w[i][j];
    }
    cout << value(0,1<<0);
}