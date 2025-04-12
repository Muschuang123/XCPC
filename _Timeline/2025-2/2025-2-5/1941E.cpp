#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][j]++;
        }
    }

    vector<i64> cost(n + 1);
    for (int i = 1; i <= n; i++)
    {
        multiset<i64> ss;
        vector<i64> dp(m + 1);
        dp[1] = 1;
        ss.insert(1);
        for (int j = 2; j <= m; j++)
        {
            if (j - d - 2 >= 1)
                ss.extract(dp[j - d - 2]);
            dp[j] = *ss.begin() + a[i][j];
            ss.insert(dp[j]);
        }
        cost[i] = dp[m];
    }
    
    i64 res = 0;
    for (int i = 1; i <= k; i++)
    {
        res += cost[i];
    }
    i64 ans = res;
    for (int i = k + 1; i <= n; i++)
    {
        res -= cost[i - k];
        res += cost[i];
        ans = min(ans, res);
    }
    cout << ans << '\n';

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