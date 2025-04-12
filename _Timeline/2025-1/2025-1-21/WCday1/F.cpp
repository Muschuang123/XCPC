#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    int l = 1, r = 1;
    map<int, int> mp;
    map<int, int> pre;
    pre[0] = 1;
    map<int, int> t;
    int cur = 0;
    int now = 0;
    while (r <= n)
    {
        size_t mpsz = mp.size();
        mp[a[r]]++;
        if (mp.size() - mpsz)
        {
            cur++;
            // t[a[r]] = cur % 2 == 1 ? 1 : -1;
            if (t.size() == 0)
                t[a[r]] = 1;
            else if (t.size() == 1)
                t[a[r]] = -1;
        }
        if (mp.size() >= 3)
        {
            while (mp.size() >= 3)
            {
                mp[a[l]]--;
                if (mp[a[l]] == 0)
                {
                    mp.erase(a[l]);
                    t.erase(a[l]);
                }
                l++;
            }
            t[a[l]] = 1;
            t[a[r]] = -1;
            now = 0;
            pre.clear();
            pre[0] = 1;
            for (int i = l; i < r; i++)
            {
                now += t[a[i]];
                pre[now] = 1;
            }
        }
        now += t[a[r]];
        ans += pre[now];
        pre[now]++;
        r++;
    }
    cout << ans << '\n';
    
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