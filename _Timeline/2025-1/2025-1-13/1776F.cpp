#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m + 1);
    vector<int> du(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
        du[a[i].first]++;
        du[a[i].second]++;
    }

    int tg = 1;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] != n - 1)
        {
            tg = i;
            break;
        }
    }

    int cnt = 0;
    vector<int> ans(m + 1);

    for (int i = 1; i <= m; i++)
    {
        if (a[i].first != tg && a[i].second != tg)
        {
            ans[i] = 1;
        }
        else
        {
            ans[i] = 2;
            cnt++;
        }
    }

    if (cnt == n - 1)
    {
        for (int i = 1; i <= m; i++)
        {
            if (ans[i] == 2)
            {
                ans[i] = 3;
                break;
            }
        }
        cout << 3 << '\n';
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " \n"[i == m];
    }
    else
    {
        cout << 2 << '\n';
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " \n"[i == m];
    }
    

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