#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int d = a[i - 1] - a[i];
        int j = 0;
        while ((1 << j) - 1 < d)
        {
            j++;
        }
        int need = (1 << j) - 1;
        for (int k = j - 1; k >= 0; k--)
        {
            if (need - (1 << k) >= d)
                need -= (1 << k);
        }
        a[i] += need;
        ans = max(ans, j);
    }
    __lg
    cout << ans << '\n';
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