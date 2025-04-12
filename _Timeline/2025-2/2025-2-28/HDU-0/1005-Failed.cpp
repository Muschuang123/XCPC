#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 并非中位数。

vector<i64> g[1000006];
vector<i64> a;

void solve()
{
    int n, m;
    cin >> n >> m;
    a.clear();
    for (int i = 0; i < m; i++) g[i].clear();

    for (int i = 1; i <= n; i++)
    {
        i64 x;
        cin >> x;
        g[x % m].push_back(x);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (g[i].empty())
            continue;
        
        cnt++;
        sort(g[i].begin(), g[i].end());
        i64 mid = g[i][g[i].size() / 2];
        for (int j = 0; j < g[i].size(); j++)
        {
            if (j == g[i].size() / 2)
                continue;
            a.push_back(abs(g[i][j] - mid) / m);
        }

    }

    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++)
        a[i] += a[i - 1];

    int q;
    cin >> q;
    i64 ans = 0;
    while (q--)
    {
        i64 k;
        cin >> k;
        ans = (ans * 13331 + (a.end() - upper_bound(a.begin(), a.end(), k) + cnt)) % 998244353;
    }
    cout << ans << '\n';

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