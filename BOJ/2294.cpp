#include <iostream>
#include <climits>
#define K_MAX 10005
using namespace std;
int n,k;
int v[100];
int dp[10001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<=k;i++)    dp[i]=K_MAX;
    for(int i=0;i<n;i++){
        cin >> v[i];
        for(int j=v[i];j<=k;j++)
            dp[j]=min(dp[j],dp[j-v[i]]+1);
    }
    if(dp[k]==K_MAX)
        cout << -1;
    else
        cout << dp[k];
}