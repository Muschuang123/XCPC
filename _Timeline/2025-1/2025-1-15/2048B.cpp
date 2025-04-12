#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int l = 1, r = n;
    for (int i = 1; i * k <= n; i++)
    {
        a[i * k] = l++;
        for (int j = 1; j < k; j++)
        {
            a[(i - 1) * k + j] = r--;
        }
    }

    int la = n - n % k;
    for (int j = la + 1; j <= n; j++)
        a[j] = r--;

    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
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