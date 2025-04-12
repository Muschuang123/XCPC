#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 前两种方法都是啥b。。没看到 m <= 1e6 可以直接用前缀和优化吗。。
// 另外演示一下 #define 糕手的技巧。

int pre[(int)2e6 + 9];
#define pre(x) pre[x + (int)1e6]

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= n; i++)
    {
        pre(a[i])++;
    }

    for (int i = 1; i <= 2e6; i++)
    {
        pre[i] += pre[i - 1];
    }

    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        if (i <= 1e6 && m - 2 * i <= 1e6)
        ans = max({ans, pre(i) - pre(-(m - 2 * i) - 1), 
            pre(m - 2 * i) - pre(-i - 1)});
    }
    cout << ans << '\n';

    return 0;
}