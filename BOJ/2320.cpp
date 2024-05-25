#include <iostream>
#include <string>
using namespace std;
int n,FULL;
int dp[17][1<<17];
string words[17];
int len[17];
int f(int node,int chk){
    int tmp=0;
    if(dp[node][chk]!=-1)
        return dp[node][chk];
    for(int i=0;i<n;i++){
        if(words[node][len[node]-1]==words[i][0]&&(chk&(1<<i))==0)
            tmp=max(tmp,f(i,chk|(1<<i)));
    }
    dp[node][chk]=tmp+len[node];
    return dp[node][chk];
}
int main(){
    int tmp=-1;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<1<<17;j++)
            dp[i][j]=-1;
        cin >> words[i];
        len[i]=words[i].length();
    }
    for(int i=0;i<n;i++)
        tmp=max(tmp,f(i,1<<i));
    cout << tmp;
}