#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 每一局结束后的rating一定是关于初始rating单调的。
 * 所以在每一局时二分一下：
 *      找到当前rating 第一个得分大于 L[i] 和 第一个小于 R[i] 对应的初始rating
 * 修改这 这个区间里的 分数。（使用树状数组的差分）
 */

struct fenwick
{
    int n;
    vector<int> t;

    fenwick(int _n = 0)
    {
        n = _n - 1;
        t.resize(n + 1);
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    void add(int index, int delta)
    {
        for (int i = index; i <= n; i += lowbit(i))
            t[i] += delta;
    }

    int query(int index)
    {
        int ans = 0;
        for (int i = index; i > 0; i -= lowbit(i))
            ans += t[i];
        return ans;
    }

    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

fenwick f(5e5 + 1);

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = 5e5 + 1;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (mid + f.query(mid) >= a[i].first)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        int resl = r;
        l = 0, r = 5e5 + 1;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (mid + f.query(mid) <= a[i].second)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        int resr = l;
        if (resr < resl)
            continue;
        f.add(resr + 1, -1);
        f.add(resl, 1);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << x + f.query(x) << '\n';
    }


    return 0;
}