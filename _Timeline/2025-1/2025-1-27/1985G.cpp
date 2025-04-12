#include <bits/stdc++.h>
#define int long long
using namespace std;

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
    int l, r, k;
    cin >> l >> r >> k;
    if (k >= 10)
    {
        cout << 0 << '\n';
        return;
    }
    int p[10] = {0, 10, 5, 4, 3, 2, 2, 2, 2, 2};
    cout << (ksm(p[k], r) - ksm(p[k], l) + 2 * mod) % mod << '\n';

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