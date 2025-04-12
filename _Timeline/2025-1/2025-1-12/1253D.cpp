#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 直接建图，找到每个集合的最小值和最大值，
 * 如果交叉，就压缩（需要一个费用
 * 不交叉不用管。
 * 
 * 判断交叉 建立一个数组 a
 * 里面存着每个集合的最大值和最小值。
 * 因为是从小到大找集合，所以 a 是单调的。
 * 所以压缩的时候只需要看看当前集合和前一个是否交叉就行了。
 * 
 * 压缩的时候要用 while 循环，
 * 是因为集合扩大了之后一次可能压缩好几层。
 */

vector<bool> vis;
vector<int> g[200005];
pair<int, int> a[200005];
int p = 0;
int mx = 0;
int ans = 0;

void dfs(int x)
{
    vis[x] = 1;
    mx = max(mx, x);
    for (auto &v : g[x])
        if (!vis[v])
            dfs(v);
}

void zip(pair<int, int> ss)
{
    while (p > 0 && a[p - 1].second >= ss.first)
    {
        ans++;
        p--;
        ss.first = min(ss.first, a[p].first);
        ss.second = max(ss.second, a[p].second);
    }
    a[p] = ss;
    p++;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vis.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // i == minimum, mx == maximum
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        mx = 0;
        dfs(i);
        zip({i, mx});
    }

    cout << ans;

    return 0;
}