#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 点数和最终构成的三角形数有直接联系。
 * 具体地：x 个点可以构成 x - 2 个三角形。
 * 特殊地：两个点中间空着一个点，可以多构造一个三角形。
 */

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x + 1);
    for (int i = 1; i <= x; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    a[0] = a[x] - n;
    int ans = x - 2;
    for (int i = 1; i <= x; i++)
    {
        ans += a[i] - a[i - 1] == 2;
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