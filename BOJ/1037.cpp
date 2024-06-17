#include <iostream>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,A,C,M,m;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A;
        if(i==0) M=A,m=A;
        else M=max(M,A),m=min(m,A);
    }
    cout << M*m;
}
