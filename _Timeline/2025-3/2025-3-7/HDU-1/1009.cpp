#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), g(1 << m);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < (1 << m); i++) cin >> g[i];
    int u = (1 << m) - 1;

    i64 res = 0;
    vector<array<i64, 3>> dp;
    // val, |, &
    dp.push_back({0, 0, u});
    for (int i = 1; i <= n; i++)
    {
        // 为什么必须要用 res 而不是直接用 ans ?
        // 因为 存在 i 使得 g[i] < 0 
        res = -1e18;
        // dp[i] = dp[j] + g[f(i, j)]
        for (auto &[val, sor, sand] : dp)
        {
            sor |= a[i];
            sand &= a[i];
            res = max(res, val + g[sor - sand]);
        }

        decltype(dp) tp;
        for (auto &[val, sor, sand] : dp)
        {
            if (tp.empty() || tp.back()[1] != sor || tp.back()[2] != sand)
            {
                tp.push_back({val, sor, sand});
            }
            else
            {
                tp.back()[0] = max(tp.back()[0], val);
            }
        }
        tp.push_back({res, 0, u});
        dp = tp;
    }
    cout << res << '\n';
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