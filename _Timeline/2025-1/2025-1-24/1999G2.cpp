#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l = 1, r = 999;
    while (l + 1 < r)
    {
        int d = (r - l + 2) / 3;
        int q1 = l + d, q2 = l + 2 * d;
        cout << "? " << q1 << ' ' << q2 << endl;
        int ans;
        cin >> ans;
        if (ans == q1 * q2)
        {
            l = q2;
        }
        else if (ans == q1 * (q2 + 1))
        {
            l = q1, r = q2;
        }
        else
        {
            r = q1;
        }
    }
    cout << "! " << r << endl;
}

signed main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}