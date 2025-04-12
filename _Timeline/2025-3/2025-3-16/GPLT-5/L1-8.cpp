#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ca = a, cb = b;
    int ra = 0, rb = 0;
    while (a)
    {
        ra += a % 10;
        a /= 10;
    }
    while (b)
    {
        rb += b % 10;
        b /= 10;
    }

    if (ca % rb == 0 && cb % ra == 0 || ca % rb != 0 && cb % ra != 0)
    {
        cout << (ca > cb ? "A" : "B") << '\n';
    }
    else if (ca % rb == 0)
    {
        cout << "A\n";
    }
    else 
    {
        cout << "B\n";
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