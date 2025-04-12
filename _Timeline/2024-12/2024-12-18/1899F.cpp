#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cout << i << ' ' << i + 1 << '\n';
    }

    int la = n - 1;
    while (q--)
    {
        int x;
        cin >> x;
        if (la == x)
            cout << "-1 -1 -1\n";
        else 
            cout << n << ' ' << la << ' ' << x << '\n';
        la = x;
    }
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