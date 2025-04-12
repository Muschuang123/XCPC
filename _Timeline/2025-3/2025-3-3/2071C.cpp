#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int n, st, en;
vector<int> g[100005];
vector<int> in, out, num;
int cnt = 0;

void dfs(int x, int fa)
{
    in[x] = ++cnt;
    num[cnt] = x;
    for (int &v : g[x])
    {
        if (v == fa)
            continue;
        dfs(v, x);
    }
    out[x] = cnt;
}

void solve()
{
    cin >> n >> st >> en;
    cnt = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);
    num.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(en, 0);
    vector<int> ans;
    for (int &v : g[en])
    {
        for (int i = out[v]; i >= in[v]; i--)
        {
            ans.push_back(num[i]);
        }
    }
    ans.push_back(en);
    for (int &e : ans)
    {
        cout << e << ' ';
    }
    cout << '\n';
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