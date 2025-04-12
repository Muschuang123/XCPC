#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[300005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        g[i].push_back(0);
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n ;i++)
    {
        cin >> a[i];
        g[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        g[i].push_back(n + 1);
    }

    vector<pair<int, int>> d;
    vector<bool> vis(n + 1);
    for (int k = 1; k <= n; k++)
    {
        if (vis[a[k]])
            continue;
        int md = 0;
        for (int i = 1; i < g[a[k]].size(); i++)
        {
            md = max(md, g[a[k]][i] - g[a[k]][i - 1]);
        }
        d.push_back({md, a[k]});
        vis[a[k]] = 1;
    }

    sort(d.begin(), d.end());

    int p = 0;
    int ans = 0x3f3f3f3f'3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        while (p < d.size() && d[p].first <= i)
        {
            ans = min(ans, d[p].second);
            p++;
        }
        cout << (ans == 0x3f3f3f3f'3f3f3f3f ? -1LL : ans) << " \n"[i == n];
    }   
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