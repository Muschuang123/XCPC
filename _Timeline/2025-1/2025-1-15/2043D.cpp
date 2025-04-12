#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 因为 gcd(A, B) = G, 所以存在 a 和 b, 使得 A = a * G, B = b * G
 * 且 gcd(a, b) = 1。题目转化为在 [(l + G - 1) / G, r / G] 中 找互质的 a 和 b
 * 背结论，1e18内两个质数只差最大不超过1500，两个不相等的质数一定互质。
 * 为了保证找到的 a 和 b 差值最大，我们外层循环枚举差值，内层循环移动 a 和 b。
 * 从 a 最小，即 (l + G - 1) / G 开始移动，保证了 A 最小。
 * 
 * 数学题，多用一些变量，让思路更清晰。
 */

void solve()
{
    int l, r, G;
    cin >> l >> r >> G;
    int L = (l + G - 1) / G;
    int R = r / G;
    int len = R - L;
    if (len < 0)
    {
        cout << "-1 -1\n";
        return;
    }

    for (int i = len; i >= 0; i--)
    {
        for (int j = L; j + i <= R; j++)
        {
            int a = j, b = j + i;
            if (__gcd(a, b) == 1)
            {
                cout << a * G << ' ' << b * G << '\n';
                return;
            }
        }
    }

    cout << "-1 -1\n";
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