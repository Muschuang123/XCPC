#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a.begin() + 1, a.end());

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, min(m / a[i].first, a[i].second) * a[i].first);
        if (i < n && a[i + 1].first == a[i].first + 1)
        {
            if (a[i].first * a[i].second + a[i + 1].first * a[i + 1].second <= m)
                ans = max(ans, a[i].first * a[i].second + a[i + 1].first * a[i + 1].second);
            else
            {
                int f = min(m / a[i].first, a[i].second) * a[i].first;
                int cnt = (m - f) / a[i + 1].first;
                f += cnt * a[i + 1].first;
                f += min({m - f, a[i + 1].second - cnt, min(m / a[i].first, a[i].second)});
                ans = max(ans, f);
            }
        }
    }
    cout << ans << '\n';
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