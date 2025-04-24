#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    i64 sum = 0;
    vector<vector<i64>> v(n + 1, vector<i64>(m + 1)), w(n + 1, vector<i64>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j] >> w[i][j];
            sum += w[i][j];
        }
        for (int j = 2; j <= m; j++) {
            v[i][j] += v[i][j - 1];
            w[i][j] += w[i][j - 1];
        }
    }

    vector<i64> dp(x + 1);
    for (int i = 1; i <= n; i++) {
        vector<i64> tp = dp;
        for (int k = 1; k <= m; k++) {
            for (int j = x; j >= v[i][k]; j--) {
                dp[j] = max(dp[j], tp[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << sum - dp[x] << '\n';
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