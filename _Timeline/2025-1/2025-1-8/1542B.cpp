#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 1)
    {
        cout << ((n - 1) % b == 0 ? "Yes" : "No") << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i *= a)
    {
        if ((n - i) % b == 0)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
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