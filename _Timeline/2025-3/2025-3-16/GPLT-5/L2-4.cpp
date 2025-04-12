#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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

    int ans = 0;
    int res = 0;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '0' || vis[i][j])
                continue;
            res++;
            int have = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (q.size())
            {
                auto [x, y] = q.front();
                if (a[x][y] > '1')
                    have = 1;
                q.pop();
                for (auto &[dx, dy] : dir)
                {
                    int xx = x + dx, yy = y + dy;
                    if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == '0' || vis[xx][yy])
                        continue;
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
                }
            }
            ans += have;
        }
    }
    cout << res << ' ' << ans << '\n';

    return 0;
}