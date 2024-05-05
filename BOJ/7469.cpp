#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int src(vector<int> &v,int k){
    int l=v.size();
    int n_partition=(l%5==0)?l/5:l/5+1;
    for(int i=0;i<l;i+=5)
        sort(v.begin()+i,v.begin()+min(i+5,l));
    if(n_partition==1)
        return v[k];
    vector<int> meds;
    int last_med_idx = (l-5*(n_partition-1)-1)/2;
    int last_end_idx = l-5*(n_partition-1)-1;
    for(int i=0;i<n_partition;i++)
        meds.push_back(v[i*5+((i==n_partition-1)?last_med_idx:2)]);
    int med_meds = src(meds,(meds.size()-1)/2);
    vector<int> subL,subR;
    int cnt=0;
    for(auto &e:v){
        if(e==med_meds)
            cnt++;
        else if(e>med_meds)
            subR.push_back(e);
        else
            subL.push_back(e);
    }
    if(subL.size()>k)
        return src(subL,k);
    else if(subL.size()+cnt>k)
        return med_meds;
    else
        return src(subR,k-subL.size()-cnt);
}
int main(){
    vector<int> vi;
    int N,t;
    cin >> N >> t;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        vi.push_back(a);
    }
    for(int t_=0;t_<t;t_++){
        int a,b,c;
        cin >> a >> b >> c;
        vector<int> v(vi.begin()+a-1,vi.begin()+b);
        cout << src(v,c-1) << endl;
    }
}