#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << r - l  + 1 << '\n';
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