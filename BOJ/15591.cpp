#include <iostream>
#include <vector>
using namespace std;
int N, Q;
vector<bool> V(50001);
vector<pair<int, int> > G[5001];
int dfs(int v, int k) {
    int res = 0;
    V[v] = true;
    for (auto &e: G[v]) {
        if (!V[e.first] && e.second >= k) {
            res++;
            res += dfs(e.first, k);
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        G[p].push_back(make_pair(q, r));
        G[q].push_back(make_pair(p, r));
    }
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        fill(V.begin(), V.end(), false);
        cout << dfs(v, k) << "\n";
    }
}
