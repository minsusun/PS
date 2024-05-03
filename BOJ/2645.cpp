#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool map[51][51];
short n,m,k;
pair<short,short> S_,T_;
int main(){
    cin >> n >> S_.first >> S_.second >> T_.first >> T_.second >> k >> m;
    for(int i=0;i<m;i++){
        short a,x,y,x_,y_;
        cin >> a;
        for(int j=0;j<a;j++){
            x_=x,y_=y;
            cin >> x >> y;
            if(!j) continue;
            if(x==x_) for(short p=min(y,y_);p<=max(y,y_);p++) map[x][p]=true;
            else for(short p=min(x,x_);p<=max(x,x_);p++) map[p][y]=true;
        }
    }
}