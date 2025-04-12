#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l = 1, r = 999;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        cout << "? " << mid << ' ' << mid << endl;
        int ans;
        cin >> ans;
        if (ans == mid * mid)
            l = mid;
        else 
            r = mid;
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