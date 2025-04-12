#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 我是入

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    k--;
    if (n == 1)
    {
        cout << k + (k >= a[1]) << '\n';
        return;
    }

    i64 g = a[1];
    for (int i = 2; i <= n; i++)
    {
        g = __gcd(g, a[i]);
    } 
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1LL * (i - 1) * g;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= k)
            k++;
    }
    cout << k << '\n';
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