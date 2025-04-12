#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    i64 cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][1] == '1')
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == '1')
                    vis[i][j] = 1;
                else 
                    break;
            }
        }
    }
    for (int j = 1; j <= m; j++)
    {
        if (a[1][j] == '1')
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i][j] == '1')
                    vis[i][j] = 1;
                else 
                    break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        if (a[i][j] == '1' && vis[i][j] == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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