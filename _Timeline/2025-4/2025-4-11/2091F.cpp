#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<i64>> dp(n + 2, vector<i64>(m + 1));
    for (int j = 1; j <= m; j++) {
        dp[n + 1][j] = j;
    }
    // len + 1 > (i64)sqrtl(len * len + 1) > len
    for (int i = n; i >= 1; i--) {
        vector<i64> tp(m + 1);
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X') {
                if (i == n) {
                    tp[j] = 1;
                } else {
                    int l = max(1, j - d + 1);
                    int r = min(m, j + d - 1);
                    tp[j] = (dp[i + 1][r] - dp[i + 1][l - 1] + mod) % mod;
                }
            }
        }

        for (int j = 1; j <= m; j++) {
            tp[j] = (tp[j] + tp[j - 1]) % mod;
        }

        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X') {
                int l = max(1, j - d);
                int r = min(m, j + d);
                dp[i][j] = (tp[r] - tp[l - 1] + mod) % mod;
            }
        }

        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
        cout << "";
    }

    cout << dp[1][m] << '\n';
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