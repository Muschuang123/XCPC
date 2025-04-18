#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;

i64 fac[maxn];

void init() {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

i64 ksm(i64 a, i64 n) {
    i64 ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    i64 res = 0;
    for (int i = 0; i <= m; i++) {
        i64 F = (m - i) % 2 ? -1 : 1;
        i64 d = ksm(i, n) * ksm(fac[i] * fac[m - i] % mod, mod - 2) % mod;
        d *= F;
        res = (res + d + mod) % mod;
    }
    cout << (res * (res - 1)) % mod << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}