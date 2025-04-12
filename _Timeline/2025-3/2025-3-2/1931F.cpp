#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 拓扑排序判环。如果没环，说明可以按照顺序排。
// 比如两个点之间有双向边，这个就不能排。最简单的二元环。

vector<int> g[200005];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
    vector<int> in(n + 1);
    while (k--)
    {
        int la = 0;
        int v;
        cin >> v;
        for (int i = 2; i <= n; i++)
        {
            cin >> v;
            g[la].push_back(v);
            in[v]++;
            la = v;
        }
    }

    queue<int> q;
    for (int i = 0; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> vis(n + 1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (int &v : g[x])
        {
            if (--in[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n";
            return;
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