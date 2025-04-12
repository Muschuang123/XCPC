#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/* 糖丸了，push_up 不会写了 */

int n;
struct SegTree
{
    int l, r, a, b = 2e5 + 5;
} t[200005 * 4];

vector<int> a, b;

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].a = a[l];
        t[p].b = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].a = max(t[p << 1].a, t[p << 1 | 1].a);
    t[p].b = min(t[p << 1].b, t[p << 1 | 1].b);
}

pair<int, int> ask(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return make_pair(t[p].a, t[p].b);
    }
    int mid = t[p].l + t[p].r >> 1;
    pair<int, int> ans = {0, n + 1};
    if (l <= mid)
    {
        // 这里注意，不能查两次。
        // 如果查两次的话，每一层查的个数翻倍
        // 一次查询变成 2^logn ， 非常慢。
        pair<int, int> res = ask(p << 1, l, r);
        ans.first = max(ans.first, res.first);
        ans.second = min(ans.second, res.second);
    }
    if (r > mid)
    {
        pair<int, int> res = ask(p << 1 | 1, l, r);
        ans.first = max(ans.first, res.first);
        ans.second = min(ans.second, res.second);
    }
    return ans;
}

void solve()
{
    cin >> n;
    a.assign(n + 1, 0);
    b.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    build(1, 1, n);

    vector<int> z(n + 1), vis(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
            vis[i] = 1;
        if (a[i] > b[i])
        {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        z[a[i]] = i;
        if (z[b[i]] == 0)
            continue;
        pair<int, int> res = ask(1, z[b[i]], i);
        if (res.first > b[i] || res.second < b[i])
            ;
        else 
            vis[i] = 1;
    }

    z.assign(n + 1, n + 1);
    for (int i = n; i >= 1; i--)
    {
        z[a[i]] = i;
        if (z[b[i]] == n + 1)
            continue;
        pair<int, int> res = ask(1, i, z[b[i]]);
        if (res.first > b[i] || res.second < b[i])
            ;
        else 
            vis[i] = 1;
    }

    if (count(vis.begin() + 1, vis.end(), 1) == n)
        cout << "YES\n";
    else 
        cout << "NO\n";
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