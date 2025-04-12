#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 本题关键是隔离修改。
// 这种题，只修改一点，然后问整体的合法性，就是隔离修改。
// 合法性通常用一个 数据 来维护，本题是一个 数字。
// 判断是否合法的条件，我们要从大范围，具体到小范围。
// 然后每次 check 更改导致的 小范围的变化。

// 本题有个关键 就是 vis 数组，他使 check 不会重复。
// 如果重复就会导致多算或者少算。

// 做题时一定理清每个量是干啥的。

// 还有一个技巧就是，像这种排列的题，可以把 数 对应的 下标 存起来。

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), p(n + 1), idx(n + 1);
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i], idx[p[i]] = i;
    vector<int> dep(n + 1);
    for (int i = 1; i <= n; i++) dep[i] = __lg(i) + 1;

    int p2[17] = {1};
    for (int i = 1; i <= 16; i++)
    {
        p2[i] = p2[i - 1] * 2;
    }

    vector<int> vis(n + 1);
    // 查看两个儿子是否对得上
    auto check = [&](int x) -> bool
    {
        if (x > (n >> 1) || x < 1 || vis[x] || idx[x] + p2[dep[n] - dep[x]] > n)
            return 0;
        
        vis[x] = 1;
        // 儿子下标，这里有个公式。不过也可以 模拟一遍 算子树大小算出来。
        return x * 2 + 1 == p[idx[x] + 1] && x * 2 == p[idx[x] + p2[dep[n] - dep[x]]] ||
               x * 2 + 1 == p[idx[x] + p2[dep[n] - dep[x]]] && x * 2 == p[idx[x] + 1];
    };

    int acc = 0;
    for (int i = 1; i <= n; i++)
    {
        acc += check(p[i]);
    }

    vis.assign(n + 1, 0);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        acc -= check(p[x]) + check(p[y]) + check(p[x] / 2) + check(p[y] / 2);
        vis[p[x]] = vis[p[y]] = vis[p[x] / 2] = vis[p[y] / 2] = 0;
        swap(idx[p[x]], idx[p[y]]);
        swap(p[x], p[y]);
        acc += check(p[x]) + check(p[y]) + check(p[x] / 2) + check(p[y] / 2);
        vis[p[x]] = vis[p[y]] = vis[p[x] / 2] = vis[p[y] / 2] = 0;

        cout << (acc == (n >> 1) ? "YES\n" : "NO\n");
    }
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