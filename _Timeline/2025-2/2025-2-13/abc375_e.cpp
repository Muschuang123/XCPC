#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 这么小的数据范围，不是暴力就是多状态 dp。
// 开一个数组，每一维都代表着一个状态。
// 特别的，这个题可以压缩一个状态，知道了其中两个组的能力，就可以算出第三个组的。
// 所以可以用 一个 三维数组写出dp。

// *：考虑 dp 的时候 先不用想着优化。
// 其实可以 把第一维设为 2，然后用奇偶滚动。
// 但是没必要，还耗费思维量。

int dp[102][502][502];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    int sum = accumulate(b.begin() + 1, b.end(), 0);
    if (sum % 3 != 0)
    {
        cout << -1;
        return 0;
    }
    
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= 500; k++)
        {
            for (int j = 500; j >= b[i]; j--)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - b[i]][k] + (a[i] != 1));
            }
        }
        for (int j = 0; j <= 500; j++)
        {
            for (int k = 500; k >= b[i]; k--)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - b[i]] + (a[i] != 2));
            }
        }
        for (int j = 0; j <= 500; j++)
        {
            for (int k = 0; k <= 500; k++)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + (a[i] != 3));
            }
        }
    }

    cout << (dp[n][sum / 3][sum / 3] == 0x3f3f3f3f ? -1 : dp[n][sum / 3][sum / 3]);

    return 0;
}