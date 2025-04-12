#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 先想到 Aron 如何赢：
// 1. 开局 p 不是叶子，q是叶子
// 2. Nora 走一次没赢，Aron 赢了
// 没有其他情况，因为再走的话就是来回拉扯了。

// 第一种情况比较好算，直接 非叶子节点 * 叶子节点 就行了。
// 第二种情况的话，必须是毛毛虫倒数第二个节点k 有叶子结点相邻。
// 并且呢，p 没有没有相邻的叶子。
// 总结下来：
//      p 非叶 不邻叶
//      k 非叶 邻叶
//      q 非叶
// 满足这些条件的 p k q 就可以构成答案。
// 那么很快地，我们用一个 for 循环就可以求出谁是叶子
// 如果是叶子的话。
// 在对每一个节点，遍历相邻节点，告诉他们 自己是叶子。
// 最后通过 dfs 算出 满足条件的 p 的前缀和 用于计算

// 计算的时候我们 for q，遍历周围节点看看能不能作为 k
// 能作为 k 的话，我们再用前缀和 算可行的 p
// 如果 k 是 q 的父节点的话，算 (总的 - q 的前缀和)。

int n;
vector<int> g[200005];
// vis : 不是叶子 && 相邻的点都不是叶子
vector<int> leaf, pre, vis, father;

void dfs(int x, int fa)
{
    father[x] = fa;
    pre[x] += vis[x];
    for (int v : g[x])
    {
        if (v == fa)
            continue;
        dfs(v, x);
        pre[x] += pre[v];
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    leaf.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    vis.assign(n + 1, 1);
    father.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // find all leaves
    int all = 0;
    for (int i = 1; i <= n; i++)
    {
        leaf[i] = g[i].size() == 1;
        all += leaf[i];

        if (leaf[i])
        {
            vis[i] = 0;
            for (int v : g[i])
                vis[v] = 0;
        }
    }

    // count the answer which q is the leaf and p isn't leaf.
    i64 ans = 1LL * (n - all) * all;

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (leaf[i])
            continue;
        for (int v : g[i])
        {
            if (leaf[v] || vis[v])
                continue;
            if (v == father[i])
                ans += pre[1] - pre[i];
            else
                ans += pre[v];
        }
    }
    cout << ans << '\n';
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