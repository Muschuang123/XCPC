#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 究极大模拟。。

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
    vector<int> mxi(1), mxj(1), mni(1), mnj(1);
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
            mxi.push_back(0);
            mxj.push_back(0);
            mni.push_back(n);
            mnj.push_back(m);
            q.push({i, j});
            vis[i][j] = cnt.size() - 1;
            while (q.size())
            {
                auto [x, y] = q.front();
                q.pop();
                cnt.back()++;
                mxi.back() = max(mxi.back(), x + 1);
                mxj.back() = max(mxj.back(), y + 1);
                mni.back() = min(mni.back(), x - 1);
                mnj.back() = min(mnj.back(), y - 1);
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
            mxi.back() = min(n, mxi.back());
            mxj.back() = min(m, mxj.back());
            mni.back() = max(1, mni.back());
            mnj.back() = max(1, mnj.back());
        }
    }

    vector<int> resi(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int &res = resi[i];
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
    }

    vector<int> resj(m + 1);
    for (int j = 1; j <= m; j++)
    {
        int &res = resj[j];
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
    }

    vector<vector<int>> dec(n + 2, vector<int>(m + 2));
    for (int i = 0; i < cnt.size(); i++)
    {
        dec[mni[i]][mnj[i]] += cnt[i];
        dec[mni[i]][mxj[i] + 1] -= cnt[i];
        dec[mxi[i] + 1][mnj[i]] -= cnt[i];
        dec[mxi[i] + 1][mxj[i] + 1] += cnt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dec[i][j] += dec[i - 1][j] + dec[i][j - 1] - dec[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            set<int> ss;
            int res = resi[i] + resj[j] - dec[i][j];
            // for (int ii = max(1, i - 1); ii <= min(i + 1, n); ii++)
            // {
            //     for (int jj = max(1, j - 1); jj <= min(j + 1, m); jj++)
            //     {
            //         if (vis[ii][jj] && !ss.count(vis[ii][jj]))
            //         {
            //             res -= cnt[vis[ii][jj]];
            //             ss.insert(vis[ii][jj]);
            //         }
            //     }
            // }
            res -= a[i][j] == '.';
            ans = max(ans, res);
        }
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