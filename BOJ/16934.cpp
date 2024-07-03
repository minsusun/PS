#include <iostream>
using namespace std;
int N;
struct T{
    bool E;
    int C;
    T* N[26];
    T():C(0){ for(int i=0;i<26;i++) N[i]=NULL; }
    ~T(){ for(int i=0;i<26;i++) delete N[i]; }
    void I(char *S,bool P){
        if(!(*S)){
            if(++C>1) cout<<C<<"\n";
            else cout<<"\n";
            return;
        }
        if(P) cout<<*S;
        int K=*S-'a';
        if(!N[K]){ N[K]=new T(); N[K]->I(S+1,false); }
        else N[K]->I(S+1,true);
    }
}R;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    while(N--){
        char S[11]; cin>>S;
        R.I(S,true);
    }
}
