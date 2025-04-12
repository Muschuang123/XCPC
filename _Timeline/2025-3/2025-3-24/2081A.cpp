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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    i64 ans = 0;
    i64 cur = 1;
    for (int i = 2; i <= n; i++)
    {
        cur = cur * inv2 % mod;
        if (s[i] == '1')
        {
            ans = (ans + cur) % mod;
        }
    }
    cout << (n - 1 + ans) % mod << '\n';
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