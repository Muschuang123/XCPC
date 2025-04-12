#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lim = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        lim = max(lim, b[i]);
    }
    int ans = abs(a[1] - b[1]);
    for (int i = 1; i <= n; i++)
    {
        ans = __gcd(ans, abs(a[i] - b[i]));
        if (ans <= lim)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}