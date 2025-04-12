#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 11
 * 121
 * 1331
 * 14641
 * ....
 * 通项公式为 a_n = 11^n
 * 
 * 哈哈，然后发现读错题了，要连续。
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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = s[i] - '0';
        ans = (ans + (i - 1) * i / 2 % mod * x % mod * ksm(10, n - i)) % mod;
    }

    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        int x = s[i] - '0';
        ans = (ans + x * cnt) % mod;
        cnt = (cnt + ksm(10, n - i) * (n - i + 1)) % mod;
    }

    cout << ans << '\n';

    return 0;
}