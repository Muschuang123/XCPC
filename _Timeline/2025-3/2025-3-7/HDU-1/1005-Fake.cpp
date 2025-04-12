#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> t(n + 1, vector<i64>(m + 1, 1e18)), d(n + 1, vector<i64>(m + 1, 1e18));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    
    // 0 右，1 下
    vector<vector<vector<i64>>> dp(n + 1, vector<vector<i64>>(m + 1, vector<i64>(2, 1e18))); 
    // dp[1][1][0] = t[1][1];
    // dp[1][1][1] = t[1][1] + d[1][1];
    dp[1][0][0] = 0;
    for (int i = 2; i <= n + m + 1; i++)
    {
        for (int j = max(1, i - m), k = i - j; j <= n && k >= 1; j++, k--)
        {
            // cout << i << ' ' << j << ' ' << k << '\n';
            dp[j][k][0] = min({
                dp[j - 1][k][0] + t[j][k] + d[j - 1][k] + d[j][k],
                dp[j - 1][k][1] + t[j][k] + d[j][k],
                dp[j][k - 1][0] + t[j][k],
                dp[j][k - 1][1] + t[j][k] + d[j][k - 1]
            });
            dp[j][k][1] = min({
                dp[j - 1][k][0] + t[j][k] + d[j - 1][k],
                dp[j - 1][k][1] + t[j][k],
                dp[j][k - 1][0] + t[j][k] + d[j][k],
                dp[j][k - 1][1] + t[j][k] + d[j][k - 1] + d[j][k]
            });
        }
    }

    cout << dp[n][m][1] << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}