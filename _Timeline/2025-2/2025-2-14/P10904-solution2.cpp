#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 本方法不相信评测机能跑 1e8
 * 所以枚举 n，而非 m
 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end());
    if (a[1] >= 0)
    {
        cout << --upper_bound(a.begin() + 1, a.end(), m) - a.begin() << '\n';
        return 0;
    }
    if (a[n] <= 0)
    {
        cout << a.end() - lower_bound(a.begin() + 1, a.end(), -m) << '\n';
        return 0;
    }

    int ans = 0;
    int r = --upper_bound(a.begin() + 1, a.end(), 0) - a.begin();
    int l = lower_bound(a.begin() + 1, a.end(), 0) - a.begin();

    for (int i = 1; i <= n; i++)
    {
        if (a[i] < -m || a[i] > m)
            continue;
        if (a[i] <= 0)
        {
            int t = m - 2 * abs(a[i]);
            int idx = --upper_bound(a.begin() + 1, a.end(), t) - a.begin();
            ans = max(ans, max(idx, r) - i + 1);
        }
        else
        {
            int t = m - 2 * a[i];
            int idx = lower_bound(a.begin() + 1, a.end(), -t) - a.begin();
            ans = max(ans, i - min(idx, l) + 1);
        }
    }

    cout << ans << '\n';

    return 0;
}