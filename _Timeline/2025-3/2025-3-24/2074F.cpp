#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 2^20 > 1e6

void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    i64 ans = 1LL * (r1 - l1) * (r2 - l2);
    for (int i = 0; i <= 20; i++)
    {
        int cur = 1 << i + 1;
        if (r1 - l1 >= cur && r2 - l2 >= cur)
        {
            i64 res = 1LL * (r1 / cur - (l1 + cur - 1) / cur) * 
                (r2 / cur - (l2 + cur - 1) / cur);
            ans -= res * 3;
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