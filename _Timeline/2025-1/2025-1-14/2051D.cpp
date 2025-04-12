#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    int sum = accumulate(a.begin() + 1, a.end(), 0LL);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        // t = a[i] + a[j]
        // sum - t >= x && sum - t <= y
        //          as same as
        // sum - x >= t && sum - y <= t
        int up = --upper_bound(a.begin() + 1, a.end(), sum - x - a[i]) - a.begin();
        int down = lower_bound(a.begin() + 1, a.end(), sum - y - a[i]) - a.begin();
        if (up < down)
            continue;
        ans += up - down + 1;
        if (a[up] >= a[i] && a[down] <= a[i])
            ans--;
    }
    cout << ans / 2 << '\n';
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