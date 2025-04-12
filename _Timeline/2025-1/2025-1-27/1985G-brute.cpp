#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int p[11] = {1};
    for (int i = 1; i <= 10; i++)
        p[i] = p[i - 1] * 10; 

    int l, r, k;
    cin >> l >> r >> k;

    for (int i = p[l]; i < p[r]; i++)
    {
        // k * D(n)
        int r1 = 0;
        int t = i;
        while (t)
        {
            r1 += t % 10;
            t /= 10;
        }
        r1 *= k;

        int r2 = 0;
        t = i * k;
        while (t)
        {
            r2 += t % 10;
            t /= 10;
        }

        if (r1 == r2)
        {
            cout << i << '\n';
        }
    }

    return 0;
}