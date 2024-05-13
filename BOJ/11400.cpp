#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,dfs_n,M_anc[100005];
vector<int> v[100005];
vector<pair<int,int> > ans;
int search(int node,int prev){
    int anc=++dfs_n;
    M_anc[node]=dfs_n;
    for(auto &e:v[node]){
        if(e==prev)
            continue;
        if(M_anc[e])
            anc=min(anc,M_anc[e]);
        else{
            int chld=search(e,node);
            if(chld>M_anc[node])
                ans.push_back(make_pair(min(node,e),max(node,e)));
            anc=min(anc,chld);
        }
    }
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
    for(int i=1;i<=N;i++) if(!M_anc[i]) search(i,0);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto &e:ans) printf("%d %d\n",e.first,e.second);
}