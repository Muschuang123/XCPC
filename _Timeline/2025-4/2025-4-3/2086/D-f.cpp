#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 5e5 + 5;
const int mod = 998244353;

i64 f[maxn], g[maxn];
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

void init() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
}

i64 C(i64 n, i64 m) {
    if (m > n || n < 0 || m < 0) {
        return 0;
    }
    if (m == 0) {
        return 1;
    }
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve() {
    vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), greater<>());
    int n = accumulate(c.begin(), c.end(), 0);
    vector<i64> pre(26);
    for (int i = 1; i < 26; i++) {
        pre[i] = pre[i - 1] + c[i - 1];
    }

    vector<i64> dp(n + 2);
    dp[0] = dp[1] = 1;
    for (int o = 0; o < 26 && c[o] > 0; o++) {
        vector<i64> tp = dp;
        for (int i = n + 1; i >= 0; i--) {
            int t = pre[o] - (i / 2 - c[o]);
            if (i >= 2 * c[o] && 2 * t <= n + 1 && 2 * t >= 0) {
                if (i % 2) {
                    dp[i] = (tp[i] + tp[i - 2 * c[o]] * C(i / 2, c[o]) % mod * tp[2 * t]) % mod;
                } else {
                    dp[i] = (tp[i] + tp[i - 2 * c[o]] * C(i / 2, c[o]) % mod * tp[2 * t + 1]) % mod;
                }
            }
            cout << "";
        }
    }
    cout << dp[n + 1] << '\n';
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