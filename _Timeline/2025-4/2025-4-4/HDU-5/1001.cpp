#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n, m, V;
    cin >> n >> m >> V;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<i64>> dp(m + 1, vector<i64>(V + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = a[i]; k <= V; k++) {
                dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
            }
        }
    }
    i64 ans = 0;
    for (int i = 0; i <= V; i++) {
        ans = (ans + dp[m][i]) % mod;
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