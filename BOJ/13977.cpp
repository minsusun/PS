#include <bits/stdc++.h>
using namespace std;
long long f[4000001];
const long long MOD = 1000000007;
long long p(long long a, int b)
{
    if (b == 1) return a % MOD;
    long long t = p(a, b/2);
    t = (t * t) % MOD;
    if (b % 2) return t * a % MOD;
    else return t % MOD;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, n, r;
    f[0] = 1;
    for (int i = 1; i < 4000001; i++) f[i] = (f[i - 1] * i) % MOD;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> r;
        cout << (f[n] * p((f[n-r] * f[r]) % MOD, MOD - 2)) % MOD << '\n';
    }
}
