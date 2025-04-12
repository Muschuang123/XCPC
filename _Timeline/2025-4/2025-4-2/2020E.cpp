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

int inv1e4 = ksm(1e4, mod - 2);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> dp(1024);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> tp = dp;
        int qu = 1LL * p[i] * inv1e4 % mod;
        int bqu = 1LL * (10000 - p[i]) * inv1e4 % mod;
        for (int j = 0; j <= 1023; j++) {
            dp[j] = 1LL * tp[j ^ a[i]] * qu % mod + 1LL * tp[j] * bqu % mod;
            dp[j] %= mod;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1023; i++) {
        ans = (1LL * ans + 1LL * dp[i] * i * i % mod) % mod;
    }
    cout << ans << '\n';
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