#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n, c1, c2;
    cin >> n >> c1 >> c2;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<i64> dp(n + 1, 1e18);
    vector<i64> vp(n + 1, 1e18);
    dp[0] = 0;
    vp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && b[i] >= b[j])
            {
                dp[i] = min(dp[i], dp[j] + (i - j - 1) * c1);
            }
            if (a[i] >= a[j] && b[i] >= b[j])
            {
                vp[i] = min(vp[i], vp[j] + (i - j - 1) * c1 + c2);
            }
        }
        swap(a[i], b[i]);
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && b[i] >= b[j])
            {
                dp[i] = min(dp[i], vp[j] + (i - j - 1) * c1);
            }
            if (a[i] >= a[j] && b[i] >= b[j])
            {
                vp[i] = min(vp[i], dp[j] + (i - j - 1) * c1 + c2);
            }
        }
        swap(a[i], b[i]);
    }

    i64 ans = 1e18;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, dp[i] + (n - i) * c1);
        ans = min(ans, vp[i] + (n - i) * c1);
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