#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

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

    int n, q;
    cin >> n >> q;
    fenwick f(n + 1);
    // k 小于 cap[i]，i-th 怪物就会逃逸
    vector<int> cap(n + 1);
    int x;

    auto check = [&](int mid)
    {
        // true == 逃逸 
        return f.query(mid) >= 1LL * x * mid;
    };

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        // 二分一下怪物 逃逸的情况下 最大的 k
        int l = 0, r = n + 1;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                l = mid;
            else 
                r = mid;
        }

        cap[i] = l + 1;
        f.add(l + 1, 1);
    }

    while (q--)
    {
        int i, k;
        cin >> i >> k;
        cout << (k >= cap[i] ? "YES" : "NO") << '\n';
    }

    return 0;
}