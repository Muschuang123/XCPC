#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    int d = abs(a - b);
    if (d == 0)
    {
        cout << 0 << '\n';
        return;
    }

    int r = 0;
    while (r * (r + 1) / 2 < d)
    {
        r++;
    }
    
    if ((r * (r + 1) / 2 - d) % 2 == 0)
    {
        cout << r << '\n';
    }
    else if (r % 2 == 0)
    {
        cout << r + 1 << '\n';
    }
    else
    {
        cout << r + 2 << '\n';
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