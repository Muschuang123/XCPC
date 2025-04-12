#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// Alice 第一次 染 自己脚下的，Bob 染 2x，Alice 染 -2x...
// 0, 2x, -2x, 4x, -4x, 6x.... 
// 所以 n 是奇数的情况肯定是可以染成的。因为 ±x 点都是奇偶错开的。
// 另一种情况是 奇偶相交，但是 在 x 的对面（x + n / 2）相交，
// 这意味着 存在一个 i (i = 0, 2, 4, 6...)，使得  -i*x + n == (i+2)*x == x + n / 2
// 前半部分化简得 (i+1) * 2x = n 这条不难满足，n是偶数就行，
// 后半部分化简得 (i+1) == n / 2 这需要 n / 2 是奇数。

void solve()
{
    int n, x;
    cin >> n >> x;
    int g = __gcd(n, 2 * x);
    if (g == 1 || g == 2 && n / 2 % 2)
        cout << "Yes\n";
    else 
        cout << "No\n";
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