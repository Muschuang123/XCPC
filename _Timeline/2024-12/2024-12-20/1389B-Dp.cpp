#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> mx2(n + 1);
    for (int i = 2; i <= n; i++)
    {
        mx2[i] = max(mx2[i - 1], a[i - 1] + a[i]);
    }

    vector<vector<int>> dp(k + 2, vector<int>(z + 1));
    // pos == k - z * 2 == i - j * 2
    for (int i = 1; i <= k + 1; i++)
    {
        for (int j = 0; j <= z && j * 2 <= i; j++)
        {
            dp[i][j] = dp[i - 1][j] + a[i - j * 2];
            // can stay
            if (i > 1 && j > 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + mx2[i - (j - 1) * 2]);
            }
        }
    }
    cout << *max_element(dp[k + 1].begin(), dp[k + 1].end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}