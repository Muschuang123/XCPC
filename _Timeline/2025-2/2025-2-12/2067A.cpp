#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 猜猜 A，很逆天的结论题，前一天晚上头疼，我直接怯战而逃了。
 */

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x + 1 >= y && (x + 1 - y) % 9 == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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