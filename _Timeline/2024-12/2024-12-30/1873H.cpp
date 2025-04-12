#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    for b, just earlier arrive at the cycle than a, then win.
    for a, just prevent b arrive the cycle.
*/

int n, a, b;
vector<int> g[200005];
vector<int> d;
vector<int> d2;

void dijkstra(int s)
{
    d.clear();
    d.resize(n + 1, 0x3f3f3f3f);
    vector<bool> vis(n + 1);
    d[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (q.size())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto &v : g[x])
        {
            if (d[v] > d[x] + 1)
            {
                d[v] = d[x] + 1;
                q.push({-d[v], v});
            }
        }
    }
}

void dijkstra2(int s)
{
    d2.clear();
    d2.resize(n + 1, 0x3f3f3f3f);
    vector<bool> vis(n + 1);
    d2[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (q.size())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto &v : g[x])
        {
            if (d2[v] > d2[x] + 1)
            {
                d2[v] = d2[x] + 1;
                q.push({-d2[v], v});
            }
        }
    }
}

void solve()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    
    vector<int> du(n + 1);
    vector<bool> vis(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++, du[v]++;
    }

    if (a == b)
    {
        cout << "NO\n";
        return;
    }

    dijkstra(b);
    dijkstra2(a);
    
    queue<int> q;
    for (int i = 1; i <= n ;i++)
    {
        if (--du[i] == 0)
            q.push(i);
    }

    while (q.size())
    {
        int x = q.front();
        q.pop();

        vis[x] = 1;
        for (auto &v : g[x])
        {
            if (--du[v] == 0 && !vis[v])
                q.push(v);
        }
    }

    if (!vis[b])
    {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && d[i] < d2[i])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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