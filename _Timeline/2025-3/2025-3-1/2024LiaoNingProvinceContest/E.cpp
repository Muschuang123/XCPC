#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int rn = n, rm = m;

    if (m % 2 == 0)
        swap(n, m);
    // 奇数 * 奇数 || 不能被4整除 * 奇数 || 2 * 2
    if (n % 2 && m % 2 || n % 4 && m % 2 || n == 2 && m == 2)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (m % 4 == 0)
        swap(n, m);
    // 能被4整除 * 奇数 || 能被4整除 * 偶数
    if (n % 4 == 0)
    {
        int cnt = 0;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i += 4)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = a[i + 1][j] = a[i + 2][j] = a[i + 3][j] = ++cnt;
            }
        }

        if (n == rn && m == rm)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j] << " \n"[j == m];
                }
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i][j] << " \n"[i == n];
                }
            }
        }
    }
    else // n 和 m 都不能被4整除
    {
        if (m > n)
            swap(n, m);
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        int cnt = 0;
        for (int i = 1, j = 1; j <= m; j += 2)
        {
            a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 2][j] = ++cnt;
            a[i + 3][j] = a[i + 4][j] = a[i + 5][j] = a[i + 5][j + 1] = ++cnt;
            a[i + 1][j + 1] = a[i + 2][j + 1] = a[i + 3][j + 1] = a[i + 4][j + 1] = ++cnt;
        }

        for (int i = 7; i <= n; i += 4)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = a[i + 1][j] = a[i + 2][j] = a[i + 3][j] = ++cnt;
            }
        }

        if (n == rn && m == rm)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j] << " \n"[j == m];
                }
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i][j] << " \n"[i == n];
                }
            }
        }
    }
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