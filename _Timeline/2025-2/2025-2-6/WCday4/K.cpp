#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    cout << max({x * a, y * b, z * c}) << '\n';
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