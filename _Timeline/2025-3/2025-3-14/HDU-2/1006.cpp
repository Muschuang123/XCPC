#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 r, b, m;
    cin >> r >> b >> m;
    r = r + 2 * b + 4 * m;
    if ((r - 1) % 4 + 1 == 4)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
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