#include <iostream>
#include <string>
using namespace std;
int dp[1010][1010];
int main(){
    string s1,s2,res;
    cin >> s1 >>  s2;
    for(int i=1;i<s1.length()+1;i++)
    {
        for(int j=1;j<s2.length()+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=s1.length(),j=s2.length();
    while(i&&j)
    {
        if(s1[i-1]==s2[j-1])
        {
            res.push_back(s1[i-1]);
            i-=1,j-=1;            
        }
        else
        {
            if(dp[i-1][j]>=dp[i][j-1])
                i-=1;
            else   
                j-=1;
        }
    }
    cout << dp[s1.length()][s2.length()];
    if(dp[s1.length()][s2.length()])
    {
        cout << endl;
        for(i=res.length()-1;i>=0;i--)
            cout << res[i];
    }
}