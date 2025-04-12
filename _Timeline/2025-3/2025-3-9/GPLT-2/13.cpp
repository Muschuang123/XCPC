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
    int rx, ry;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
                rx = i, ry = j;
        }
    }
    
    vector<vector<int>> ans(n + 1, vector<int>(m + 1, 1e9));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
    q.push({0, rx, ry});
    ans[rx][ry] = 0;
    while (q.size())
    {
        auto [co, x, y] = q.top();
        q.pop();
        vis[x][y] = 1;
        for (auto &[dx, dy] : dir)
        {
            int xx = x + dx, yy = y + dy;
            if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || a[xx][yy] == 0)
                continue;
            if (ans[x][y] + 1 < ans[xx][yy])
            {
                ans[xx][yy] = ans[x][y] + 1;
                q.push({ans[xx][yy], xx, yy});
            }
        }
        cout << "";
    }

    int k;
    cin >> k;
    map<int, vector<int>> mp;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (ans[y][x] != 1e9)
        mp[ans[y][x]].push_back(i);
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