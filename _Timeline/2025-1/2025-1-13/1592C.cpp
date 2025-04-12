#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> a;
vector<int> g[200005];
int ok = 0;
int sum = 0;

int dfs(int x, int fa)
{
    int ret = a[x];
    for (auto &v : g[x])
    {
        if (v != fa)
        {
            int res = dfs(v, x);
            if (res == sum)
                ok++;
            else 
                ret ^= res;
        }
    }

    return ret;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear();
    a.clear();
    a.resize(n + 1);
    ok = 0;
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (sum == 0)
    {
        cout << "YES\n";
        return;
    }
    if (k == 2)
    {
        cout << "NO\n";
        return;
    }

    dfs(1, 0);

    cout << (ok >= 2 ? "YES\n" : "NO\n");

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