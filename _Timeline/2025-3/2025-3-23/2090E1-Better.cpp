#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1), b(2 * n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        a[i + n] = a[i];
        b[i + n] = b[i];
    }
    int p = 0, ans = 0;
    i64 sum = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        sum += b[i] - a[i];
        if (sum >= 0)
        {
            ans = max(ans, i - p);
            sum = 0;
            p = i;
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