#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 容斥：
 * A: 所有情况，c + 1 里面任意拿两个，另外考虑 x == y 的情况，再加上 c + 1。
 * B: x + y = a[i] --> x: [0, a[i] / 2]; y: [(a[i] + 1) / 2, a[i]]。一共 a[i] / 2 + 1 种情况。
 * C: y - x = a[i] --> x: [0, c - a[i]]; y: [a[i], c]。一共 c - a[i] + 1 种情况。
 * D: a[i] + a[j] = x + y + y - x = 2 * y --> (a[i] + a[j]) % 2 == 0。
 *      奇数加奇数，偶数加偶数。可以自己加自己。
 * i64 ans = A - B - C + D。
 */

void solve()
{
    i64 n, c;
    cin >> n >> c;
    vector<i64> a(n + 1);
    i64 ji = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ji += a[i] % 2;
    }

    i64 ans = (c + 1) * c / 2 + c + 1;
    for (int i = 1; i <= n; i++)
    {
        ans -= a[i] / 2 + 1;
        ans -= c - a[i] + 1;
    }
    ans += (n - ji) * (n - ji - 1) / 2 + ji * (ji - 1) / 2 + n;

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