#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int a[30004];
// dp[i][j], j: 相较于原步长变化大小，偏移数组，400 是原点
int dp[30004][802];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[d][400] = a[0] + a[d];
    int ans = dp[d][400];
    for (int i = d + 1; i <= 3e4; i++)
    {
        // 可能的步长区间 包含于 [d - 400, d + 400]
        for (int j = -400; j <= 400; j++)
        {
            // 步长 (d + j) 合法
            if (d + j >= 1 && d + j <= i)
            {
                dp[i][400 + j] = max({
                    dp[i][400 + j], 
                    dp[i - (d + j)][400 + j],
                    dp[i - (d + j)][400 + j - 1],
                    dp[i - (d + j)][400 + j + 1]
                    }) + a[i];
                ans = max(ans, dp[i][400 + j]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}