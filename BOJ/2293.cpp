#include <iostream>
using namespace std;
// n ~100 k ~10000 v[i] ~100000
int n,k;
int v[100];
int dp[100001];
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        dp[v[i]]++;
        for(int j=v[i];j<=k;j++)
            dp[j]+=dp[j-v[i]];
    }
    cout << dp[k];
}