#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(n / 3 + 1, 0x3f3f3f3f));
    dp[0][0] = 0;
    for (int i = 3; i <= n; i++)
    {
        if (i > 3)
        {
            for (int j = 0; j <= i / 3; j++)
            {
                dp[i - 3][j] = min(dp[i - 3][j], dp[i - 4][j]);
            }
        }
        int co = (s[i - 2] != 'o') + (s[i - 1] != 'v') + (s[i] != 'o');
        for (int j = 1; j <= i / 3; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + co);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 3; j++)
        {
            if (dp[i][j] <= k)
            {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}