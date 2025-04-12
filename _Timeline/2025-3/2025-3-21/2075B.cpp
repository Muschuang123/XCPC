#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    i64 ans = 0;

    if (k == 1)
    {
        if (a[1] > a[n])
        {
            ans += a[1];
            sort(a.begin() + 2, a.end(), greater<>());
            for (int i = 3; i <= n; i++)
                a[i] += a[i - 1];
            ans += a[k + 1];
        }
        else
        {
            ans += a[n];
            sort(a.begin() + 1, a.end() - 1, greater<>());
            for (int i = 2; i <= n - 1; i++)
                a[i] += a[i - 1];
            ans += a[k];
        }
    }
    else
    {
        sort(a.begin() + 1, a.end(), greater<>());
        for (int i = 2; i <= n; i++)
        {
            a[i] += a[i - 1];
        }
        ans += a[k + 1];
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