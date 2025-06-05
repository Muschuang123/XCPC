// https://www.luogu.com.cn/problem/P3372
#include <bits/stdc++.h>
using i64 = long long;
#define int long long
using namespace std;

const int maxn = 1e5 + 5;

struct SegTree
{
    struct Node
    {
        int l, r, v, add;
    } t[maxn * 4];

    int a[maxn];

    void pushup(int p)
    {
        t[p].v = t[p << 1].v + t[p << 1 | 1].v;
    }

    void pushdown(int p)
    {
        if (t[p].add)
        {
            t[p << 1].v += t[p].add * (t[p << 1].r - t[p << 1].l + 1);
            t[p << 1 | 1].v += t[p].add * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
            t[p << 1].add += t[p].add;
            t[p << 1 | 1].add += t[p].add;
            t[p].add = 0;
        }
    }

    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r;
        if (l == r)
        {
            t[p].v = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void change(int p, int l, int r, int d)
    {
        if (l <= t[p].l && t[p].r <= r)
        {
            t[p].v += d * (t[p].r - t[p].l + 1);
            t[p].add += d;
            return;
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        if (l <= mid)
            change(p << 1, l, r, d);
        if (r > mid)
            change(p << 1 | 1, l, r, d);
        pushup(p);
    }

    int ask(int p, int l, int r)
    {
        if (l <= t[p].l && t[p].r <= r)
        {
            return t[p].v;
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        i64 ans = 0;
        if (l <= mid)
            ans += ask(p << 1, l, r);
        if (r > mid)
            ans += ask(p << 1 | 1, l, r);
        return ans;
    }
} T;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> T.a[i];
    }

    T.build(1, 1, n);
    while (m--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            T.change(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << T.ask(1, x, y) << '\n';
        }
    }

    return 0;
}
