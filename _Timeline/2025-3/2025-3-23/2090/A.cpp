#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 x, y, a;
    cin >> x >> y >> a;
    if (a % (x + y) < x)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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