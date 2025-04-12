#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int ind = lower_bound(sum.begin(), sum.end(), sum[i] - b[k]) - sum.begin();
            dp[i] = min(dp[i], dp[ind] + m - k);
        }
    }

    cout << (dp[n] == 1e18 ? -1 : dp[n]) << '\n';
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