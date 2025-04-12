#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct SegTree
{
    int l, r, v;
} t[200005 * 4];


vector<int> a;
map<int, int> mp;

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].v = 0;
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].v = max(t[p << 1].v, t[p << 1 | 1].v);
}

void change(int p, int l, int r, int d)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].v = max(t[p].v, d);
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid)
        change(p << 1, l, r, d);
    if (r > mid)
        change(p << 1 | 1, l, r, d);
    t[p].v = max(t[p << 1].v, t[p << 1 | 1].v);
}

int ask(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].v;
    }
    int mid = t[p].l + t[p].r >> 1;
    int ans = 0;
    if (l <= mid)
        ans = max(ans, ask(p << 1, l, r));
    if (r > mid)
        ans = max(ans, ask(p << 1 | 1, l, r));
    return ans;

}

struct qu 
{
    int r, a, i, ans;
};

bool cmp1(const qu &a, const qu &b)
{
    return a.r < b.r || a.r == b.r && a.a < b.a;
}

bool cmp2(const qu &a, const qu &b)
{
    return a.i < b.i;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    vector<qu> q(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    int cnt = 0;
    for (auto &[k, e] : mp)
    {
        e = ++cnt;
    }

    build(1, 1, cnt);

    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].r >> q[i].a;
        q[i].i = i;
    }
    
    sort(q.begin() + 1, q.end(), cmp1);

    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        int f = mp[a[i]];
        int res = f == 1 ? 0 : ask(1, 1, f - 1);
        change(1, f, f, res + 1);
        while (p <= m && q[p].r == i)
        {
            int t = (--mp.upper_bound(q[p].a))->second;
            q[p].ans = ask(1, 1, t);
            p++;
        }
    }

    sort(q.begin() + 1, q.end(), cmp2);

    for (int i = 1; i <= m; i++)
    {
        cout << q[i].ans << '\n';
    }
    

    return 0;
}
