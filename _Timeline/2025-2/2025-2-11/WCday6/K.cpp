#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (abs(x + x + 1 - y) % 4 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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