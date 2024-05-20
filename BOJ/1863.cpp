#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int n,cnt;
pair<int,int> v[50001];
stack<pair<int,int>> st;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> v[i].first >> v[i].second;
    sort(v,v+n);
    for(int i=0;i<n;i++){
        if(!v[i].second){
            cnt+=st.size();
            while(st.size()) st.pop();
        }
        else if(!st.size()||st.top().second<v[i].second)
            st.push(v[i]);
        else if(st.top().second==v[i].second)
            continue;
        else{
            while(st.size()&&st.top().second>v[i].second)
                cnt++,st.pop();
            if(st.size()==0||st.top().second<v[i].second)
                st.push(v[i]);
        }
    }
    cout << cnt+st.size();
}
