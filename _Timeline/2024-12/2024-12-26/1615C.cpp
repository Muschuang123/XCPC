#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int sa1 = 0, dif1 = 0, sa0 = 0, dif0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i] && a[i] == '1') sa1++;
        if (a[i] == b[i] && a[i] == '0') sa0++;
        if (a[i] != b[i] && a[i] == '1') dif1++;
        if (a[i] != b[i] && a[i] == '0') dif0++;
    }
    int ans = 0x3f3f3f3f3f3f3f3f;
    if (sa1 == sa0 + 1)
        ans = min(ans, sa0 + sa1);
    if (dif1 == dif0)
        ans = min(ans, dif0 + dif1);
    if (ans == 0x3f3f3f3f3f3f3f3f)
        cout << -1 << '\n';
    else 
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