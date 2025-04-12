#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(33, -1e18); 
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        // 除了从dp[31]来的状态，还有之前dp[32]造成的后面全是0的状态，
        // 这个状态有可能比现在的dp[31]的值要大，所以要保留
        dp[32] = max(dp[32], max(dp[31] + (a[i] >> 32), dp[32] + (a[i] >> 32) - k));
        for (int j = min(31LL, i); j >= 1; j--)
        {
            dp[j] = max(dp[j - 1] + (a[i] >> j), dp[j] + (a[i] >> j) - k);
        }
        dp[0] = dp[0] + a[i] - k;
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    
    


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