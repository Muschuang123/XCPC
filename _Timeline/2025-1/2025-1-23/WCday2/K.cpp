#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
bool check(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    // vector<vector<int>> cnt(n + 1, vector<int>(m + 1));
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (a[i][j] != '1')
    //             continue;

    //         if (i > 1 && a[i - 1][j] == '0')
    //             cnt[i][j]++;
    //         if (i < n && a[i + 1][j] == '0')
    //             cnt[i][j]++;
    //         if (j > 1 && a[i][j - 1] == '0')
    //             cnt[i][j]++;
    //         if (j < m && a[i][j + 1] == '0')
    //             cnt[i][j]++;
    //     }
    // }

    vector<int> ans;
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '1' && !vis[i][j])
            {
                int res = 0;
                queue<pair<int, int>> q;
                set<pair<int, int>> ss;
                q.push({i, j});
                vis[i][j] = 1;
                while (q.size())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto [dx, dy] : dir)
                    {
                        if (!check(x + dx, y + dy))
                            continue;
                        if (a[x + dx][y + dy] == '1' && !vis[x + dx][y + dy])
                        {
                            q.push({x + dx, y + dy});
                            vis[x + dx][y + dy] = 1;
                        }
                        if (a[x + dx][y + dy] == '0' && !ss.count(make_pair(x + dx, y + dy)))
                        {
                            res++;
                            ss.insert({x + dx, y + dy});
                        }
                    }
                }
                ans.push_back(res);
            }
        }
    }

    cout << *min_element(ans.begin(), ans.end());

    return 0;
}