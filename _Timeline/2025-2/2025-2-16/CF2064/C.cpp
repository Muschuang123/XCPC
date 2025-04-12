#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1];
        if (a[i] > 0)
            pre[i] += a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1];
        if (a[i] < 0)
            suf[i] += a[i];
    }

    i64 ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, pre[i] - suf[i + 1]);
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