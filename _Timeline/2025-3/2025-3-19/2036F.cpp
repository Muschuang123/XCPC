#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 l, r, i, k;
    cin >> l >> r >> i >> k;
    i64 ans = 0;

    i64 cl = l, cr = r;
    if (cl & 1)
    {
        ans ^= cl;
        cl++;
    }
    if (cr & 1 ^ 1)
    {
        ans ^= cr;
        cr--;
    }
    if ((cr - cl + 1) % 4 == 2)
    {
        ans ^= 1;
    }

    i64 tl = (l >> i << i | k) < l ? (l >> i) + 1 : l >> i;
    i64 tr = (r >> i << i | k) > r ? (r >> i) - 1 : r >> i;

    if (tr >= tl)
    {
        if (tl & 1)
        {
            ans ^= tl << i | k;
            tl += 1;
        }
        if (tr & 1 ^ 1)
        {
            ans ^= tr << i | k;
            tr -= 1;
        }
        if ((tr - tl + 1) % 4 == 2)
        {
            ans ^= 1 << i;
        }
    }
    cout << ans << '\n';
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