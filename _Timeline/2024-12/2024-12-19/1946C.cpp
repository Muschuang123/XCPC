#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> g[100005];
int ans = 0;

int dfs(int x, int fa, int need)
{
    int sum = 1;
    for (auto &v : g[x])
    {
        if (v != fa)
        {
            int res = dfs(v, x, need);
            if (res == -1)
                ans++;
            else 
                sum += res;
        }
    }
    if (sum >= need)
        return -1;
    else 
        return sum;
}

bool check(int x)
{
    ans = 0;
    int res = dfs(1, 0, x);
    return ans - (res != -1) >= k;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int l = 0, r = n + 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
    
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