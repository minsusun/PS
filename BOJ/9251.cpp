#include <iostream>
#include <string>
using namespace std;
int dp[1010][1010];
int main(){
    string s1,s2;
    cin >> s1 >>  s2;
    for(int i=1;i<s1.length()+1;i++)
    {
        for(int j=1;j<s2.length()+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[s1.length()][s2.length()];
}