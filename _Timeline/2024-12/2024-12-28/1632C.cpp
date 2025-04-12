#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    int ans = b - a;
    for (int i = a; i <= b; i++)
    {
        ans = min(ans, (abs(b - (i | b)) + i - a) + 1);
    }
    for (int i = b; i <= b * 2; i++)
    {
        ans = min(ans, (abs(i - (a | i)) + i - b) + 1);
    }
    cout << ans << '\n';

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