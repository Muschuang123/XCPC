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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    dsu d(n + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (d.fin(u) == d.fin(v))
        {
            ans++;
        }
        d.merg(u, v);
    }
    cout << ans << '\n';

    return 0;
}