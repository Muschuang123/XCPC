#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());

    int cnt[maxn] = {0};

    int l = 0, r = 0;
    int sum = 0;
    int ans = 1e18;
    while (r < n)
    {
        while (r < n && sum < m)
        {
            r++;
            for (int i = 1; i * i <= a[r]; i++)
            {
                if (a[r] % i == 0)
                {
                    if (!cnt[i] && i <= m)
                        sum++;
                    cnt[i]++;

                    if (!cnt[a[r] / i] && a[r] / i <= m)
                        sum++;
                    cnt[a[r] / i]++;
                }
            }
        }
        while (l < r && sum >= m)
        {
            l++;
            ans = min(ans, a[r] - a[l]);
            for (int i = 1; i * i <= a[l]; i++)
            {
                if (a[l] % i == 0)
                {
                    cnt[i]--;
                    if (!cnt[i] && i <= m)
                        sum--;

                    cnt[a[l] / i]--;
                    if (!cnt[a[l] / i] && a[l] / i <= m)
                        sum--;
                }
            }
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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