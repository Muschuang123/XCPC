#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n + 1), v(k);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> v[i];
    // 最小是这个数。原因：先清空，然后 操作1、操作2 循环。
    int ans = (d - 1) / 2;
    for (int i = 0; i <= 2 * n && d - i - 1 >= 0; i++)
    {
        int res = 0;
        // 计算经过当前有几个数满足条件
        for (int j = 1; j <= n; j++)
        {
            res += (j - a[j] == 0);
        }
        // 计算当前答案（操作 2
        ans = max(ans, res + (d - i - 1) / 2);
        // （操作 1
        for (int j = 1; j <= v[i % k]; j++)
        {
            a[j]++;
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