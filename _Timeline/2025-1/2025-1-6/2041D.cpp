#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    BFS序 + 枚举所有状态
    可以找到平面最短路。
    不能超过3步只需要不走第4步就行了。
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<pair<int, int>> d{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    cin >> n >> m;
    char a[n + 1][m + 1] = {0};
    int f[n + 1][m + 1][4][4] = {0};
    a.resize(n + 1, vector<char>(m + 1, 0));

    int sx, sy, tx, ty;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                sx = i, sy = j;
            if (a[i][j] == 'T')
                tx = i, ty = j;
        }
    }

    queue<array<int, 5>> q;
    q.push({sx, sy, 0, 0, 0});
    while (q.size())
    {
        auto [x, y, dir, len, cnt] = q.front();
        q.pop();
        if (a[x][y] == '#' || f[x][y][dir][cnt])
            continue;

        f[x][y][dir][cnt] = len;

        for (int i = 0; i < 4; i++)
        {
            auto [dx, dy] = d[i];
            if (i != dir)
            {
                q.push({x + dx, y + dy, i, len + 1, 1});
            }
            else if (cnt < 3)
            {
                q.push({x + dx, y + dy, dir, len + 1, cnt + 1});
            }
        }
    }

    int ans = 1e18;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (f[tx][ty][i][j] != 0)
                ans = min(ans, f[tx][ty][i][j]);
        }
    }

    cout << (ans == 1e18 ? -1 : ans);

    return 0;
}

