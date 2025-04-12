#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 小模拟，注意细节即可。
 */

void solve()
{
    int q;
    cin >> q;

    int l = 1, r = 1e18;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, n;
            cin >> a >> b >> n;
            int cl, cr;
            if (n == 1)
            {
                cl = max(l, 1LL);
                cr = min(r, a);
            }
            else
            {
                cl = max(l, a * (n - 1) - b * (n - 2) + 1);
                cr = min(r, a * n - b * (n - 1));
            }
            if (cl > cr)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << 1 << ' ';
                l = cl, r = cr;
            }
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int cl = max(1LL, l - b), cr = max(1LL, r - b);
            int resl = (cl + a - b - 1) / (a - b);
            int resr = (cr + a - b - 1) / (a - b);
            if (resl != resr)
            {
                cout << -1 << ' ';
            }
            else
            {
                cout << resl << ' ';
            }
        }
        cout << "";
    }
    cout << '\n';
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