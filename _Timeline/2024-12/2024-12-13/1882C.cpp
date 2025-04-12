#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ou = 0;
    int ans = 0;
    int p = n % 2 == 0 ? n + 1 : n;
    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 1 && a[i] >= 0)
        {
            ans += a[i];
            ans += ou;
            ou = 0;
            p = i;
        }
        if (i % 2 == 0 && a[i] >= 0)
        {
            ou += a[i];
        }
    }
    int res = 0;
    int sum = 0;
    ou = 0;
    for (int i = p - 1; i >= 1; i--)
    {
        if (i % 2 == 0)
        {
            res = max(res, ou);
            if (a[i] >= 0)
                ou += a[i];
        }
        if (i % 2 == 1)
            res = max(res, ou + a[i]);
    }
    cout << ans + res << '\n';

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