#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,cnt;
vector<pair<int,int>> v;
int main(){
    int pivot=-1;
    cin >> n;
    for(int i=0;i<n;i++){
        int start,end;
        cin >> start >> end;
        v.push_back(make_pair(end,start));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i].first>=pivot&&v[i].second>=pivot){
            pivot=v[i].first;
            cnt++;
        }
        
    }
    cout << cnt;
}
