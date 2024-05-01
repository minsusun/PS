#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int T,w;
vector<pair<int,pair<int,int> > > v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long int ans=-1;
    stack<pair<int,pair<int,int> > > st;
    cin >> w;
    for(int i=0;i<w;i++){
        int a;
        cin >> a;
        v.push_back(make_pair(a,make_pair(i,i+1)));
    }
    for(int i=0;i<w;i++){
        if(st.size()!=0&&v[i].first<st.top().first){
            while(st.size()!=0&&st.top().first>v[i].first){
                int h=st.top().first,x_i=st.top().second.first;
                st.pop();
                if(st.size()==0)
                    x_i=0;
                else
                    x_i=st.top().second.second;
                if(ans==-1)
                    ans=(long long int)(h)*(v[i].second.first-x_i);
                else
                    ans=max(ans,(long long int)(h)*(v[i].second.first-x_i));
            }
        }
        st.push(v[i]);
    }
    while(st.size()!=0){
        int h=st.top().first,x_i=st.top().second.first;
        st.pop();
        if(st.size()==0)
            x_i=0;
        else
            x_i=st.top().second.second;
        if(ans==-1)
            ans=(long long int)(h)*(w-x_i);
        else
            ans=max(ans,(long long int)(h)*(w-x_i));
    }
    cout << ans << endl;
}