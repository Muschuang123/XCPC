#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[200005];
vector<int> mix[200005];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        mix[i].clear();
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        a[x] = 0;
    }

    vector<int> in(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        in[i] = m;

        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
            mix[i].push_back(x);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);

    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto &v : g[x])
        {
            if (--in[v] == 0)
                q.push(v);
        }

        int res = 0;
        if (mix[x].size())
            for (auto &v : mix[x])
            {
                res += a[v];
            }
        else 
            res = 0x3f3f3f3f3f3f3f3f;
        
        a[x] = min(a[x], res);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}