#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 没有 0 肯定行，有两个 0 肯定不行。
// 判断出 答案 在 n - cnt[0] 和 n - cnt[0] + 1 之间了，
// 只需验证后者是否成立：
// 即：在一个 0 出现之前（含），始终满足 min >= mex。

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    i64 ans = n - count(a.begin() + 1, a.end(), 0);

    vector<int> vis(n + 1);
    int mex = 0;
    vector<int> me(n + 2);
    for (int i = n; i >= 1; i--)
    {
        if (a[i] <= n)
        {
            vis[a[i]] = 1;
        }
        while (vis[mex] == 1)
            mex++;
        me[i] = mex;
    }

    int mn = 1e9 + 1;
    for (int i = 1; i <= n; i++)
    {
        if (mn < me[i])
        {
            break;
        }
        if (a[i] == 0)
        {
            ans++;
            break;
        }
        if (a[i] != 0)
        {
            mn = min(mn, a[i]);
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