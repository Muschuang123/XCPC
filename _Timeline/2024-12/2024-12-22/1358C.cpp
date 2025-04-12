#include <bits/stdc++.h>
#define int long long
using namespace std;

int su(int n)
{
    return n * (n + 1) / 2;
}

void solve()
{
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;

    if (x == xx || y == yy)
    {
        cout << 1 << '\n';
        return;
    }

    int lex = xx - x;
    int ley = yy - y;

    if (lex > ley)
        swap(lex, ley);
    
    cout << 2 * su(lex - 1) + lex * (ley - lex + 1) + 1 << '\n';
    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}