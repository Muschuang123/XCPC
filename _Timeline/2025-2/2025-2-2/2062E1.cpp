#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 留住第一大的，把第二大的拿走，如果第一大的还在，就赢。不在，就试试拿第三大的。
 * 判断拿走第二大的 时候，第一大的在不在，只需要判断第一大的是不是第二大的孩子。
 * 比他大的都是他的孩子的话，那就不能拿。
 * 判断是不是孩子可以用 按照 dfs序 做出的 in[]、out[]。
 */

vector<int> g[400005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    vector<int> a(n + 1), vis(n + 1);
    map<int, vector<int>, greater<>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int tim = 0;
    vector<int> in(n + 1);
    vector<int> out(n + 1);

    function<void (int, int)> dfs = [&](int x, int fa)
    {
        in[x] = ++tim;
        for (auto &v : g[x])
            if (v != fa)
                dfs(v, x);
        out[x] = tim;
    };

    dfs(1, 0);

    int fi = n + 1, la = 0;

    for (auto &[k, v] : mp)
    {
        for (auto &i : v)
        {
            // 存在一个比他大的，不是他的孩子，就可以
            if (in[i] > fi || out[i] < la)
            {
                cout << i << '\n';
                return;
            }
        }
        // 这个地方需要隔离，因为相等 w 的不可以。
        for (auto &i : v)
        {
            fi = min(fi, in[i]);
            la = max(la, in[i]);
        }
    }
    cout << 0 << '\n';
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