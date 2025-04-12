#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> bac(n + 1);
    for (int i = 1; i <= n; i++)
        bac[i] = bac[i - 1] + a[i];

    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= k + 1; i++)
    {
        sum += a[i];
        if (i > 1)
        {
            int res = k + 1 - i;
            int can = min(z, res / 2);
            ans = max(ans, sum + (a[i - 1] + a[i]) * can + bac[i + res - can * 2] - bac[i]);
            if (z > res / 2 && res % 2 == 1)
            {
                ans = max(ans, sum + (a[i - 1] + a[i]) * can + a[i - 1]);
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}