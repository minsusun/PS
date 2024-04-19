#include<bits/stdc++.h>
using namespace std;int N,Q,v,k,p,q,r,V[5001];vector<pair<int,int>> G[5001];int D(int n){int R=0;V[n]=1;for(auto[f,s]:G[n])R+=!V[f]&s>=k?D(f)+1:0;return R;}main(){cin>>N>>Q;for(;N-->1;)cin>>p>>q>>r,G[p].push_back({q,r}),G[q].push_back({p,r});while(Q--)cin>>k>>v,fill_n(V,5001,0),cout<<D(v)<<"\n";}
