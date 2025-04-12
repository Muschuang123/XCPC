#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 画出每个小球的 x-t 图像。
 * 求 最小的 t'，使得 [0, t'] 之间包含至少 k 个交点 
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> al, ar;
    for (int i = 1; i <= n; i++)
    {
        int x, v;
        cin >> x >> v;
        if (v == -1)
            al.push_back(x);
        else 
            ar.push_back(x);
    }

    sort(al.begin(), al.end());
    sort(ar.begin(), ar.end());
    
    auto check = [&](int t)
    {
        int res = 0;
        // 向右走的球，在 t 时间内，越过了多少 向左走的球。
        // 这里假设 向左走的球不动，所以 t 为实际的 2 倍。
        for (auto &i : ar)
        {
            res += upper_bound(al.begin(), al.end(), i + t) - 
                upper_bound(al.begin(), al.end(), i);
        }
        return res >= k;
    };

    int l = 0, r = 1e18;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }

    if (r == 1e18)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        cout << fixed << setprecision(6) << r / 2.0 << '\n';
    }

    return 0;
}