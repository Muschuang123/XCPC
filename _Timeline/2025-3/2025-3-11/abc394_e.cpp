#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 向两边拓展。
// O(n^4)
// 对于每一对 u, v 都有可能要验证是否 i, j 使得 a[i][u] == a[v][j]
// u, v, i, j ∈ [1, n] --> O(n^4)

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    queue<array<int, 3>> q;
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        q.push({0, i, i});
        vis[i][i] = 1;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!vis[i][j] && a[i][j] != '-')
            {
                q.push({1, i, j});
                vis[i][j] = 1;
            }

    while (q.size())
    {
        // u ---> v
        auto [co, u, v] = q.front();
        ans[u][v] = co;
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (a[i][u] != '-')
            for (int j = 1; j <= n; j++)
            {
                if (!vis[i][j] && a[i][u] == a[v][j])
                {
                    vis[i][j] = 1;
                    q.push({co + 2, i, j});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << " \n"[j == n];

    return 0;
}