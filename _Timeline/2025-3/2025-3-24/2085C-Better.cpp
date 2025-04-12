#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// thats meaning (x + k & y + k) == 0

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << -1 << '\n';
        return;
    }
    cout << (1LL << 40) - max(x, y) << '\n';
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