#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 写了一个很神秘的 dp，预处理 a[i][j] 代表 s 在 [i, j] 上代表的数。 > n 直接停。
 * 枚举位置 i，枚举每个数 j，枚举步长 l，计算 j + [i, l] 需要的加号数量，
 * 更新一下 i + l 处这个数的数量。
 * 一直 dp 到 len + 1，这样的话保证 [1, len] 全用上了。
 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    int n;
    cin >> s >> n;
    int len = s.size();
    s = " " + s;

    vector<vector<int>> a(len + 1, vector<int>(len + 1));
    static vector<vector<int>> dp(len + 2, vector<int>(n + 1, 1e9));

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; i + j <= len + 1; j++)
        {
            a[i][j] = a[i][j - 1] * 10 + s[i + j - 1] - '0';
            if (a[i][j] > n)
                break;
        }
    }

    dp[1][0] = 0;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] != 1e9)
            for (int l = 1; i + l <= len + 1; l++)
            {
                if (a[i][l] > n)
                    break;
                int t = j + a[i][l];
                if (t <= n)
                    dp[i + l][t] = min(dp[i + l][t], dp[i][j] + 1);
            }
        }
    }
    
    if (dp[len + 1][n] == 1e9)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dp[len + 1][n] - 1 << '\n';
    }
    

    return 0;
}