#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // dp[现在的人说的是真还是假][现在的人] = 可能的情况
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // 如果 i 说真话，那么 a[i] == a[i - 1] （i - 1也说真话）
        // 或者 a[i] == a[i - 2] + 1 （i - 1说假话）
        if (a[i] == a[i - 1])
            dp[1][i] = (dp[1][i] + dp[1][i - 1]) % mod;
        if (i == 1 || a[i] == a[i - 2] + 1)
            dp[1][i] = (dp[1][i] + dp[0][i - 1]) % mod;
        
        // i 说假话，a[i] != a[i - 1]（错误的，因为假话不一定假，只是不可靠。）
        // if (a[i] != a[i - 1])
            dp[0][i] = (dp[0][i] + dp[1][i - 1]) % mod;
    }
    cout << (dp[0][n] + dp[1][n]) % mod << '\n';
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