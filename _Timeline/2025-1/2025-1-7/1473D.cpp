#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 前后缀统计一下，拿掉中间这一段，用
 *      前缀的最大范围  与  当前的x + 后缀最大改变范围
 *  一比较，出 l 和 r 得到答案。
 */

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '+')
            a[i] = 1;
        else    
            a[i] = -1;
    }

    vector<pair<int, int>> pre(n + 1);
    int l = 0, r = 0, cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += a[i];
        sum[i] = cur;
        l = min(l, cur);
        r = max(r, cur);
        pre[i].first = l;
        pre[i].second = r;
    }

    l = 0, r = 0, cur = 0;
    vector<pair<int, int>> bac(n + 2);
    for (int i = n; i >= 1; i--)
    {
        // cur += a[i];
        l = min(bac[i + 1].first + a[i], 0LL);
        r = max(bac[i + 1].second + a[i], 0LL);
        bac[i].first = l;
        bac[i].second = r;
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int ll = min(pre[x - 1].first, sum[x - 1] + bac[y + 1].first);
        int rr = max(pre[x - 1].second, sum[x - 1] + bac[y + 1].second);
        cout << rr - ll + 1 << '\n';
    }
    


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