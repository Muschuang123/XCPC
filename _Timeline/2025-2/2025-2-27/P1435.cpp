// https://www.luogu.com.cn/problem/P1435
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 最长公共子序列

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    string v = s;
    reverse(v.begin() + 1, v.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i] == v[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << n - dp[n][n];

    return 0;
}