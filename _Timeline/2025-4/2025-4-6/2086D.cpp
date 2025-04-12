#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;
const int maxn = 5e5 + 5;

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
    vector<int> a(26);
    for (auto &c : a) {
        cin >> c;
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    // n 奇数位置 | m 偶数位置
    int n = (sum + 1) / 2, m = sum / 2;
    i64 tot = 0;
    // 把整个字符串的奇数都放到前面，偶数都放到后面
    // dp 模拟前面的情况，不放到前面自然就是放到后面
    vector<i64> dp(n + 1);
    dp[0] = 1;
    for (int o = 0; o < 26; o++) {
        if (a[o] == 0) {
            continue;
        }
        vector<i64> tp = dp;
        dp.assign(n + 1, 0);
        // i := 这个字母放完之后，前面放了多少个
        for (int i = 0; i <= n; i++) {
            // 前面能放出这么多个且后面有地方放
            if (tot >= i && tot - i + a[o] <= m) {
                dp[i] = (dp[i] + tp[i] * C(m - (tot - i), a[o])) % mod;
            }
            // 如果前面有地方放
            if (i + a[o] <= n) {
                dp[i + a[o]] = (dp[i + a[o]] + tp[i] * C(n - i, a[o])) % mod;
            }
        }
        tot += a[o];
    }
    cout << dp[n] << '\n';
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