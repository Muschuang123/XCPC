#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct dsu
{
    int n, cnt;
    vector<int> fa, sz;

    // Index 0 is invalid
    dsu(int _n = 0)
    {
        n = _n - 1;
        cnt = n;
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        sz.resize(n + 1, 1);
    }

    int fin(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = fin(fa[x]);
    }

    bool merg(int u, int v)
    {
        u = fin(u), v = fin(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        fa[v] = u;
        sz[u] += sz[v];
        cnt--;
        return 1;
    }
};

int n;
vector<int> g[200005];
vector<int> vis(n + 1);

void dfs(int x)
{
    vis[x] = 1;
    for (int &v : g[x])
    {
        if (!vis[v])
            dfs(v);
    }
}

void solve()
{
    cin >> n;
    vis.assign(n + 1, 0);
    vector<int> in(n + 1);
    for (int i = 1; i <= n; i++) g[i].clear();
    set<pair<int, int>> ss;
    for (int i = 1; i <= n; i++)
    {
        int u, v = i;
        cin >> u;
        if (u > v)
            swap(u, v);
        ss.insert({u, v});
    }
    for (auto &[u, v] : ss)
    {
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++, in[v]++;
    }
    dsu d(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] <= 1)
            q.push(i);
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (int &v : g[x])
        {
            if (--in[v] <= 1 && !vis[v])
            {
                q.push(v);
                d.merg(x, v);
            }
        }
    }

    int res = d.cnt - count(vis.begin() + 1, vis.end(), 0); 
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt + min(1, res) << ' ' << cnt + res << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}