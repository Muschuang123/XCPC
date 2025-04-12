#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end());

    int d = 0;
    for (int i = n; i >= 2; i--)
    {
        if (a[i - 1] == a[i])
        {
            d = a[i];
            a[i - 1] = a[i] = 0;
            break;
        }
    }

    if (d == 0)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> v = a;
    a.clear();
    for (int i = 1; i <= n; i++)
    {
        if (v[i] != 0)
            a.push_back(v[i]);
    }

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] - a[i - 1] < 2 * d)
        {
            cout << a[i] << ' ' << a[i - 1] << ' ' << d << ' ' << d << '\n';
            return;
        }
    }

    cout << -1 << '\n';

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