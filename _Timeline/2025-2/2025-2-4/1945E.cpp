#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 跑一遍二分，结束后：
 * a[l] == x 说明啥也不用改。
 * a[l] < x 说明最终会找到 l 这个地方，直接让 a[l] 和 x 交换，不影响二分
 *      因为交换前 x <= x 造成的 l 的移动，a[l] <= x 也能造成。
 * a[l] > x 说明 l 一直是 1，没动过。为什么呢？
 *      因为如果 l 要动，那么动完之后一定 a[l] <= x，要不然 l 不会动的。
 *      所以其实 r 一路靠过来了，因为 a[m] > x 始终成立。
 *      这也说明了路上没有 x ，直接交换 a[l] 和 x。
 */

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    int ind = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == x)
            ind = i;
    }

    int l = 1, r = n + 1;
    while (r - l != 1)
    {
        int m = (l + r) / 2;
        if (a[m] <= x)
            l = m;
        else 
            r = m;
    }

    if (a[l] == x)
    {
        cout << "0\n";
    }
    else
    {
        cout << "1\n" << ind << ' ' << l << '\n';
    }
    
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