/*
    from: jiangly
*/
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

    int ans = 0;
    for (int i = 3; i <= n; i++)
    {
        ans += max(0LL, a[i]);
    }
    ans += max(0LL, a[1] + max(0LL, n > 1 ? a[2] : 0LL));
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