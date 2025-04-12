#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> res(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > 1 && a[i] == 1)
        {
            cout << -1 << '\n';
            return;
        }

        res[i] += res[i - 1];
        if (a[i - 1] == 1)
        {
            res[i] = 0;
            continue;
        }
        while (a[i] > a[i - 1])
        {
            a[i - 1] *= a[i - 1];
            res[i]--;
        }
        int t = a[i];
        while (a[i - 1] > t)
        {
            t *= t;
            res[i]++;
        }
        res[i] = max(0LL, res[i]);
    }

    cout << accumulate(res.begin() + 1, res.end(), 0LL) << '\n';

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