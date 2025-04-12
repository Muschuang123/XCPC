#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 一种不使用偏移量的 存负数下标数组的方法：正负分开存。

const int maxn = 1e6 + 6;
int l[maxn], r[maxn];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 0)  
            r[a[i]]++;
        else 
            l[-a[i]]++;
    }

    for (int i = 1; i <= 1e6; i++)
    {
        r[i] += r[i - 1];
        l[i] += l[i - 1];
    }

    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        if (i <= 1e6 && m - 2 * i <= 1e6)
        ans = max({ans, r[i] + l[max(0, m - 2 * i)], r[max(0, m - 2 * i)] + l[i]});
    }
    cout << ans << '\n';

    return 0;
}