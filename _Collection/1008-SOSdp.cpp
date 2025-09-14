// https://acm.hdu.edu.cn/contest/problem?cid=1177&pid=1008
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // 求和
    vector<vector<i64>> sum(n + 1, vector<i64>(1 << m));
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s < 1 << m; s++) {
            sum[i][s] = sum[i][s ^ (s & -s)] + a[i][__lg(s & -s)];
        }
    }

    // 拿一次，作为 位 1 列的 max
    vector<i64> mx(1 << m);
    for (int s = 0; s < 1 << m; s++) {
        for (int i = 1; i <= n; i++) {
            mx[s] = max(mx[s], sum[i][s]);
        }
    }

    vector<i64> dp = mx;
    k = min(k, m);
    for (int o = 2; o <= k; o++) {
        for (int s = (1 << m) - 1; s >= 0; s--) {
            for (int t = s; t > 0; t = t - 1 & s) {
                dp[s] = max(dp[s], dp[t] + mx[s ^ t]);
            }
        }
    }
    cout << dp.back() << '\n';
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