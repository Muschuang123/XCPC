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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    priority_queue<pair<int, int>> q;
    set<int> ss;
    fenwick f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        q.push({a[i], i});
        ss.insert(i);
        f.add(i, 1);
    }
    i64 ans = 0;
    while (q.size())
    {
        auto [d, i] = q.top();
        q.pop();
        if (f.query(i - 1, n) >= k + 1)
        {
            int j = 1;
            if (!ss.count(i))
                j--;
            else 
            {
                ss.erase(i);
                f.add(i, -1);
            }
            for (; j <= k; j++)
            {
                auto it = ss.upper_bound(i);
                f.add(*it, -1);
                ss.erase(it);
            }
            ans += d;
        }
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