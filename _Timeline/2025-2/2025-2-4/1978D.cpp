#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n, c;
    cin >> n >> c;
    vector<i64> a(n + 1), pre(n + 1);
    multiset<i64> l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1)
            a[i] += c;
        pre[i] = pre[i - 1] + a[i];
        r.insert(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        i64 x = a[i];
        r.extract(a[i]);

        if (l.size() && *l.rbegin() >= x || r.size() && *r.rbegin() > x)
        {
            ans += l.size();
            x += pre[i - 1];
        }
        if (r.size() && *r.rbegin() > x)
        {
            ans++;
        }

        cout << ans << " \n"[i == n];
        l.insert(a[i]);
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