#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> a(n + 1, vector<i64>(m + 1));
    vector<i64> zo(m + n + 1), yb(m + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            zo[i + j] += a[i][j];
            yb[i + m - j + 1] += a[i][j];
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, zo[i + j] + yb[i + m - j + 1] - a[i][j]);
        }
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