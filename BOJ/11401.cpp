#include <iostream>
#define N 1000000007
#define ll long long int
using namespace std;
int n,r,dp[4000001]={1};
ll pow(ll a,int b){
    if(b==0) return 1;
    ll tmp=pow(a,b/2)%N;
    if(b%2==1) return tmp*tmp%N*a%N;
    else return tmp*tmp%N;
}
ll f(int a){
    if(dp[a]==0) dp[a]=(f(a-1)*a)%N;
    return dp[a];
}
int main(){
    cin >> n >> r;
    cout << f(n)*pow(f(r)*f(n-r)%N,N-2)%N;
}
