#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const i64 mod = 1e9 + 7;

void solve()
{
    i64 n;
    cin >> n;
    i64 m = n / 2;
    cout << m * (m + 1) % mod << '\n';
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