#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 sum(i64 n)
{
    return n * (n + 1) / 2LL;
}

void solve()
{
    i64 n, x, y;
    cin >> n >> x >> y;
    i64 ans = 0;
    for (i64 i = min(n, y); i <= min(n, y); i++)
    {
        for (i64 j = 1; j <= min(n, x + y); j++)
        {
            if (n - j < i)
            {
                i64 dmg = x + n - j;
                i64 res = (dmg + 1) * (i - (n - j));
                res += sum(dmg) - sum(max(0LL, dmg - (n - i)));
                ans = max(ans, res);
            }
            else
            {
                i64 dmg = x + i;
                i64 res = sum(dmg) - sum(max(0LL, dmg - j));
                ans = max(ans, res);
            }
            
        }
    }
    cout << ans << '\n';
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