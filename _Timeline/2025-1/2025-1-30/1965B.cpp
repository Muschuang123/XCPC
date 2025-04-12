#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int need = k - 1;

    for (int i = 1; i <= need; i *= 2)
    {
        a.push_back(i);
        need -= i;
    }
    if (need > 0)
    {
        a.push_back(need);
    }
    // 与前面的 k - 1 造出 : 除了 k 的倍数的所有数 和 k 的部分倍数
    for (int i = k + 1; i <= n; i *= 2)
    {
        a.push_back(i);
    }
    // 用 k + 2 弥补 一下 2 * (k + 1) - 1、4 * (k + 1) - 1、等构造不出来的缺陷
    // 构造的时候只需要把 k + 1 这个数 替换成 k + 2 就可以了
    a.push_back(k + 2);
    cout << a.size() << '\n';
    for (auto &v : a)
        cout << v << ' ';
    cout << '\n';
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