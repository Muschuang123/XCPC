#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    if LCM % GCD == 0:
        then: exist n * m == LCM / GCD
            and: gcd(n, m) == 1 (so that gcd(GCD * n, GCD * m) == GCD)
            finally: ( GCD * n , GCD * m ) satisfy the need.
            check: GCD * n, GCD * m ∈ [l, r].

*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int l, r, x, y;
    cin >> l >> r >> x >> y;

    int ans = 0;
    if (y % x != 0)
    {
        cout << 0;
        return 0;
    }
    int res = y / x;
    for (int i = 1; i * i <= res; i++)
    {
        if (res % i == 0)
        if (l <= i * x && i * x <= r && l <= res / i * x && res / i * x <= r && __gcd(i, res / i) == 1)
        {
            ans += 2;
            if (i == res / i)
                ans--;
        }
    }
    cout << ans;

    return 0;
}