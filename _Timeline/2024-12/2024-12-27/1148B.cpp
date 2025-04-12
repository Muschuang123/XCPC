#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += ta;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    if (k >= n || k >= m)
    {
        cout << -1 << '\n';
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= min(k + 1, n); i++)
    {
        int ind = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        if (ind + k - i + 1 > m)
        {
            cout << -1 << '\n';
            return 0;
        }
        ans = max(ans, b[ind + k - i + 1]);
    }
    cout << ans + tb << '\n';

    //   2 4 6 8
    // 1 2 3 9 10

    return 0;
}