#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> g[200005];
int ans = 0;

void solve()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();

    vector<int> in(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        g[i].push_back(x);
        in[x]++;
    }

    vector<int> vis(n + 1);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push({i, 1});
    }
    while (q.size())
    {
        auto [x, d] = q.front();
        q.pop();
        vis[x] = 1;
        ans = max(ans, d);
        for (auto &v : g[x])
        {
            if (--in[v] == 0)
            {
                q.push({v, d + 1});
            }
        }
    }

    cout << ans + 2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}