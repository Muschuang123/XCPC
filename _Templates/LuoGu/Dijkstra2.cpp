#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int v, w;
};

vector<node> g[100005];
vector<bool> vis;
vector<int> d;

void dijkstra(int s)
{
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
        for (auto &c : g[x])
        {
            int v = c.v, w = c.w;
            if (d[v] > d[x] + w)
            {
                d[v] = d[x] + w;
                q.push({-d[v], v});
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    vis.resize(n + 1);
    d.resize(n + 1, 0x3f3f3f3f);

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " \n"[i == n];

    return 0;
}