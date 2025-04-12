#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    答案具有二段性（存在正方形满足... && 最大边长），二分答案，枚举边长。
    求谁最值，谁就单调，因为超过这个数必定不行。

    "bool check()" 检验是否存在 边长为 len 的正方形。
    把低于 len 高度的建筑标位 1，枚举正方形，二维前缀和，算一算正方形内如果没有 1 就存在。

    肯定是更小会满足答案，所以让 l = mid。
*/

int n, m;
vector<vector<int>> a;

bool check(int len)
{
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] = a[i][j] < len;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 0; i <= n - len; i++)
    {
        for (int j = 0; j <= m - len; j++)
        {
            if (b[i + len][j + len] - b[i][j + len] - b[i + len][j] + b[i][j] == 0)
                return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    a.clear();
    a.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int l = 1, r = n + 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << '\n';
        
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}