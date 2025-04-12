#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * https://ac.nowcoder.com/discuss/1453293
 * 
 * 按照商相等分块。
 * 块内余数成等差数列，只有首项是不确定的，公差是商。
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    // l, r, 商q
    vector<array<int, 3>> a;
    for (int l = 1; l <= n; l++)
    {
        int q = n / l;
        int r = n / q;
        a.push_back({l, r, q});
        l = r;
    }

    // 计算严格大于 mid 的余数个数
    auto check = [&](int mid)
    {
        int res = 0;
        for (auto [l, r, q] : a)
        {
            // 块中的余数最大值
            int mx = n % l;
            if (mid >= mx)
                continue;
            // mid 与 mx 之间的差距
            res += (mx - mid + q - 1) / q;
        }
        return res;
    };
    
    // 二分余数大小 [l, r)
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid) >= k)
            l = mid;
        else 
            r = mid;
    }

    int dec = (check(l) - k) * (l + 1);

    int ans = 0;
    for (auto [z, r, q] : a)
    {
        // 块中的余数最大值
        int mx = n % z;
        if (l >= mx)
            continue;
        // 项数
        int num = (mx - l + q - 1) / q;
        int fir = mx - (num - 1) * q;
        ans += (fir + mx) * num / 2;
        cout << "";
    }

    cout << ans - dec;

    return 0;
}