#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + x[i];
    }

    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, (a + b) * x[i] + b * (s[n] - s[i] - (n - i) * x[i]));
        // cout << i << ' ' << ans << '\n';
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