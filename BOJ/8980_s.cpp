#include<bits/stdc++.h>
using namespace std;int C,M,a,b,c,P;struct x{int s,e,c;bool operator<(x p){return e==p.e?s>p.s:e<p.e;}};vector<x> S;int R[2001];int main(){cin>>C>>C>>M;while(M--){cin>>a>>b>>c;S.push_back({a,b,c});}sort(S.begin(),S.end());for(auto[f,s,c]:S){for(a=f;a++<s;)c=min(C-R[a],c);for(a=f;a++<s;)R[a]+=c;P+=c;}cout<<P;}
