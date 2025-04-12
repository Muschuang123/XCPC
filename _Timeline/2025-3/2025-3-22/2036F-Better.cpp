#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 calc(i64 n)
{
    i64 ans = 0;
    for (int r = 0; r <= n % 4; r++)
    {
        ans ^= n - r;
    }
    return ans;
}

void solve()
{
    i64 l, r, i, k;
    cin >> l >> r >> i >> k;
    l--;

    i64 ans = calc(r) ^ calc(l);
    r = r - k >> i;
    l = l - k >> i;
    ans ^= (calc(r) << i) ^ (calc(l) << i);
    if (r - l & 1)
        ans ^= k;

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