#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 检验是否输入的数两两乘积可以是 所有数的lcm（以下简称ans
 * 然后ans <= 1e12了
 * 查找ans的所有因子 i
 * 看看 i 和ans / i 是不是已经输入了（用所有因子数量和n比较
 * 没输入就-1
 * 两个方面吧，一方面确定输入的都是因子，另一方面确定输入全了
 */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans = lcm(ans, a[i]);
    }

    sort(a.begin() + 1, a.end());

    if (ans == a[n])
        ans *= a[1];

    for (int i = 1; i <= n; i++)
    {
        if (a[i] * a[n - i + 1] != ans)
        {
            cout << -1 << '\n';
            return;
        }
    }

    int cnt = 0;
    for (int i = 2; i * i <= ans; i++)
    {
        if (ans % i == 0)
            cnt += 2;
        if (i * i == ans)
            cnt--;
    }

    if (n != cnt)
    {
        cout << -1 << '\n';
        return;
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