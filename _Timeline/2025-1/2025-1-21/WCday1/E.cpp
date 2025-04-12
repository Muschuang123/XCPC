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

    sort(a.begin() + 1, a.end());
    int l1, l2, r1, r2;
    int d = n / 2;
    if (d % 2 == 0)
    {
        l1 = a[d / 2], r1 = a[d / 2 + 1];
        l2 = a[d + d / 2], r2 = a[d + d / 2 + 1];
    }
    else
    {
        l1 = r1 = a[(d + 1) / 2];
        l2 = r2 = a[d + (d + 1) / 2];
    }
    
    if (l1 == l2 && r1 == r2 && l1 == r1)
    {
        int ans = 1e18;

        // 4种情况。都有可能是最优
        int res = 0;
        for (int i = 1; i <= d; i++)
            res += abs(a[i] - l1);
        for (int i = d + 1; i <= n; i++)    
            res += abs(a[i] - (l1 + 1));
        ans = min(ans, res);

        res = 0;
        for (int i = 1; i <= d; i++)
            res += abs(a[i] - l1);
        for (int i = d + 1; i <= n; i++)    
            res += abs(a[i] - (l1 - 1));
        ans = min(ans, res);

        res = 0;
        for (int i = 1; i <= d; i++)
            res += abs(a[i] - (l1 - 1));
        for (int i = d + 1; i <= n; i++)    
            res += abs(a[i] - l1);
        ans = min(ans, res);

        res = 0;
        for (int i = 1; i <= d; i++)
            res += abs(a[i] - (l1 + 1));
        for (int i = d + 1; i <= n; i++)    
            res += abs(a[i] - l1);
        ans = min(ans, res);

        cout << ans << '\n';
    }
    else
    {
        int ans = 0;
        for (int i = 1; i <= d; i++)
            ans += abs(a[i] - l1);
        for (int i = d + 1; i <= n; i++)
            ans += abs(a[i] - l2);
        cout << ans << '\n';
    }
    

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