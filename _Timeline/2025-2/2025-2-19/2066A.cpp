#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 读错题了。没看到是有向图。。
// 如果 不是排列，那么如果是方案 A 的话必定有一个点没有出边，
// 带着这个点查询，看看返回是不是 0。方案 B 是不会出现 0 的回答的。
// 否则就询问 1 的 index 和 n 的 index。
// 回答 > n - 1 说明肯定是 方案 B，
// 回答 < n - 1 说明肯定是 方案 A。
// 回答 == n - 1 ，如果是方案 A 的话，那么这个图的 n - 1 条边构成了一条链。
// 因为是有向图，这个时候我们反过来询问一下，看看是不是 0 或 1。
// 如果是 1 ，说明整个图就是一个环。
// 1 不可能是 方案 B ，因为方案 B 必须满足 回答 > n - 1 >= 2 > 1。

vector<int> g[200005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 0)
        {
            cout << "? " << i << ' ' << (i == 1 ? 2 : 1) << endl;
            int x;
            cin >> x;
            if (x == 0)
            {
                cout << "! A" << endl;
            }
            else
            {
                cout << "! B" << endl;
            }
            return;
        }
    }

    cout << "? " << g[1][0] << ' ' << g[n][0] << endl;
    int x;
    cin >> x;
    if (x > n - 1)
    {
        cout << "! B" << endl;
    }
    else if (x < n - 1)
    {
        cout << "! A" << endl;
    }
    else
    {
        cout << "? " << g[n][0] << ' ' << g[1][0] << endl;
        cin >> x;
        if (x == 0 || x == 1)
        {
            cout << "! A" << endl;
        }
        else
        {
            cout << "! B" << endl;
        }
    }
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}