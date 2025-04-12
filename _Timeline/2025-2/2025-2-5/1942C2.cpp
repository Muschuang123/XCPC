#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 点数和最终构成的三角形数有直接联系。
 * 具体地：x 个点可以构成 x - 2 个三角形。
 * 特殊地：两个点中间空着一个点，可以多构造一个三角形。
 * 
 * 利用这个特殊点。我们发现：如
 *      果两个点中间空的点数是奇数，我们可以空一个点一个，最后多一个。
 * 所以先点奇数。
 * 又因为必须点完才能多一个，所以先点小的。
 * 注意 y 可能很大，所以点的话必须一下点完。
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
    multiset<pair<int, int>> ss;
    for (int i = 1; i <= x; i++)
    {
        if (a[i] - a[i - 1] - 1)
            ss.insert({a[i] - a[i - 1] - 1 & 1 ^ 1, a[i] - a[i - 1] - 1});
    }

    while (ss.size())
    {
        auto [tt, x] = *ss.begin();
        ss.erase(ss.begin());
        if (x == 0)
            continue;

        if (x == 1)
        {
            ans++;
            continue;
        }

        if (y == 0)
            break;
        
        int ch = min(x / 2, y);
        ans += ch * 2;
        x -= ch * 2;
        y -= ch;
        ss.insert({tt, x});
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