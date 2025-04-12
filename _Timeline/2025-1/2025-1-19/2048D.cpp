#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * lower_bound找出多少人能过这个题。
 * 把自己过不了的、最简单的题掐掉。
 * 剩下的题先挑自己能过的，过不了的再挑最难的。
 * 调和级数 + lower_bound预处理 + 排序
 * 时间复杂度没问题。
 */

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<int> sa = a;
    sort(sa.begin() + 1, sa.end());

    int rk = sa.end() - upper_bound(sa.begin() + 1, sa.end(), a[1]) + 1;

    // 多少人能过这个题
    vector<int> c(m + 1);
    for (int i = 1; i <= m; i++)
    {
        c[i] = sa.end() - lower_bound(sa.begin() + 1, sa.end(), b[i]);
    }
    
    sort(c.begin() + 1, c.end());

    // 从这个题以后的都能做出来（不包含）
    int ind = --lower_bound(c.begin() + 1, c.end(), rk) - c.begin();
    for (int i = 1; i <= m; i++)
    {
        int sum = (m - ind) / i;
        int cnt = (m - ind) / i;
        int res = (m - ind) % i; 


        for (int j = i - res; j <= ind; j += i)
        {
            sum += c[j] + 1;
            cnt++;
        }
        // cout << sum + m / i - cnt << ' ' << flsuh;
        cout << sum + m / i - cnt << ' ';
        cout << "";
    }
    cout << '\n';
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