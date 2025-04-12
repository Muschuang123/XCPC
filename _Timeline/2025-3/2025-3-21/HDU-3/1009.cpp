#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct dsu
{
    int n;
    vector<int> fa;

    // Index 0 is invalid
    dsu(int _n = 0)
    {
        n = _n - 1;
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int fin(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = fin(fa[x]);
    }

    bool merg(int u, int v)
    {
        u = fin(u), v = fin(v);
        if (u == v)
            return 0;
        fa[v] = u;
        return 1;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    dsu d(n + 1);
    // idx[表面部落] = 实际部落
    // ridx[实际部落] = 表面部落
    // pos[人] = 实际部落
    // 注意，pos 是针对一个人的，而 idx 是针对一个部落的。
    vector<int> idx(n + 1), ridx(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
        idx[i] = ridx[i] = pos[i] = i;
    while (q--)
    {
        int op, a, b;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            // 两个部落的实际部落合并。
            // 结果：b 不合法、a 是 idx[a] 和 idx[b] 的表面部落
            d.merg(idx[a], idx[b]);
        }
        else if (op == 2)
        {
            cin >> a >> b;
            // 让 a 的实际部落变成 b 的实际部落
            pos[a] = idx[b];
        }
        else if (op == 3)
        {
            cin >> a >> b;
            // 让 a, b 的映射交换
            swap(ridx[idx[a]], ridx[idx[b]]);
            swap(idx[a], idx[b]);
        }
        else
        {
            cin >> a;
            // 查到 a 的实际部落，并且映射成表面部落
            cout << ridx[d.fin(pos[a])] << '\n';
        }
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