#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    
    int l = h[1] + 1, r = h[1] + 1;
    for (int i = 2; i <= n; i++)
    {
        // nl > ground && nl > l - k && nr < r + k && nr < ground + k

        int nl = max(l - k + 1, h[i] + 1);
        int nr = min(r + k - 1, h[i] + k);
        if (nr + k - 1 < l || nl > r + k - 1)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            l = nl;
            r = nr;
        }
    }
    if (l != h[n] + 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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