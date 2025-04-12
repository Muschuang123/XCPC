#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 价格必定是 a[i] 或 b[i]。否则 +1 不影响结果
 * 枚举所有 a[i] 和 b[i]。判断买的人数和差评的人数。
 * 如果差评的人数 <= k，那更新答案。
 */

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int buy = b.end() - lower_bound(b.begin() + 1, b.end(), a[i]);
        int good =  a.end() - lower_bound(a.begin() + 1, a.end(), a[i]);
        if (buy - good <= k)
        {
            ans = max(ans, buy * a[i]);
        }
        
        buy = b.end() - lower_bound(b.begin() + 1, b.end(), b[i]);
        good =  a.end() - lower_bound(a.begin() + 1, a.end(), b[i]);
        if (buy - good <= k)
        {
            ans = max(ans, buy * b[i]);
        }
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