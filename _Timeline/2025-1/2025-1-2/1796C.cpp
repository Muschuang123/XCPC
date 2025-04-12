#include <bits/stdc++.h>
// #define int long long
using namespace std;

/*
    the maximuming set way is lets set include [l, l * 2, l * 2 * 2, .....]
        then we can calculate the answer 1.
        lets take *2 for mx times. 
    
    for every answer which is suitable [i, i * 2, ....] can be the maximum set, 
    we can replace one 2 to 3. NOTICE just only once 2, and can't 2 -> 4.
        because we should hold the maximum. 
    
    just let r / 2^(mx - 1) / 3 and find the max number can do this.
    and use r / 2^mx find answer without replace behavior, plus them.
*/

const int mod = 998244353;

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
    int l, r;
    cin >> l >> r;

    int mx = 0;
    for (int i = l << 1; i <= r; i <<= 1)
    {
        mx++;
    }

    int ans = 0;

    int g = 0;
    if (mx >= 1)
    {
        g = r / (1 << mx - 1) / 3 - l + 1;
        ans = (ans + max(0, g) % mod * mx) % mod;
    }
    ans = (ans + (r / (1 << mx) - l + 1)) % mod;

    // for (int i = l; (i << mx) <= r; i++)
    // {
    //     ans++;
    //     if ((i << mx - 1) * 3 <= r)
    //         ans += mx;
    //     ans %= mod;
    // }

    cout << mx + 1 << ' ' << ans << '\n';
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