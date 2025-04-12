// 树状数组
// 前缀和的单点修改与查询
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> s;

void add(int x, int y)
{
    while (x <= n)
    {
        s[x] += y;
        x += x & -x;
    }
}

int ask(int x)
{
    int ans = 0;
    while (x)
    {
        ans += s[x];
        x -= x & -x;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m;
    cin >> n >> m;
    s.resize(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i]);
    }

    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            add(x, y);
        }
        if (op == 2)
        {
            cout << ask(y) - ask(x - 1) << '\n';
        }
    }


    return 0;
}