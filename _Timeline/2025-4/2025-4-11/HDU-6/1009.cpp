#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

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

const int inv5 = ksm(5, mod - 2);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> inv(n + 1), mi(n + 1);
    inv[0] = mi[0] = 1;
    for (int i = 1; i <= n; i++) {
        inv[i] = inv[i - 1] * inv5 % mod;
        mi[i] = mi[i - 1] * 5 % mod;
    }

    // 1: 第 i 个是元音   0: 第 i 个是辅音
    vector<vector<i64>> dp(n + 1, vector<i64>(2));
    vector<i64> pre(n + 1);
    dp[0][0] = 1;
    pre[0] = mi[n];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * 21 % mod;
        if (i - k - 1 >= 0) {
            dp[i][1] = (pre[i - 1] - pre[i - k - 1] + mod) % mod * inv[n - i] % mod;
        } else {
            dp[i][1] = (pre[i - 1] + mod) % mod * inv[n - i] % mod;
        }
        pre[i] = (pre[i - 1] + dp[i][0] * mi[n - i]) % mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}