#include <bits/stdc++.h>
#define int long long
using namespace std;

// 为了凸显出这个超级方法，我直接压行。
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end(), greater<int>());
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    int p = 0;
    while (a[p] < a[n] / 2)
        p++;

    cout << (a[n] + 1) / 2 + p << '\n';

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