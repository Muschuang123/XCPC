#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[200005];
// dp[i][val] 代表：i 的子树中有一条链。
// val: 0 不在链上 | 1 在链端点 | 2 在链中间
// dp 的过程中只考虑 子树（包括自己）中的联通块数量
vector<vector<int>> dp;

void dfs(int x, int fa)
{
    // 初始状态，只删掉自己一个点
    dp[x][1] = (int)g[x].size() - 1;
    vector<int> vec;
    // v 是 x 的儿子
    for (int v : g[x])
    {
        if (v == fa)
            continue;
        dfs(v, x);

        // 如果儿子节点也是 0，联通块数量不变
        // 如果儿子节点构成链，那么父亲的出现 属于添加了一个联通块
        dp[x][0] = max({dp[x][0], dp[v][0], dp[v][1] + 1, dp[v][2] + 1});

        // 只能从孩子也是端点的状态转移而来，
        // 转移之后，不算父亲的父亲，不算这个儿子，剩下的链接都断开
        // 这样就多了 g[x].size() - 2 个联通块
        dp[x][1] = max(dp[x][1], dp[v][1] + (int)g[x].size() - 2);

        vec.push_back(dp[v][1]);
    }
    
    // 如果有超过 2 个儿子，那么可以挑选两个孩子构成端点的链，通过父亲链接成一个
    // 不算父亲的父亲，不算两个儿子，多了 g[x].size() - 3 个联通块
    if (vec.size() >= 2)
    {
        sort(vec.begin(), vec.end(), greater<>());
        dp[x][2] = vec[0] + vec[1] + (int)g[x].size() - 3;
    }
}

void solve()
{
    int n;
    cin >> n;
    dp.assign(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 制造一个假父亲，便于计算。
    g[1].push_back(0);

    dfs(1, 0);

    cout << *max_element(dp[1].begin(), dp[1].end()) << '\n';
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