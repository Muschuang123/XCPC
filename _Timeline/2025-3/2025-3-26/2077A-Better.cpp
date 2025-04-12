#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 原式可以转化为 
// a[1] + a[3] + ... + a[2 * n + 1] = a[2] + a[4] + ... + a[2 * n]
// 左边多一项。
// 我们把小的数 小的数放到等式右边，大的数放到左边，右边空出一个位置
// 不难想到，空出的这个位置需要一个很大的数，才能平衡
// 因为左边大数可以一对一减去右边小数，何况还空着一个大数
// 这样就可以满足题意，a[i] 互不重合

void solve()
{
    int n;
    cin >> n;
    vector<int> b(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin() + 1, b.end(), greater<>());
    vector<i64> a(2 * n + 2);
    for (int i = 1; i <= n + 1; i++)
    {
        a[2 * i - 1] = b[i];
        a[2] += b[i];
    }
    for (int i = n + 2; i <= 2 * n; i++)
    {
        a[2 * (i - n)] = b[i];
        a[2] -= b[i];
    }
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        cout << a[i] << " \n"[i == 2 * n + 1];
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