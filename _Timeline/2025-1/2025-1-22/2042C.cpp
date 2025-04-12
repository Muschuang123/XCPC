#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 0 --> -1
 * 1 --> 1
 * 做出后缀和。
 * 除了全体和，剩下都可以增加一次权重。（对应分组行为
 * 肯定是优先增加最大的。
 * 二分看看最少增加几次。
 * 
 * 为了保证保证二分单调，后缀和为负的就不要增加了。
 */

int n, k;
vector<int> a;

bool check(int d)
{
    d--;
    int cnt = 0;
    for (int i = 2; d && i <= n; i++, d--)
    {
        cnt += a[i];
    }
    return cnt >= k;
}

void solve()
{
    cin >> n >> k;
    a.clear();
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = x == '1' ? 1 : -1;
    }

    for (int i = n - 1; i >= 1; i--)
        a[i] += a[i + 1];

    sort(a.begin() + 2, a.end(), greater<>());

    int sz = n;
    for (int i = 2; i < n; i++)
    {
        if (a[i] > 0 && a[i + 1] <= 0)
        {
            sz = i;
            break;
        }
    }

    int l = 0, r = sz + 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }
    cout << (r == sz + 1 ? -1 : r) << '\n';

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