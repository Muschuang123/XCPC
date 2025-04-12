#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[100005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ok = 1;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() != 1 && g[i].size() != 2)
        {
            ok = 0;
        }
        if (g[i].size() == 1)
            ans.push_back(i);
    }

    if (!ok)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans[0] << ' ' << ans[1] << '\n';    
    }
    

    return 0;
}