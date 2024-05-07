#include <iostream>
#include <algorithm>
using namespace std;
int n,sum;
int a[51],b[51];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++)
        sum+=a[i]*b[n-i-1];
    cout << sum;
}
