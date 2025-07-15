#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v[200002];
    queue<int> q;
    int T[200002],n[200002],N,M,i,p,a;
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N;
    for(i=1;i<=N;i++){
        T[i]=-1;
        for(;;){
            cin>>a; if(!a) break;
            v[i].push_back(a);
        }
    }
    cin>>M;
    for(i=0;i<M;i++){cin>>a;q.push(a);T[a]=0;}
    while(q.size()){
        p=q.front(); q.pop();
        for(auto &e:v[p]){
            if(T[e]==-1&&v[e].size()<=2*++n[e]){ q.push(e); T[e]=T[p]+1; }
        }
    }
    for(i=1;i<=N;i++) cout<<T[i]<<" ";
}
