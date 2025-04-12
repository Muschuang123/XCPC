#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // vector<vector<int>> vis(k + 1, vector<int>(k + 1));
    set<pair<int, int>> vis;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> s0, s1;
    int k = sqrtl(2 * n) + 10;
    for (int len = 1; len <= k; len++)
    {
        for (int i = 0, j = len - 1; i < len; i++, j--)
        {
            // for (int j = 0; j < k / 3; j++)
            // {
                s0.push({i + j, i, j});
                int x = 3 * i + 1, y = 3 * j + 1;
                s1.push({x + y, x, y});
                s1.push({x + y + 1, x, y + 1});
                s1.push({x + y + 1, x + 1, y});
                s1.push({x + y + 4, x + 1, y + 1});
            // }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            while (1)
            {
                auto [d, x, y] = s0.top(); 
                s0.pop();
                if (!vis.count({3 * x + 1, 3 * y + 1}))
                {
                    cout << 3 * x + 1 << ' ' << 3 * y + 1 << '\n';
                    vis.insert({3 * x + 1, 3 * y + 1});
                    break;
                }
            }
        }
        else
        {
            while (1)
            {
                auto [d, x, y] = s1.top();
                s1.pop();
                if (!vis.count({x, y}))
                {
                    cout << x << ' ' << y << '\n';
                    vis.insert({x, y});
                    break;
                }
            }
        }
    }
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