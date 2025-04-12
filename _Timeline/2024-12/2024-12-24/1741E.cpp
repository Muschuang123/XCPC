#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    vector<bool> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] && i + b[i] <= n)
        {
            dp[i + b[i]] = 1;
        }
        if (i - b[i] - 1 >= 0 && dp[i - b[i] - 1])
        {
            dp[i] = 1;
        }
    }
    if (dp[n])
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
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