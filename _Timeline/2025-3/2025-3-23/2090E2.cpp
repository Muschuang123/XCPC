#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;
    vector<int> a(2 * n + 1), b(2 * n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (k == accumulate(a.begin() + 1, a.end(), 0LL))
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] - a[i];
        a[i + n] = a[i];
    }
    vector<i64> pre(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        pre[i] = a[i] + pre[i - 1];
    }

    // 贪心，用在 最少的 操作轮数 下，最少的 k 一定是最好的
    // 因为多出的 k 可以随意使用
    auto check = [&](int mid)
    {
        int p = 0;
        i64 sum = 0;
        vector<i64> cost(2 * n - mid + 1);
        deque<int> dq;
        for (int i = 2 * n; i >= 0; i--)
        {
            if (i <= 2 * n - mid)
            {
                while (dq.front() > i + mid)
                    dq.pop_front();
                // (i, i + mid] 的最大子段和是负的，就需要一点 k 来弥补
                // 这里相当于把 pre[i] 磨平，和 pre[dq.front()] 一样高 (子段和 = 0)
                // 这时 pre[i] == pre[dq.front()]
                // 后面如果再遇到 比 pre[dq.front()] 大的 设为 pre[x], (x < i)，再磨平
                // 这时 pre[x] == pre[i]
                // 以此类推保证 长度为 n 的每一段（长度为 m）都是平的，
                // 这样就能在 操作的轮数 就 <= 窗口大小了
                cost[i] = max(0LL, pre[i] - pre[dq.front()]);
                // 不需要磨的话，pre[i] > pre[dq.front()]
                // 这样 pre[i] 将会成为新的 pre[dq.front()]
            }
            while (dq.size() && pre[dq.back()] <= pre[i])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = 1; i <= 2 * n - mid; i++)
            cost[i] += cost[i - 1];
        i64 need = 1e18;
        // 只要能弥补出一个 长度为 n 的区间
        for (int i = 0; i + n <= 2 * n - mid; i++)
        {
            need = min(need, cost[i + n] - cost[i]);
        }
        return need <= k;
    };
    
    int l = 0, r = n; 
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }
    cout << r << '\n';
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