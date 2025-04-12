#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<i64> a(m + 1);
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> q(m + 1);
    vector<vector<int>> w(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            q[j].push({x, i});
        }
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    }

    int comp = 0;
    vector<int> vis(n + 1);
    while (comp < n)
    {
        queue<int> can;
        int fl = 0;
        for (int j = 1; j <= m; j++)
        {
            while (q[j].size() && q[j].top().first <= a[j])
            {
                auto [f, s] = q[j].top();
                q[j].pop();
                vis[s]++;
                if (vis[s] == m)
                {
                    fl = 1;
                    can.push(s);
                    comp++;
                }
            }
        }
        if (!fl)
        {
            cout << "NO\n";
            return;
        }
        while (can.size())
        {
            int i = can.front();
            can.pop();
            for (int j = 1; j <= m; j++)
            {
                a[j] += w[i][j];
            }
        }
    }
    cout << "YES\n";
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