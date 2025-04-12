#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * https://www.cnblogs.com/registergen/p/cf_round_737_solution.html
 * 分类讨论，用 “1的个数的奇偶” 和 “是否有0” 讨论，最后再 ^k（每一位）。
 * 其中：
 *      “1的个数的奇偶”对应了 ^ 。
 *      “是否有0” 对应了 & 。
 * 
 * 显然是要分 n 的奇偶情况分别处理的。
 */

const int mod = 1e9 + 7;

int ksm(int a, int n)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    
    if (n & 1)
    {
        // ==
        cout << ksm(ksm(2, n - 1) + 1, k) << '\n';
    }
    else
    {
        int ans = 0;
        // == but have 0 (every bits are not all 1)
        ans = (ans + ksm(ksm(2, n - 1) - 1, k)) % mod;
        // 2^0 ~ 2^(k - 1)
        for (int i = 0; i <= k - 1; i++)
        {
            // i + 1 ~ k - 1    have the even number of 1
            // i                all 1
            // 0 ~ i - 1        arbitrary
            ans = (ans + ksm(ksm(2, n - 1) - 1, k - i - 1) * ksm(2, i * n)) % mod;
        }
        cout << ans << '\n';
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