#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree
{
    int l, r, v, add;
};

vector<int> a;
vector<SegTree> t;

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
    // sum
    t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}

void spread(int p)
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

void change(int p, int l, int r, int d)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].v += d * (t[p].r - t[p].l + 1);
        t[p].add += d;
        return;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid)
        change(p << 1, l, r, d);
    if (r > mid)
        change(p << 1 | 1, l, r, d);
    t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}

int ask(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].v;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += ask(p << 1, l, r);
    if (r > mid)
        ans += ask(p << 1 | 1, l, r);
    return ans;

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    t.resize(4 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);
    while (m--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            change(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << ask(1, x, y) << '\n';
        }
        
    }


    return 0;
}