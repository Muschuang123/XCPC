#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool cmp1(const pair<i64, i64> &a, const pair<i64, i64> &b)
{
    return a.first - a.second < b.first - b.second;
}

bool cmp2(const pair<i64, i64> &a, const pair<i64, i64> &b)
{
    return a.second - a.first < b.second - b.first;
}

const int maxn = 2e5 + 5;
vector<int> g[maxn];
i64 a[maxn];
int sz[maxn];

void dfs1(int x, int fa)
{
    sz[x] = 1;
    for (auto &v : g[x])
    {
        if (v == fa)
            continue;
        dfs1(v, x);
        sz[x] += sz[v];
    }
}

// odd, even
pair<i64, i64> dfs2(int x, int fa)
{
    // leaf
    if (g[x].size() == 1 && g[x][0] == fa)
    {
        return {0, a[x]};
    }

    vector<pair<i64, i64>> odd;
    vector<pair<i64, i64>> eve;
    for (auto &v : g[x])
    {
        if (v == fa)
        {
            continue;
        }
        pair<i64, i64> pa = dfs2(v, x);
        if (sz[v] % 2)
        {
            odd.push_back(pa);
        }
        else
        {
            eve.push_back(pa);
        }
    }

    // can't change order.
    if (odd.empty())
    {
        // dfn x is odd
        i64 even = 0, od = 0;
        for (auto &[f, s] : eve)
        {
            even += s;
            od += f;
        }
        return {even, od + a[x]};
    }
    // cout << x << ' ' << fa << endl;

    int m = odd.size();
    // dfn[x] is odd
    // first child is even
    i64 even = 0;
    sort(odd.begin(), odd.end(), cmp1);
    for (int i = 0; i < (m + 1) / 2; i++)
    {
        even += odd[i].second;
    }
    for (int i = (m + 1) / 2; i < m; i++)
    {
        even += odd[i].first;
    }
    for (auto &pa : eve)
    {
        even += max(pa.first, pa.second);
    }

    // dfn x is even
    i64 od = 0;
    sort(odd.begin(), odd.end(), cmp2);
    for (int i = 0; i < (m + 1) / 2; i++)
    {
        od += odd[i].first;
    }
    for (int i = (m + 1) / 2; i < m; i++)
    {
        od += odd[i].second;
    }
    for (auto &pa : eve)
    {
        od += max(pa.first, pa.second);
    }

    return {even, od + a[x]};
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    pair<i64, i64> ans = dfs2(1, 0);
    cout << ans.first << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}