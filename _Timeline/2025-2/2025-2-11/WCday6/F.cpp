#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 按照 a[i] + b[i] 从小到大排序。
 * 手里捏着一个 mx 代表答案，从前往后遍历。
 * 如果 mx >= a[i] ，说明 可以直接取 a[i] + b[i]。因为排序，这个一定最优。
 * 如果 mx < a[i]，说明对于 x < i，a[x] < a[i] 恒成立，（甚至 a[x] + b[x] < a[i]）。
 * 所以这个时候取 a[i - 1] + b[i - 1] 最优。本质上是先取 i，再取 i - 1。
 */

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second >> a[i].first;
        a[i].first += a[i].second;
    }
    sort(a.begin() + 1, a.end());
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mx >= a[i].second)
        {
            mx = max(mx, a[i].first);
        }
        else
        {
            mx = max(a[i].second, a[i - 1].first);
        }
    }

    cout << mx << '\n';
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