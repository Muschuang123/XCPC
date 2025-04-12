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
        return query(r) - query(l);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    fenwick f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        f.add(i, x);
    }

    i64 ans = 0;
    int cnt = 0;
    while (q--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            f.add(a, b - f.query(a - 1, a));
        }
        else if (op == 2)
        {
            ans ^= (f.query(b) / 100 - f.query(a - 1) / 100) * ++cnt;
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