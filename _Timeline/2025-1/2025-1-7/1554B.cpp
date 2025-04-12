#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 官方题解里有详细证明。
 * 只有对于 i * j > (n - 1) * n - k * n * 2 的时候，f(i, j) 才有可能比 f(n, n - 1) 大。
 * 考虑极端情况，让 i 最小，这个时候 j 是 n 才可以，两遍约一下，得到：
 *              i > n - 2 * k - 1。
 * 所以对于 i < n - 2 * k 的情况我们不用考虑。因为他不可能比 f(n, n - 1) 大。
 */

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = -1e18;
    for (int i = max(1LL, n - 2 * k); i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ans = max(ans, i * j - k * (a[i] | a[j]));
        }
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