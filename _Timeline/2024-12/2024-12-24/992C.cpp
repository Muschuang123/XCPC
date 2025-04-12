#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int ksm(int a, int n)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int x, k;
    cin >> x >> k;

    if (x == 0)
    {
        cout << 0;
        return 0;
    }
    x %= mod;
    cout << ((2 * x - 1) * ksm(2, k) % mod + 1 + mod) % mod;


    return 0;
}