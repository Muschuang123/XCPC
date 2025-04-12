#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 糖。a[i] 写成 a[t] 了。调了一小时

void solve()
{
    i64 n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n % 2 == 0)
    {
        int res = 0;
        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            res ^= a[i];
        }
        a.push_back(res);
        n++;
    }

    if (l <= n)
    {
        cout << a[l] << '\n';
        return;
    }
    else if (l / 2 <= n)
    {
        int ans = 0;
        for (int i = 1; i <= l / 2; i++)
            ans ^= a[i];
        cout << ans << '\n';
        return;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum ^= a[i];

    int ans = 0;
    i64 t = l / 2;
    while (t > n)
    {
        ans ^= sum;
        if (t % 2)
            break;
        t /= 2;
        if (t <= n)
        {
            for (int i = 1; i <= t; i++)
                ans ^= a[i];
        }
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