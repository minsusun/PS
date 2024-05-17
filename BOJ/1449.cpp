#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,l,cnt;
vector<int> v;
int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    l--;
    for(int i=0;i<v.size();){
        int tmp=v[i];
        cnt++;
        for(;v[i]<=tmp+l;i++);
    }
    cout << cnt;
}
