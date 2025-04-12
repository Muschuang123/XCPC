#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[900005];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; i++)
        g[i].clear();
    vector<int> in(3 * n + 1);
    vector<array<int, 3>> cur;
    for (int i = 1; i <= m; i++)
    {
        int x, y, col;
        cin >> x >> y >> col;
        cur.push_back({x, y, col});
    }
    for (auto &[x, y, col] : cur)
    {
        if (col != (y + 1) / 2 && col != n + n - x + 1 && col != 2 * n + x - y / 2)
        {
            cout << "No\n";
            return;
        }
        for (auto &e : vector<int>{(y + 1) / 2, n + n - x + 1, 2 * n + x - y / 2})
        {
            if (e != col)
            {
                g[col].push_back(e);
                in[e]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= 3 * n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto &v : g[x])
        {
            if (--in[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= 3 * n; i++)
    {
        if (in[i])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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