#include <iostream>
using namespace std;
long long int g,l;
long long int gcd(long long int a,long long int b){
    if(a<b)
        return gcd(b,a);
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    cin >> g >> l;
    long long int ms=g+l,ma=g,mb=l;
    for(long long int i=g;i<=l;i+=g){
        if(g*l%i==0&&gcd(i,g*l/i)==g&&g*l/i+i<ms)
            ma=i,mb=g*l/i,ms=ma+mb;
    }
    cout << ma << " " << mb;
}
