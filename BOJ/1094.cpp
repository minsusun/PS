#include <iostream>
#include <queue>
using namespace std;
int main() {
    int x;
    int c = 64;
    priority_queue<int, vector<int>, greater<int> > pq;
    cin >> x;
    int step = 0;
    pq.push(c);
    while(c>x) {
        int p = pq.top();
        pq.pop();
        pq.push(p/2);
        if(c-p/2<x) {
            pq.push(p/2);
        }
        else {
            c -= p/2;
        }
        step++;
    }
    cout << pq.size() << "\n";
}