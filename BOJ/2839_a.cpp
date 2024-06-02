#include <iostream>
using namespace std;
int n;
int dp[5010]={-1,-1,-1,1,-1,1};
int _M(int a,int b){
    if(a==-1)
        return b;
    else if(b==-1)
        return a;
    else
    {
        if(a>b)
            return b;
        else
            return a;
    }
}
int calc(int k){
    if(dp[k]!=0)
        return dp[k];
    else{
        int a=_M(calc(k-3),calc(k-5));
        if(a==-1)
            return a;
        else
        {
            dp[k]=a+1;
            return dp[k];
        }
    }
}
int main(){
    cin >> n;
    cout << calc(n);
}