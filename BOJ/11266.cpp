#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int T,N,M,dfs_n,M_anc[100005],cnt;
vector<int> v[100005];
bool chk[100005];
int search(int node,bool p){
    int anc=++dfs_n;
    M_anc[node]=dfs_n;
    int c_cnt=0;
    for(auto &e:v[node]){
        if(M_anc[e])
            anc=min(anc,M_anc[e]);
        else{
            int chld=search(e,false);
            c_cnt++;
            if(!p&&chld>=M_anc[node])
                chk[node]=true;
            anc=min(anc,chld);
        }
    }
    if(p) chk[node]=(c_cnt>=2);
    return anc;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1;i<=N;i++) if(!M_anc[i]) search(i,true);
    for(int i=1;i<=N;i++) if(chk[i]) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=N;i++) if(chk[i]) printf("%d ",i);
}
