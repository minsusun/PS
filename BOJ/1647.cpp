#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,C,T,S[100005],x,y,z;
struct P{ int a,b,c; };
vector<P> E;
bool cmp(P &a,P &b){ return a.c<b.c; }
int F(int n){ return (S[n]==n)?n:(S[n]=F(S[n])); }
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=1;i<=N;i++) S[i]=i;
    for(int i=0;i<M;i++){
        cin >> x >> y >> z;
        E.push_back({x,y,z});
    }
    sort(E.begin(),E.end(),cmp);
    for(auto &e:E){
        if(C==N-2) break;
        if(F(e.a)==F(e.b)) continue;
        int p=F(e.a),q=F(e.b);
        S[min(p,q)]=S[max(p,q)],T+=e.c,C++;
    }
    cout << T;
}