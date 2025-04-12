#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                int ind = lower_bound(a.begin() + i + 1, a.end(), a[i] ^ j) - a.begin();
                if (ind <= n && a[ind] == (a[i] ^ j) && __gcd(a[ind], a[i]) == j)
                {
                    ans += upper_bound(a.begin() + i + 1, a.end(), a[i] ^ j) - a.begin() - ind;
                    // cout << a[i] << ' ' << a[ind] << '\n';
                }

                int nj = a[i] / j;
                if (j == nj)
                    continue;
                
                ind = lower_bound(a.begin() + i + 1, a.end(), a[i] ^ nj) - a.begin();
                if (ind <= n && a[ind] == (a[i] ^ nj) && __gcd(a[ind], a[i]) == nj)
                {
                    ans += upper_bound(a.begin() + i + 1, a.end(), a[i] ^ nj) - a.begin() - ind;
                    // cout << a[i] << ' ' << a[ind] << '\n';
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}