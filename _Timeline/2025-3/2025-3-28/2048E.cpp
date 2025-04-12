// https://www.luogu.com.cn/article/zg0hqs8c
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 一共有 2 * n + m 个点，最多画出 (2 * n + m - 1) * n 条边
// (2 * n + m - 1) * n >= 2 * n * m
// 2 * n - 1 >= m
// 构造极端情况
// 直接想就是 每个种颜色把他们都连起来 M 型
// 左右横跳，然后左右交错...
// l1-r1-l2-r2-l3-r3-l4-...-r(m)-l(2n)
// l3-r1-l4-r2-l5-r3-l6-...-r(m)-l2
// ...
// l(2n-1)-r1-l(2n)-r2-l1-....-r(m)-l(2n-2)
// 第一种颜色是 (1, 1), (2, 1), (2, 2), (3, 2)...
// 第二种颜色是 (3, 1), (4, 1), (4, 2), (5, 2)...
// 容易发现是蛇形。
// 1 4 4 3 3 2 2
// 1 1 4 4 3 3 2
// 2 1 1 4 4 3 3
// 2 2 1 1 4 4 3
// 3 2 2 1 1 4 4
// 3 3 2 2 1 1 4
// 4 3 3 2 2 1 1
// 4 4 3 3 2 2 1

void solve()
{
    int n, m;
    cin >> n >> m;
    if (2 * n - 1 < m)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
    }
    vector<vector<int>> a(2 * n + 1, vector<int>(m + 1));
    for (int i = 1; i <= 2 * n; i++)
    {
        a[i][1] = (i + 1) / 2;
    }
    for (int j = 2; j <= m; j++)
    {
        for (int i = 1; i <= 2 * n; i++)
        {
            a[i][j] = a[(i - 2 + 2 * n) % (2 * n) + 1][j - 1];
        }
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " \n"[j == m];
        }
    }

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