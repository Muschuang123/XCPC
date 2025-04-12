#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 删边使用 set<int> g[maxn] 做的图删指定边。
 * 
 * 先把 度 >= 2 的，能删就删，因为删了一定能让边变少（-1 或者 -3）。
 *      这种情况最多 m - 1 次操作，删完所有最后还剩一条。
 *      *: 删干净的话肯定最后一次删了 3 条。
 * 
 * 判断一下是不是空图，空图不用管。
 * 不是空图的话说明有残边，用其中一条残变把剩下的边连起来，成一棵树。
 *      这种情况最多 n - 1 次操作
 * 
 * 操作数 <= 2 * max(m, n)，满足题意。
 */

int n, m;
set<int> g[200005];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++)
    {
        while (g[i].size() >= 2)
        {
            int u = *g[i].begin(), v = *--g[i].end();
            g[u].erase(i);
            g[v].erase(i);
            g[i].erase(u);
            g[i].erase(v);
            if (g[u].count(v))
            {
                g[u].erase(v);
                g[v].erase(u);
            }
            else
            {
                g[u].insert(v);
                g[v].insert(u);
            }
            ans.push_back({i, u, v});
        }
    }

    int kx = 0, kv = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() > 0)
        {
            kx = i, kv = *g[i].begin();
            break;
        }
    }

    if (kx != 0 || kv != 0)
    {
        vector<int> vis(n + 1);
        vis[kx] = vis[kv] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (g[i].size() == 0)
            {
                vis[i] = 1;
                ans.push_back({kx, kv, i});
                kv = i;
            }
            if (g[i].size() == 1 && !vis[i])
            {
                vis[i] = vis[*g[i].begin()] = 1;
                ans.push_back({kx, kv, i});
                kv = i;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [a, b, c] : ans)
        cout << a << ' ' << b << ' ' << c << '\n';
    
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