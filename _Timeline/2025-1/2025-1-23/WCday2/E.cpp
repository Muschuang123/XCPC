#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree
{
    int l, r, v, add;
};

int n, q;
vector<int> a;
vector<int> s;
vector<int> b;
SegTree t[4 * 200005];

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].v = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].v = max(t[p << 1].v, t[p << 1 | 1].v);
}

int ask(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].v;
    }
    int mid = t[p].l + t[p].r >> 1;
    long long ans = -1e18;
    if (l <= mid)
        ans = max(ans, ask(p << 1, l, r));
    if (r > mid)
        ans = max(ans, ask(p << 1 | 1, l, r));
    return ans;

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q;
    cin >> n >> q;
    a.resize(n + 1);
    s.resize(n + 1);
    b.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i] - s[i - 1];
    }
    
    build(1, 1, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << 0 << '\n';
            continue;
        }
        // cout << ask(1, l + 1, r) << '\n';
        // cout << ask(1, l + 1, r) + s[l - 1] << '\n';
        cout << max(0LL, ask(1, l + 1, r) + s[l - 1]) << '\n';
    }
    


    return 0;
}