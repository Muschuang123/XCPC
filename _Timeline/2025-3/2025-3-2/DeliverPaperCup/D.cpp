#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 n, m, k;
vector<i64> a;

bool check(i64 mid)
{
    i64 res = 0;
    i64 acu = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= mid)
        {
            res += a[i] - mid;
        }
        else
        {
            acu += mid - a[i];
        }
    }
    return acu <= k + min(m, res);
}

void solve()
{
    cin >> n >> m >> k;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    i64 l = 0, r = (accumulate(a.begin() + 1, a.end(), 0LL) + k) / n + 1;
    while (l + 1 < r)
    {
        i64 mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid;
    }
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}