#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 1000; i++)
    {
        for (int k = 1; k <= i - 2; k++)
        {
            if (k * 180 % i == 0 && k * 180 / i == n)
            {
                cout << i << '\n';
                return;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}