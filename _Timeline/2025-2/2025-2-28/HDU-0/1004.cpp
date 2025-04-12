#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 ans = 0;

void solve()
{
    i64 n;
    cin >> n;
    ans ^= n - __lg(n) + (n == (n & -n) && n != 1);
    // cout << n - __lg(n) + (n == (n & -n) && n != 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    cout << ans << '\n';
    return 0;
}