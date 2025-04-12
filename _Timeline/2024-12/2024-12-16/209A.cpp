#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int f1 = 0, f2 = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            f1 += f2;
            ans += f1;
        }
        else
        {
            f2 += f1;
            ans += f2;
        }
        f1 %= mod;
        f2 %= mod;
        ans %= mod;
    }
    cout << ans;

    return 0;
}