#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    multiset<int> wa;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (wa.size() < m && a[i] > 0)
        {
            wa.insert(a[i]);
            sum += a[i];
        }
        else if (wa.size() == m && a[i] > *wa.begin())
        {
            sum -= *wa.begin();
            wa.erase(wa.begin());
            wa.insert(a[i]);
            sum += a[i];
        }
        
        ans = max(ans, sum - d * i);
    }
    cout << ans << '\n';
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