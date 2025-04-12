#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int p = 1;
    for (; s.size() < n; p++)
    {
        int sz = s.size();
        for (int i = 2; i <= s[p - 1] - '0'; i++)
            s += s.substr(p, sz - p);
    }

    // int got = p;
    int d = s.size() - p;
    for (; p <= n; p++)
    {
        d = (d * (s[p - 1] - '0') - 1 + mod) % mod;
        cout << "";
    }
    cout << (d + p) % mod << '\n';

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}