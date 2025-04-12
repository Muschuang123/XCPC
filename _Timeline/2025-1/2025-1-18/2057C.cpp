#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 对于每一位，a b c中一个或者两个有，就能保证最大。
 * 如果l和r覆盖的区间这一位没有发生变动，那就没法调，
 * 只能是三个都是1 或者三个都是0
 * 如果发生变动了，则区间内必定有进位。
 * 一个数是进位之后：...100000
 * 一个数是进位之前：...011111
 * 另一个数随便取，因为取哪都不影响结果了。
 * 当然是取两侧最近的一个数更好，看看能取哪个。
 */

void solve()
{
    int l, r;
    cin >> l >> r;
    int tl = l, tr = r;
    int ans = 0;
    while (__lg(l) == __lg(r))
    {
        int d = 1 << __lg(r);
        ans += d;
        l -= d;
        r -= d;
    }
    r = 1 << __lg(r);
    l = r - 1;
    if (tr >= ans + r + 1)
    {
        cout << ans + l << ' ' << ans + r << ' ' << ans + r + 1 << '\n';
    }
    else
    {
        cout << ans + l - 1 << ' ' << ans + l << ' ' << ans + r << '\n';
    }
    

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