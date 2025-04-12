#include <bits/stdc++.h>
#define int long long
using namespace std;

// bool check(int need, int invest)
// {
//     return need * k > invest + need;
// }

void solve()
{
    int k, x, a;
    cin >> k >> x >> a;

    int invest = 0;
    for (int i = 1; i <= x + 1; i++)
    {
        if (a < invest)
        {
            cout << "No\n";
            return;
        }
        int l = 0, r = 1e9 + 7;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (mid * k > invest + mid)
                r = mid;
            else
                l = mid;
        }
        // cout << r << '\n';
        invest += r;
    }

    
    if (a < invest)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}