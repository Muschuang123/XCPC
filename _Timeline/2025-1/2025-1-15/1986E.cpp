#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i] % k].push_back(a[i]);
    }

    int cnt = 0;
    for (auto &v : mp)
    {
        if (v.second.size() % 2)
            cnt++;
    }
    if (cnt > n % 2)
    {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (auto &v : mp)
    {
        if (v.second.size() % 2 == 0 || v.second.size() == 1)
        {
            for (int i = 1; i < v.second.size(); i += 2)
            {
                ans += v.second[i] - v.second[i - 1];
            }
        }
        else
        {
            int res = 1e18;
            int sz = v.second.size();
            vector<vector<int>> dp(2, vector<int>(sz));
            for (int i = 1; i < sz; i++)
                dp[i % 2][i] = v.second[i] - v.second[i - 1];
            for (int i = 1; i < sz; i++)
                dp[1][i] += dp[1][i - 1];
            for (int i = sz - 2; i >= 0; i--)
                dp[0][i] += dp[0][i + 1];
            
            for (int i = 0; i < sz; i++)
            {
                if (i % 2)
                    res = min(res, dp[1][i] + dp[0][i]);
                else
                {
                    int x = 0;
                    if (i > 0)
                        x += dp[1][i - 1];
                    if (i < sz - 1)
                        x += dp[0][i + 1];
                    res = min(res, x);
                }
            }
            ans += res;
        }
    }
    cout << ans / k << '\n';
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