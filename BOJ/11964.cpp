#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, A, B;
    queue<pair<int,bool> > q;
    cin >> T >> A >> B;
    vector<bool> v(5000005, false);
    q.push({0, false});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (v[p.first]) continue;
        v[p.first] = true;
        if (p.first + A <= T) q.push({p.first + A, p.second});
        if (p.first + B <= T) q.push({p.first + B, p.second});
        if (!p.second) q.push({p.first / 2, !p.second});
    }
    int res = -1;
    for (int i = 0; i <= T; i++) {
        if (v[i]) res = max(res, i);
    }
    cout << res;
}
