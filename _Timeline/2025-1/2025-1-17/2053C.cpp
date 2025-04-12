#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 有i段区间，每次求和，实际上就是在加 2^(i - 1) 倍的平均数。
 * 因为区间是对称的，而且如果是奇数的话，所有区间都是奇数。
 */

int n, k;
double mean;

int dfs(int l, int r, int s)
{
    if (r - l + 1 < k)
        return 0;

    int res = 0;
    if (r - l + 1 & 1)
    {
        int mid = l + r >> 1;
        res += mean * s + dfs(l, mid - 1, s << 1);
    }
    else
    {
        int mid = l + r >> 1;
        res += dfs(l, mid, s << 1);
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    mean = (n + 1) / 2.0;
    cout << dfs(1, n, 1) << '\n';

    // vector<int> a(4);
    // int cnt = 0;
    // int tmp = n;
    // while (n)
    // {
    //     a[cnt] = n & 1;
    //     n >>= 1;
    //     cnt++;
    // }
    // cout << tmp << "\t" << dfs(1, tmp) << '\t' << a[3] << a[2] << a[1] << a[0] << '\n';
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