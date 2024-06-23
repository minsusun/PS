#include <iostream>
#include <cstring>
#include <deque>

#define endl "\n"

using namespace std;

deque <int> f;
deque <int> b;

int main()
{
    char a[100001];
    cin >> a;
    
    int n;
    cin >> n;
    
    int t = strlen(a);
    for (int i=0; i<t; i++) {
        f.push_back(a[i]);
    }
    
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c == 'P') {
            char d;
            cin >> d;
            f.push_back(d);
        }
        else if (c == 'L') {
            if (!f.empty()) {
                b.push_front(f.back());
                f.pop_back();
            }
        }
        else if (c == 'D') {
            if (!b.empty()) {
                f.push_back(b.front());
                b.pop_front();
            }
        }
        else if (c == 'B') {
            if (!f.empty()) {
                f.pop_back();
            }
        }
    }
    while(!b.empty()) {
        f.push_back(b.front());
        b.pop_front();
    }
    
    while(!f.empty()) {
        printf("%c",f.front());
        f.pop_front();
    }
}
