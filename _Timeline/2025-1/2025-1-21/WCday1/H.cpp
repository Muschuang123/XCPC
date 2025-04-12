#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int l, r, i, ans;
};

bool cmp1(const node &a, const node &b)
{
    return a.r < b.r || a.r == b.r && a.l < b.l;
}

bool cmp2(const node &a, const node &b)
{
    return a.i < b.i;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<node> a(n + 1);
    set<int> ss;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
        a[i].ans = 0;
        ss.insert(i);
    }

    sort(a.begin() + 1, a.end(), cmp1);

    for (int i = 1; i <= n; i++)
    {
        auto it = ss.lower_bound(a[i].l);
        if (it == ss.end())
        {
            cout << -1 << '\n';
            return 0;
        }
        int cur = *it;
        if (cur > a[i].r)
        {
            cout << -1 << '\n';
            return 0;
        }
        
        ss.erase(cur);
        a[i].ans = cur;
    }

    sort(a.begin() + 1, a.end(), cmp2);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i].ans << ' ';
    }
    cout << '\n';

    return 0;
}