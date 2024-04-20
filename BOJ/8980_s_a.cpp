#include <bits/stdc++.h>
using namespace std;int N,W,M,ans,v,i;int main(){cin>>N>>W>>M;tuple<int, int, int> A[M];for(auto&[r,l,w]:A)cin>>l>>r>>w,--l,--r;sort(A,A+M);int T[N]{};for(auto[r,l,w]:A){v=0;for(i=l;i++<r;)v=max(v,T[i]);ans+=w=min(w,W-v);for(i=l;i++<r;)T[i]+=w;}cout<<ans;}
