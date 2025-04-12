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

i64 inv2 = ksm(2, mod - 2);

void solve()
{
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 b = (n - 2) * 2 + (m - 2) * 2;
    i64 a = n * m - k;
    i64 hz = 0;
    for (int i = 1; i <= k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        if ((x == 1 || x == n) && y != 1 && y != m)
        {
            b--;
            if (c == 1)
                hz++;
        }
        if (x != 1 && x != n && (y == 1 || y == m))
        {
            b--;
            if (c == 1)
                hz++;
        }
    }
    if (hz % 2 && b == 0)
    {
        cout << 0 << '\n';
        return;
    }
    if (b)
    {
        cout << ksm(2, a - b) * ksm(2, b) % mod * inv2 % mod << '\n';
    }
    else
    {
        cout << ksm(2, a) % mod << '\n';
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