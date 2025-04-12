#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<i64, i64>> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].first >> b[i].second;
    }

    vector<pair<i64, i64>> p[4];
    for (int i = 0; i < 4; i++)
        p[i].resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[0][i].first = a[i].first + a[i].second;
        p[0][i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        p[1][i].first = -a[i].first + a[i].second;
        p[1][i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        p[2][i].first = -a[i].first - a[i].second;
        p[2][i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        p[3][i].first = a[i].first - a[i].second;
        p[3][i].second = i;
    }
    for (int i = 0; i < 4; i++)
    {
        sort(p[i].begin() + 1, p[i].end());
    }

    i64 ans = 1e18;
    for (int i = 1; i <= m; i++)
    {
        i64 res = 0;
        for (int j = 0; j < 4; j++)
        {
            int idx = p[j].back().second;
            res = max(res, abs(a[idx].first - b[i].first) + abs(a[idx].second - b[i].second));
        }
        ans = min(ans, res);
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