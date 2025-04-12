#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct fenwick
{
    int n;
    vector<i64> t;

    fenwick(int _n = 0)
    {
        n = _n - 1;
        t.resize(n + 1);
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    void add(int index, i64 delta)
    {
        for (int i = index; i <= n; i += lowbit(i))
            t[i] += delta;
    }

    i64 query(int index)
    {
        i64 ans = 0;
        for (int i = index; i > 0; i -= lowbit(i))
            ans += t[i];
        return ans;
    }

    i64 query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

struct qu
{
    int t, x, i, res;
};

bool cmp1(const qu &a, const qu &b)
{
    return a.t < b.t;
}

bool cmp2(const qu &a, const qu &b)
{
    return a.i < b.i || a.i == b.i && a.t < b.t;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<qu> q(2 * m + 1);
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        q[i] = {l - 1, a[c], i, 0};
        q[m + i] = {r, a[c], i, 0};
    }

    sort(q.begin() + 1, q.end(), cmp1);

    fenwick f(n + 1);

    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        while (p <= 2 * m && q[p].t < i)
        {
            q[p].res = f.query(q[p].x);
            p++;
        }
        f.add(a[i], 1);
    }
    while (p <= 2 * m && q[p].t <= n)
    {
        q[p].res = f.query(q[p].x);
        p++;
    }
    sort(q.begin() + 1, q.end(), cmp2);

    for (int i = 2; i <= 2 * m; i += 2)
    {
        cout << q[i - 1].t + q[i].res - q[i - 1].res << '\n';
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