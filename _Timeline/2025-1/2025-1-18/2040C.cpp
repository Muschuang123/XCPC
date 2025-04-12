#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<bool> a(n + 1);
    k--;
    if (k > (1LL << min(60LL, n - 1)) - 1)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = n - 1; i >= 1 && k; i--)
    {
        if (k & 1)
            a[i] = 1;
        k >>= 1;
    }

    int l = 1, r = n;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            ans[r] = i;
            r--;
        }
        else
        {
            ans[l] = i;
            l++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }

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