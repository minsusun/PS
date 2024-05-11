#include <iostream>
#include <climits>
using namespace std;
int c,n;
int cost[21],customer[21];
int dp[1105];
int main(){
    cin >> c >> n;
    for(int i=1;i<=c+100;i++)   dp[i]=INT_MAX;
    for(int i=0;i<n;i++){
        cin >> cost[i] >> customer[i];
        for(int j=customer[i];j<=c+customer[i];j++) dp[j]=min((long long int)dp[j],(long long int)dp[j-customer[i]]+cost[i]);
        for(int j=0;j<=c+customer[i];j++){
            if(j%5==0)
                cout << endl;
            cout << j << ":";
            if(dp[j]==INT_MAX)
                cout << 0 << " ";
            else
                cout << dp[j] << " ";
        }
        cout << endl;
    }
    int m=dp[c];
    for(int i=c;i<=c+100;i++)  m=min(m,dp[i]);
    cout << m;
}
/*
100 2
7 12
20 30
-> 67
12+90
=> 7 + 20 *3
62 = 6*7 + 20
30 + 84

100 3
7 12
20 30
30 60
-> 57

12 2
3 5
1 1
-> 8

10 3
3 1
2 2
1 3
-> 4

10 10
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 10
-> 10

*/