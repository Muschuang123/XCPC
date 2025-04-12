#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 不带特殊数，最大子段和，最小子段和。
 * 带上特殊数，从特殊数向两遍扩散，求出两边的最大和最小 前/后缀和，区间全取。
 * 最大子段和(ans)求法：
 *  知 缀和(cur)，最小缀和(mn)，则 for all cur: ans = max(ans, cur - mn);
 * 这里因为最大子段和的变动是连续的，所以每次都更新insert答案也可以。
 */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)
            pos = i;
    }

    set<int> ans;
    ans.insert(0);
    int mx = 0, mn = 0, cur = 0;
    for (int i = pos - 1; i >= 1; i--)
    {
        cur += a[i];
        mx = max(mx, cur);
        mn = min(mn, cur);
        if (a[i] == 1)
        {
            ans.insert(cur - mn);
        }
        else
        {
            ans.insert(cur - mx);
        }
        
    }
    for (int i = mn; i <= mx; i++)
        ans.insert(a[pos] + i);

    int tmx = mx, tmn = mn;
    mx = mn = cur = 0;
    for (int i = pos + 1; i <= n; i++)
    {
        cur += a[i];
        mx = max(mx, cur);
        mn = min(mn, cur);
        if (a[i] == 1)
        {
            ans.insert(cur - mn);
        }
        else
        {
            ans.insert(cur - mx);
        }
    }
    for (int i = mn + tmn; i <= mx + tmx; i++)
        ans.insert(a[pos] + i);

    cout << ans.size() << '\n';
    for (auto &v : ans)
        cout << v << ' ';
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