#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    int s0 = 0, s1 = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            t[i][j] = x == '0' ? -1 : 1;
            if (t[i][j] == 1)
            {
                s1 += a[i][j];
            }
            else
            {
                s0 += a[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t[i][j] += t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1];
        }
    }

    auto sum = [&](int i1, int j1, int i2, int j2)
    {
        return t[i2][j2] - t[i1 - 1][j2] - t[i2][j1 - 1] + t[i1 - 1][j1 - 1];
    };

    vector<int> v;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        for (int j = 1; j + k - 1 <= m; j++)
        {
            int s = sum(i, j, i + k - 1, j + k - 1);
            if (s != 0)
                v.push_back(abs(s));
        }
    }

    if (v.empty())
    {
        cout << (s0 == s1 ? "YES\n" : "NO\n");
        return;
    }
    int g = v.front();
    for (int i = 1; i < v.size(); i++)
    {
        g = __gcd(g, v[i]);
    }

    if (abs(s1 - s0) % g == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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