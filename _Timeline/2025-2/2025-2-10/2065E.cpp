#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (abs(n - m) > k || k > max(n, m))
    {
        cout << -1 << '\n';
        return;
    }

    if (n >= m)
    {
        while (n > 0 || m > 0)
        {
            if (n > 0)
            {
                for (int i = 1; i <= min(n, k); i++)
                {
                    cout << '0';
                }
                n -= k;
            }
            if (m > 0)
            {
                for (int i = 1; i <= min(m, k); i++)
                {
                    cout << '1';
                }
                m -= k;
            }
        }
        cout << '\n';
    }
    else
    {
        while (n > 0 || m > 0)
        {
            if (m > 0)
            {
                for (int i = 1; i <= min(m, k); i++)
                {
                    cout << '1';
                }
                m -= k;
            }
            if (n > 0)
            {
                for (int i = 1; i <= min(n, k); i++)
                {
                    cout << '0';
                }
                n -= k;
            }
        }
        cout << '\n';
    }
    
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