#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int n, m;
vector<vector<i64>> t, d;
vector<vector<vector<int>>> vis;
vector<vector<vector<i64>>> dis;

int ff(int x, int y)
{
    if (x > y)
        swap(x, y);
    if (x == 0 && y == 3)
        return 1;
    else 
        return y - x;
}

// 下 右 上 左
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dij(i64 x, i64 y, i64 f)
{
    dis[x][y][f] = t[x][y];
    priority_queue<array<i64, 4>, vector<array<i64, 4>>, greater<>> q;
    q.push({t[x][y], x, y, f});
    while (q.size())
    {
        auto [cur, x, y, f] = q.top();
        q.pop();
        if (vis[x][y][f])
            continue;
        vis[x][y][f] = 1;
        for (int i = 0; i < 4; i++)
        {
            auto [dx, dy] = dir[i];
            i64 xx = x + dx, yy = y + dy;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
            {
                if (dis[x][y][f] + t[xx][yy] + d[x][y] * ff(i, f) < dis[xx][yy][i])
                {
                    dis[xx][yy][i] = dis[x][y][f] + t[xx][yy] + d[x][y] * ff(i, f);
                    q.push({dis[xx][yy][i], xx, yy, i});
                }
            }
            if (i != f && dis[x][y][f] + d[x][y] * ff(i, f) < dis[x][y][i])
            {
                dis[x][y][i] = dis[x][y][f] + d[x][y] * ff(i, f);
                q.push({dis[x][y][i], x, y, i});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    t.assign(n + 1, vector<i64>(m + 1, 1e18));
    d.assign(n + 1, vector<i64>(m + 1, 1e18));
    dis.assign(n + 1, vector<vector<i64>>(m + 1, vector<i64>(4, 1e18)));
    vis.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(4)));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    dij(1, 1, 1);
    cout << dis[n][m][0] << '\n';
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

/*
1
3 5
0 999 0   0 0
0 999 0 999 0
0 0   0 999 0
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

*/