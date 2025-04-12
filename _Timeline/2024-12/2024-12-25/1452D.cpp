#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

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

    int n;
    cin >> n;
    int bas = ksm(ksm(2, n), mod - 2);
    vector<int> a(n + 2);
    a[1] = 1;
    int ji = 1, ou = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            a[i] += ji;
            ou += a[i];
        }
        else
        {
            a[i] += ou;
            ji += a[i];
        }
        ji %= mod;
        ou %= mod;
        a[i] %= mod;
    }
    cout << (a[n] * bas + mod) % mod;

    return 0;
}