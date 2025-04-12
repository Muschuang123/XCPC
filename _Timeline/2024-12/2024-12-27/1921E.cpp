#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, xa, ya, xb, yb;
    // guaranteed that either xa≠xb or ya≠yb.
    cin >> n >> m >> xa >> ya >> xb >> yb;

    int x = abs(xb - xa);
    int y = abs(yb - ya);
    int move = x / 2;

    if (xb < xa || y > x)
    {
        cout << "Draw\n";
        // cout << flush;
        return;
    }
    
    if (x % 2 == 1)
    {
        if (ya == yb)
        {
            cout << "Alice\n";
            return;
        }
        else if (ya < yb)
        {
            int xn = xb - move;
            int yn = min(m, yb + move);
            if (abs(xa - xn) < abs(ya - yn))
            {
                cout << "Draw\n";
            }
            else
            {
                cout << "Alice\n";
            }
        }
        else
        {
            int xn = xb - move;
            int yn = max(1LL, yb - move);
            if (abs(xa - xn) < abs(ya - yn))
            {
                cout << "Draw\n";
            }
            else
            {
                cout << "Alice\n";
            }
        }
    }
    else
    {
        if (ya == yb)
        {
            cout << "Bob\n";
        }
        else if (ya > yb)
        {
            int xn = xa + move;
            int yn = min(m, ya + move);
            if (abs(xb - xn) < abs(yb - yn))
            {
                cout << "Draw\n";
            }
            else
            {
                cout << "Bob\n";
            }
        }
        else
        {
            int xn = xa + move;
            int yn = max(1LL, ya - move);
            if (abs(xb - xn) < abs(yb - yn))
            {
                cout << "Draw\n";
            }
            else
            {
                cout << "Bob\n";
            }
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