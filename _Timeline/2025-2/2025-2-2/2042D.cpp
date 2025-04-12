#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct user
{
    int l, r, i;
};

bool cmpl(const user &a, const user &b)
{
    return a.l < b.l || a.l == b.l && a.r > b.r;
}

bool cmpr(const user &a, const user &b)
{
    return a.r > b.r || a.r == b.r && a.l < b.l;
}

void solve()
{
    int n;
    cin >> n;
    vector<user> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
    }

    sort(a.begin() + 1, a.end(), cmpl);

    vector<int> ans(n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i].l == a[i + 1].l && a[i].r == a[i + 1].r)
            vis[a[i].i] = vis[a[i + 1].i] = 1;
    }

    set<int> l, r;
    for (int i = 1; i <= n; i++)
    {
        auto it = r.lower_bound(a[i].r);
        if (it != r.end())
            ans[a[i].i] += *it - a[i].r;
        r.insert(a[i].r);
    }
    
    sort(a.begin() + 1, a.end(), cmpr);
    
    for (int i = 1; i <= n; i++)
    {
        auto it = l.upper_bound(a[i].l);
        if (it != l.begin())
            ans[a[i].i] += a[i].l - *--it;
        l.insert(a[i].l);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            cout << 0 << '\n';
        else 
            cout << ans[i] << '\n';
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