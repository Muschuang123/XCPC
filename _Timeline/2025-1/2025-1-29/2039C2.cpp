#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, m;
    cin >> x >> m;
    // let i = x ^ y
    int ans = 0;
    // i <= x : brute force
    for (int i = 1; i <= min(x, m); i++)
    {
        if ((x ^ i) % i == 0)
            ans++;
    }

    // i > x
    if (m > x)
    {
        // x < i <= m - x
        int i = (m - x) - m % x;
        ans += i / x - 1;

        // m - x < x <= m + x
        // x ^ y 的上界是变动的，这里是变动的区域，可能取得到，也可能取不到
        // m - x <= m ^ x <= m + x
        // 在这个区间里最多两个答案，验证一下能不能取到就可以了
        ans += (i + x ^ x) <= m;
        ans += (i + 2 * x ^ x) <= m;
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