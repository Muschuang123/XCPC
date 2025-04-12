#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    步子越大，步数越少。

    枚举步长len，因为步长是连续增加，所以 大步需要的步数 <= 小步需要的步数 

    答案是 min{ len - 1 + (a + len - 1) / len + (b + len - 1) / len }.
    "len - 1": 增加步长需要的行动数
    "(a + len - 1) / len": 移动 a 距离需要的最少步数（向上取整）
    "(b + len - 1) / len": 移动 b 距离需要的最少步数（向上取整）
*/

void solve()
{
    int x, y;
    cin >> x >> y;

    int ans = 1e18;
    for (int i = 1; i <= 1e5; i++)
    {
        ans = min(ans, (y + i - 1) / i + (x + i - 1) / i + i - 1);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}