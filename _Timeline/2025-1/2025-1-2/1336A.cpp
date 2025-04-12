#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[200005];
vector<int> ch;
vector<int> d;

void dfs(int x, int fa, int len)
{
    d[x] = len;

    if (g[x].size() == 1 && x != 1)
    {
        ch[x] = 0;
        return;
    }

    for (auto &v : g[x])
    {
        if (v != fa)
        {
            dfs(v, x, len + 1);
            ch[x] += ch[v] + 1;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    ch.resize(n + 1);
    d.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(d[i] - ch[i]);
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += q.top();
        q.pop();
    }

    cout << ans << '\n';

    return 0;
}