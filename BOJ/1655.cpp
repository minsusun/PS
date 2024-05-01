#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,a;
priority_queue<int,vector<int>,greater<int> > pqg;
priority_queue<int,vector<int>,less<int> > pql;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a;
        if(pql.size()==pqg.size()) pql.push(a);
        else pqg.push(a);
        if(!pql.empty()&&!pqg.empty()&&pql.top()>pqg.top()){
            int a=pql.top(),b=pqg.top();
            pql.pop(),pqg.pop();
            pql.push(b),pqg.push(a);
        }
        cout << pql.top() << "\n";
    }
}