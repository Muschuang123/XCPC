#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, -pre[i] + suf[i + 1]);
    }

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