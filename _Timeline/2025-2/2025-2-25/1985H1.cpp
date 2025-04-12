#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;
bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return 0;
    return 1;
}

void solve()
{
    cin >> n >> m;
    vector<int> cnt(1);
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] || a[i][j] == '.')
                continue;
            
            queue<pair<int, int>> q;
            cnt.push_back(0);
            q.push({i, j});
            vis[i][j] = cnt.size() - 1;
            while (q.size())
            {
                auto [x, y] = q.front();
                q.pop();
                cnt.back()++;
                for (auto [dx, dy] : dir)
                {
                    int xx = x + dx, yy = y + dy;
                    if (check(xx, yy) && a[xx][yy] == '#' && !vis[xx][yy])
                    {
                        q.push({xx, yy});
                        vis[xx][yy] = cnt.size() - 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        set<int> ss;
        if (i > 1)
        {
            i--;
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] && !ss.count(vis[i][j]))
                {
                    ss.insert(vis[i][j]);
                    res += cnt[vis[i][j]];
                }
            }
            i++;
        }

        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] && !ss.count(vis[i][j]))
            {
                ss.insert(vis[i][j]);
                res += cnt[vis[i][j]];
            }
            res += a[i][j] == '.';
        }

        if (i < n)
        {
            i++;
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] && !ss.count(vis[i][j]))
                {
                    ss.insert(vis[i][j]);
                    res += cnt[vis[i][j]];
                }
            }
            i--;
        }
        ans = max(ans, res);
    }

    for (int j = 1; j <= m; j++)
    {
        int res = 0;
        set<int> ss;
        if (j > 1)
        {
            j--;
            for (int i = 1; i <= n; i++)
            {
                if (vis[i][j] && !ss.count(vis[i][j]))
                {
                    ss.insert(vis[i][j]);
                    res += cnt[vis[i][j]];
                }
            }
            j++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i][j] && !ss.count(vis[i][j]))
            {
                ss.insert(vis[i][j]);
                res += cnt[vis[i][j]];
            }
            res += a[i][j] == '.';
        }

        if (j < m)
        {
            j++;
            for (int i = 1; i <= n; i++)
            {
                if (vis[i][j] && !ss.count(vis[i][j]))
                {
                    ss.insert(vis[i][j]);
                    res += cnt[vis[i][j]];
                }
            }
            j--;
        }
        ans = max(ans, res);
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