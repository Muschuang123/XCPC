#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;

int n, q;
int a[maxn];

struct SegTree
{
    int l, r;
    int mxd, mnd; // a[i] - i
    int mxp, mnp; // a[i] + i
    int dans, pans;
} t[maxn * 4];

void update(int p)
{
    // (a[r] - r) - (a[l] - l)
    t[p].dans = max({t[p << 1].dans, t[p << 1 | 1].dans, 
        t[p << 1 | 1].mxd - t[p << 1].mnd});
    // (a[l] + l) - (a[r] + r)
    t[p].pans = max({t[p << 1].pans, t[p << 1 | 1].pans,
        t[p << 1].mxp - t[p << 1 | 1].mnp});

    // update
    t[p].mxp = max(t[p << 1].mxp, t[p << 1 | 1].mxp);
    t[p].mnp = min(t[p << 1].mnp, t[p << 1 | 1].mnp);
    t[p].mxd = max(t[p << 1].mxd, t[p << 1 | 1].mxd);
    t[p].mnd = min(t[p << 1].mnd, t[p << 1 | 1].mnd);
}

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].mxd = t[p].mnd = a[l] - l;
        t[p].mxp = t[p].mnp = a[l] + l;
        t[p].dans = t[p].pans = 0;
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}

void change(int p, int l, int r, int d)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].mxd = t[p].mnd = d - l;
        t[p].mxp = t[p].mnp = d + l;
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid)
        change(p << 1, l, r, d);
    if (r > mid)
        change(p << 1 | 1, l, r, d);
    update(p);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cout << max(0, max(t[1].dans, t[1].pans)) << '\n';
    while (q--)
    {
        int p, x;
        cin >> p >> x;
        change(1, p, p, x);
        cout << max(0, max(t[1].dans, t[1].pans)) << '\n';
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