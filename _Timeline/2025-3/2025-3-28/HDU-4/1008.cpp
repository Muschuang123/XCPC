#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    vector<i64> dp(m + 1);
    vector<int> cur(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            dp[j] = dp[cur[j]] + a[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            if (dp[cur[j - 1]] < dp[j])
                cur[j] = j;
            else 
                cur[j] = cur[j - 1];
        }
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << '\n';
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