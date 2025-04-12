#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n;
    cin >> n;
    int ans = 10, dig = 0;
    int t = n;
    while (t)
    {
        dig++;
        t /= 10;
    }

    i64 cur = 0;
    for (int i = 1; i <= dig; i++)
    {
        cur = cur * 10 + 9;
        for (int j = 0; j <= 8; j++)
        {
            i64 now = n + cur * j;
            while (now)
            {
                if (now % 10 == 7)
                {
                    ans = min(ans, j);
                    goto LLL;
                }
                now /= 10;
            }
        }
    LLL:;
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