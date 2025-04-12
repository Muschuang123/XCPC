#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ok = 1;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ok = 0;
        mx = max(mx, a[i]);
    }
    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }

    while (1)
    {
        mx++;
        int win = 1;
        for (int i = 2; i * i <= mx; i++)
        {
            if (mx % i == 0)
            {
                win = 0;
                break;
            }
        }
        if (win)
        {
            cout << mx << '\n';
            return;
        }
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