#include <iostream>
using namespace std;
int n;
int main(){
    int i;
    cin >> n;
    for(i=n/5;i>=0;i--){
        if((n-5*i)%3==0){
            cout << i+(n-5*i)/3;
            break;
        }
    }
    if(i==-1)
        cout << -1;
}
