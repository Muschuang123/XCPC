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

    queue<int> q;
    vector<int> a(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            // a[i]++;
        }
    }

    while (q.size())
    {
        int x = q.front();
        q.pop();
        ans = max(ans, a[x]);
        for (auto &v : g[x])
        {
            a[v] += a[x];
            if (--in[v] == 0)
            {
                q.push(v);
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