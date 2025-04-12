#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    // 左  右  下  上
    cin >> a >> b >> c >> d;
    if (b - a >= d - c)
    {
        cout << b << ' ' << d << '\n';
        cout << b - 1 << ' ' << d << '\n';
        cout << a << ' ' << d - 1 << '\n';
    }
    else
    {
        cout << a << ' ' << c << '\n';
        cout << a << ' ' << c + 1 << '\n';
        cout << a + 1 << ' ' << d << '\n';
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