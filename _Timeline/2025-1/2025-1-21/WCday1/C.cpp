#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }

    vector<array<int, 4>> ans;
    auto work = [&](int i, int j, int x, int y)
    {
        swap(a[i][j], a[x][y]);
        ans.push_back({i, j, x, y});
    };

    // i, j ---> x, y
    auto move = [&](int i, int j, int x, int y)
    {
        auto movex = [&]()
        {
            while (i < x)
            {
                work(i, j, i + 1, j);
                i++;
            }
            while (i > x)
            {
                work(i, j, i - 1, j);
                i--;
            }
        };
        auto movey = [&]()
        {
            while (j < y)
            {
                work(i, j, i, j + 1);
                j++;
            }
            while (j > y)
            {
                work(i, j, i, j - 1);
                j--;
            }
        };
        if (i > x)
        {
            // i, j 在 x, y 的下方，这保证了 j 这一行畅通无阻
            movey();
            movex();
        }
        else
        {
            // i, j 在 x, y 的右方，这保证了 i 这一列畅通无阻
            movex();
            movey();
        }
    };

    int x = 1, y = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 可能会和下面的相撞，必须while
            while (a[i][j] == 1)
            {
                move(i, j, x, y);
                a[x][y] = 2;
                y++;
                if (y == n / 2 + 1)
                {
                    y = 1;
                    x++;
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [i, j, x, y] : ans)
    {
        cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
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