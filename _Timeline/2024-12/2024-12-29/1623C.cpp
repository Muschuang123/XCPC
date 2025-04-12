#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a;

bool check(int mid)
{
    vector<int> c = a;
    for (int i = n; i >= 3; i--)
    {
        if (c[i] < mid)
        {
            return 0;
        }
        int res = c[i] - mid;
        res = min(res, a[i]) / 3;
        c[i - 1] += res;
        c[i - 2] += res * 2;
    }
    if (c[1] < mid || c[2] < mid)
        return 0;

    return 1;
}

void solve()
{
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = 1e9 + 7;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}