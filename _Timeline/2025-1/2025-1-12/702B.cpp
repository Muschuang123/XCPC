#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 找到所有情况。
 * 
 * map<>.count 返回类型竟然只有 0 和 1 。。。
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for (auto &x : mp)
    {
        for (int i = 40; i >= 0; i--)
        {
            int t = (1LL << i) - x.first;

            if (t > x.first && mp.count(t))
            {
                ans += x.second * mp[t];
            }

            if (t == x.first)
            {
                ans += x.second * (x.second - 1) / 2;
            }
        }
    }
    
    cout << ans;

    return 0;
}