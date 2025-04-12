#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, d, h;
    cin >> n >> d >> h;
    if (d >= n || 2 * h < d || d == 1 && n > 2)
    {
        cout << -1;
        return 0;
    }

    int p = 2;
    for (int i = 1; i <= h; i++)
    {
        cout << p - 1 << ' ' << p << '\n';
        p++;
    }

    
    if (h == d)
    {
        if (p <= n)
        {
            cout << "2 " << p << '\n';
            p++;
        }
        for (int i = 1; i <= d - h - 1; i++)
        {
            cout << p - 1 << ' ' << p << '\n';
            p++;
        }
        while (p <= n)
        {
            cout << "2 " << p << '\n';
            p++;
        }
    }
    else
    {
        if (p <= n)
        {
            cout << "1 " << p << '\n';
            p++;
        }
        for (int i = 1; i <= d - h - 1; i++)
        {
            cout << p - 1 << ' ' << p << '\n';
            p++;
        }
        while (p <= n)
        {
            cout << "1 " << p << '\n';
            p++;
        }
    }

    return 0;
}