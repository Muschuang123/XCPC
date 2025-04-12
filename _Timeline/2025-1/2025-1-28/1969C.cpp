#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++)
    {
        int mn = 1e18;
        int res = 0;
        // j 次操作，实际上是把 [i - j, i] 区间里的这 j + 1 个数取得最小值并减去。
        for (int j = 0; j <= k && i - j >= 1; j++)
        {
            res += a[i - j] - mn;
            if (mn > a[i - j])
            {
                res += (j + 1) * (mn - a[i - j]);
                mn = a[i - j];
            }
            for (int l = k; l >= j; l--)
            {
                dp[i][l] = max(dp[i][l], dp[i - j - 1][l - j] + res);
            }
        }
    }
    int ans = 0;
    cout << accumulate(a.begin() + 1, a.end(), 0LL) - dp[n][k] << '\n';
}   

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}