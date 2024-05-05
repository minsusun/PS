#include <iostream>
#include <queue>
using namespace std;
short dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={1,-1,2,-2,2,-2,1,-1},T,N;
int main(){
    cin >> T;
    for(int T_=0;T_<T;T_++){
        bool v[301][301]={0};
        queue<pair<pair<short,short>,int> > q;
        pair<short,short> S,E;
        cin >> N >> S.first >> S.second >> E.first >> E.second;
        q.push(make_pair(S,0));
        v[S.first][S.second]=true;
        while(q.size()){
            if(q.front().first==E){
                cout << q.front().second << "\n";
                break;
            }
            short x=q.front().first.first,y=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                short nx=x+dx[i],ny=y+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<N&&!v[nx][ny]){
                    v[nx][ny]=true;
                    q.push(make_pair(make_pair(nx,ny),t+1));
                }
            }
        }
    }
}