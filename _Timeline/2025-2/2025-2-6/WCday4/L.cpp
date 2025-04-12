#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

i64 ksm(i64 a, i64 n)
{
    i64 ans = 1;
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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<i64>> a(n + 1, vector<i64>(32)), b(n + 1, vector<i64>(32));
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int d = 0;
        while (x)
        {
            a[i][d] = x & 1;
            d++;
            x >>= 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int d = 0;
        while (x)
        {
            b[i][d] = x & 1;
            d++;
            x >>= 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int d = 0; d < 32; d++)
        {
            b[i][d] += b[i - 1][d];
        }
    }

    vector<vector<i64>> c(n + 1, vector<i64>(32));
    for (int i = 1; i <= n; i++)
    {
        for (int d = 0; d < 32; d++)
        {
            c[i][d] += (1 - a[i][d]) * (b[n][d] - b[i - 1][d]);
            c[i][d] += a[i][d] * (n - i + 1 - (b[n][d] - b[i - 1][d]));
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int d = 0; d < 32; d++)
    //     {
    //         cout << c[i][d] << " \n"[d == 31];
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int d = 0; d < 32; d++)
        {
            a[i][d] += a[i - 1][d];
            c[i][d] = (c[i][d] + c[i - 1][d]) % mod;
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        i64 ans = 0;
        for (int d = 0; d < 32; d++)
        {
            // ans = (ans + (a[r][d] - a[l - 1][d]) * (len - (b[r][d] - b[l - 1][d])) % mod * (1LL << d)) % mod;
            // ans = (ans + (len - (a[r][d] - a[l - 1][d])) * (b[r][d] - b[l - 1][d]) % mod * (1LL << d)) % mod;
            ans = (ans + (c[r][d] - c[l - 1][d] + mod) % mod * (1LL << d)) % mod;
            ans = (ans - (a[r][d] - a[l - 1][d]) * (n - r - (b[n][d] - b[r][d])) % mod * (1LL << d) % mod + mod) % mod;
            ans = (ans - (len - (a[r][d] - a[l - 1][d])) * (b[n][d] - b[r][d]) % mod * (1LL << d) % mod + mod) % mod;
        }
        cout << ans << '\n';
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