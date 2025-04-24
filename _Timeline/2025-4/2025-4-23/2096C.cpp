#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const i64 inf = (i64)1e18 + 9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    vector<vector<i64>> dp(n + 1, vector<i64>(2, inf));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        int f0 = 0, f1 = 0, f2 = 0;
        for (int j = 1; j <= n; j++) {
            f0 |= a[i][j] == a[i - 1][j];
            f1 |= a[i][j] + 1 == a[i - 1][j];
            f2 |= a[i][j] - 1 == a[i - 1][j];
        }
        if (!f0) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + b[i]);
        }
        if (!f1) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + b[i]);
        }
        if (!f2) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
    }
    i64 res = min(dp[n][0], dp[n][1]);
    if (res == inf) {
        cout << -1 << '\n';
        return;
    }

    dp.assign(n + 1, vector<i64>(2, inf));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        int f0 = 0, f1 = 0, f2 = 0;
        for (int j = 1; j <= n; j++) {
            f0 |= a[j][i] == a[j][i - 1];
            f1 |= a[j][i] + 1 == a[j][i - 1];
            f2 |= a[j][i] - 1 == a[j][i - 1];
        }
        if (!f0) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        }
        if (!f1) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        }
        if (!f2) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
    }

    if (min(dp[n][0], dp[n][1]) == inf) {
        cout << -1 << '\n';
        return;
    }
    cout << res + min(dp[n][0], dp[n][1]) << '\n';
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