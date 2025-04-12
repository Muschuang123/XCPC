#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[500005];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i].clear();
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++)
    {
        map<int, int> mp;
        mp[a[i]]++;
        for (auto &v : g[i])
        {
            mp[a[v]]++;
        }

        for (auto &[f, s] : mp)
        {
            if (s >= 2)
                ans[f] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
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