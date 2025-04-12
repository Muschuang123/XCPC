#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 插空，越后面的人肯定越说了算。倒着做。
 * 建一个 fenwick ，1 表示 这里没人。
 * 从后往前 挨个 插空，插第 a[i] 个空 设置为 b[i]。
 * 这样 a[i] 最终排在 b[i]，但是答案问的是最终的排列。
 * 那么就输出 a[b[i]]。
 * 
 * 有的博客说可以 O(nlogn) 做，我看了半天没看懂。
 * 最终用 fenwick + binary search 实现了一个 O(nlog^2n) 的做法
 */

struct fenwick
{
    int n;
    vector<i64> t;

    fenwick(int _n = 0)
    {
        n = _n - 1;
        t.resize(n + 1);
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    void add(int index, i64 delta)
    {
        for (int i = index; i <= n; i += lowbit(i))
            t[i] += delta;
    }

    i64 query(int index)
    {
        i64 ans = 0;
        for (int i = index; i > 0; i -= lowbit(i))
            ans += t[i];
        return ans;
    }

    i64 query(int l, int r)
    {
        return query(r) - query(l);
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    fenwick f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        f.add(i, 1);
    }

    vector<int> ans(n + 1);
    for (int i = n; i >= 1; i--)
    {
        int l = 0, r = n;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (f.query(mid) >= a[i])
                r = mid;
            else 
                l = mid;
        }
        f.add(r, -1);
        ans[r] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}