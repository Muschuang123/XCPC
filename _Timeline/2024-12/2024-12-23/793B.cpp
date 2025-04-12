#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> p = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
vector<vector<char>> a;
vector<vector<bool>> vis;
bool ans = 0;
int tx, ty;

void dfs(int x, int y, int dir, int turn)
{
    if (a[x][y] == 'T')
        ans = 1;
    if (ans)
        return;
    
    vis[x][y] = 1;

    auto [xx, yy] = p[dir];
    if (xx + x >= 1 && xx + x <= n && yy + y >= 1 && yy + y <= m && !vis[xx + x][yy + y] && a[xx + x][yy + y] != '*' && turn <= 2)
        dfs(xx + x, yy + y, dir, turn);

    if (turn <= 1)
    for (int o = 0; o < 4; o++)
    {
        if (o == dir || dir + o == 1 || dir + o == 6)
            continue;
        auto [i, j] = p[o];
        i += x;
        j += y;
        if (turn == 1 && i != tx && j != ty)
            continue;
        if (i >= 1 && i <= n && j >= 1 && j <= m && !vis[i][j] && a[i][j] != '*' && turn < 2)
            dfs(i, j, o, turn + 1);
    }
    vis[x][y] = 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    vis.resize(n + 1, vector<bool>(m + 1));
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                x = i;
                y = j;
            }
            if (a[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        dfs(x, y, i, 0);
    }

    cout << (ans ? "YES" : "NO");

    return 0;
}