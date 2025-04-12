#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * insert : dp[i][j] = dp[i][j - 1] + 1
 * erase : dp[i][j] = dp[i - 1][j] + 1
 * replace : dp[i][j] = dp[i - 1][j - 1] + 1
 * no operation (satisfy a[i] == b[j]): dp[i][j] = dp[i - 1][j - 1]
 */

vector<vector<int>> dp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    dp.resize(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    }
    cout << dp[n][m];

    return 0;
}