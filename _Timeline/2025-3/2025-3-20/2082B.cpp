#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int x, n, m;
    cin >> x >> n >> m;
    n = min(n, 40);
    m = min(m, 40);
    int tx = x, tn = n, tm = m;

    while (tn || tm)
    {
        if (!tx)
            break;
        if (tm)
        {
            tx++;
            tx /= 2;
            tm--;
        }
        else
        {
            tx /= 2;
            tn--;
        }
    }
    cout << tx << ' ';
    
    tx = x, tn = n, tm = m;
    while (tn || tm)
    {
        if (!tx)
            break;
        if (tn)
        {
            tx /= 2;
            tn--;
        }
        else
        {
            tx++;
            tx /= 2;
            tm--;
        }
    }
    cout << tx << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}