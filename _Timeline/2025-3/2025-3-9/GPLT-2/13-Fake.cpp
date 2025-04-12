#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    map<int, vector<int>> mp;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        // if (x < 1 || x > n || y < 1 || y > m)
        //     continue;
        swap(x, y);
        int mn = 1e9;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        queue<array<int, 3>> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (q.size())
        {
            auto [x, y, co] = q.front();
            q.pop();
            if (a[x][y] == 2)
            {
                mn = co;
                break;
            }
            for (auto &[dx, dy] : dir)
            {
                int xx = x + dx, yy = y + dy;
                if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || a[xx][yy] == 0)
                    continue;
                vis[xx][yy] = 1;
                q.push({xx, yy, co + 1});
            }
        }
        if (mn != 1e9)
        {
            mp[mn].push_back(i);
        }
    }

    for (auto &[f, v] : mp)
    {
        if (v.size() != 1)
            continue;
        cout << v.back() << ' ' << f << '\n';
        return 0;
    }
    cout << "No winner.\n";

    return 0;
}