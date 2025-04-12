#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // clock_t st, en;

    i64 n;
    cin >> n;

    // st = clock();
    i64 x = pow(n, 1.0 / 3);
    i64 y = pow(x * x * x - n, 1.0 / 3) - 1;
    x = max((i64)1, x);
    y = max((i64)1, y);
    while (1)
    {
        i64 kx = x * x * x, ky = y * y * y;
        if (kx - ky == n)
        {
            cout << x << ' ' << y << '\n';
            return 0;
        }
        else if (kx - ky > n)
        {
            if (x - 1 > y)
                y++;
            else 
                break;
        }
        else if (kx - ky < n)
        {
            x++;
        }
    }
    cout << -1 << '\n';

    return 0;
}