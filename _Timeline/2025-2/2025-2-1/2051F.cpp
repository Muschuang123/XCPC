#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q + 1);
    int l = m, r = m;
    int el = 0, er = n + 1; 
    int fl = 0;
    int fl2 = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i];
        if (l <= a[i] && a[i] <= r)
        {
            fl = 1;
        }
        if (fl)
        {
            el += a[i] > el;
            er -= a[i] < er;
        }
        if (a[i] < l)
        {
            l--;
        }
        if (a[i] > r)
        {
            r++;
        }
        if (l == r)
        {
            fl2 = 1;
        }
        int ans = 0;
        if (!fl2)
        {
            ans = el + min(er - 1, r) - max(el + 1, l) + 1 + n + 1 - er;
        }
        else
        {
            ans = el + n + 1 - er;
        }
        cout << min(n, ans) << " \n"[i == q];
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