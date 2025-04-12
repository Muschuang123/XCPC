#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 先状态压缩一遍把操作 j 次的最优结果列出来，
 *     * : 这里状态压缩是必要的，有后效性，不能贪
 * 算出差分值，代表多操作一次的收益是多少，差分一定是单减的。
 * 优先队列，取最大的前 k 个差分值。
 * 
 * O(nm2^m) 超时，预处理把 2^m 个操作都处理出来，变成O(n2^m)。
 * 
 * 数值范围分析：只有 ans 需要 i64 ，其他操作均在 i32 范围内。
 * 
 * 0x3f3f3f3f < 2^30 - 1 。。
 */

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    vector<int> f(1 << m, (1 << 30) - 1);
    for (int i = 0; i < (1 << m); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i & 1 << j)
                f[i] &= b[j + 1];
        }
    }

    vector<vector<int>> mn(n + 1, vector<int>(m + 1, (1 << 30) - 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (1 << m); j++)
        {
            mn[i][__builtin_popcount(j)] = min(mn[i][__builtin_popcount(j)], a[i] & f[j]);
        }
    }

    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mn[i][j - 1] - mn[i][j])
            {
                q.push(mn[i][j - 1] - mn[i][j]);
            }
        }
    }

    i64 ans = accumulate(a.begin() + 1, a.end(), 0LL);
    while (q.size() && k--)
    {
        ans -= q.top();
        q.pop();
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