#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[1003];

void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        g[i].clear();

    int m = n - 1;
    vector<int> du(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++;
        du[v]++;
    }

    if (du[x] == 1 || du[x] == 0)
    {
        cout << "Ayush\n";
        return;
    }
    
    if (n % 2 == 1)
    {
        cout << "Ashish\n";
    }
    else
    {
        cout << "Ayush\n";
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