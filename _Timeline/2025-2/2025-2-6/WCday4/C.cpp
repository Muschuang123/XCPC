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

i64 n;
string s;
i64 ans = 0;

void solve()
{
    ans = 0;
    cin >> n;
    cin >> s;

    if (n == 1)
    {
        cout << (s[0] == '?' ? 2 : 1) << '\n';
        return;
    }

    i64 cnt = count(s.begin(), s.end(), '?');

    if (s.front() == '?' && s.back() == '?')
    {
        cout << (4 + (n - 2) * 2) * ksm(2, cnt - 2) % mod << '\n';
    }
    else if (s.front() == '?' || s.back() == '?')
    {
        cout << (2 + n - 2) * ksm(2, cnt - 1) % mod << '\n';
    }
    else
    {
        if (s.back() == s.front())
        {
            cout << (n - 2) * ksm(2, cnt) % mod << '\n';
        }
        else
        {
            cout << 2 * ksm(2, cnt) % mod << '\n';
        }
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