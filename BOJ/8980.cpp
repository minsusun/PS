#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, C, M, value;
struct x{
    int s,e,c;
    bool operator<(x p) { return e == p.e ? s > p.s : e < p.e; }
};
vector<x> S;
int R[2001];
int main() {
    scanf("%d%d%d",&N,&C,&M);
    while(M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        S.push_back({a, b, c});
    }
    sort(S.begin(), S.end());
    for(auto[f, s, c]:S) {
        int cost = c;
        for(int i = f; i < s; i++) cost = min(C - R[i], cost);
        for(int i = f; i < s; i++) R[i] += cost;
        value += cost;
    }
    printf("%d", value);
}
