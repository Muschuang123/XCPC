#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end(), greater<int>());

    int res = n % k;
    int mul = n / k;
    for (int i = 1; i <= m; i++)
    {
        if (i <= res && a[i] > mul + 1)
        {
            cout << "NO\n";
            return;
        }
        if (i > res && a[i] > mul)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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