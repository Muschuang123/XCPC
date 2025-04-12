#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    a.push_back(0);
    int acu = 1;
    int ans = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        if (a[i - 1] - a[i] == 1)
        {
            acu++;
        }
        else
        {
            if (acu % 2 == 0)
            {
                ans++;
                acu = 2;
            }
            else
            {
                acu = 2;
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}