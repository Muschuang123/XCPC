#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    double a, d;
    int n;
    cin >> a >> d >> n;
    bool dx = 0, dy = 0;
    double x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        double s = fmod(d, 4 * a);
        while (s > 0)
        {
            if (!dx && !dy)
            {
                if (a - x > s)
                {
                    x += s;
                    s = 0;
                }
                else
                {
                    s -= a - x;
                    x = a;
                    dx = 1;
                }
            }
            if (dx && !dy)
            {
                if (a - y > s)
                {
                    y += s;
                    s = 0;
                }
                else
                {
                    s -= a - y;
                    y = a;
                    dy = 1;
                }
            }
            if (dx && dy)
            {
                if (x > s)
                {
                    x -= s;
                    s = 0;
                }
                else
                {
                    s -= x;
                    x = 0;
                    dx = 0;
                }
            }
            if (!dx && dy)
            {
                if (y > s)
                {
                    y -= s;
                    s = 0;
                }
                else
                {
                    s -= y;
                    y = 0;
                    dy = 0;
                }
            }
        }
        cout << fixed << setprecision(10) << x << ' ' << y << '\n';
    }

    return 0;
}