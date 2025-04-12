#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << '\n';
    }
    else
    {
        for (i64 i = 4; i <= 2 * n; i <<= 1)
        {
            if (i == (i & -i))
            {
                n++;
            }
        }
        cout << 2 * n << '\n';
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