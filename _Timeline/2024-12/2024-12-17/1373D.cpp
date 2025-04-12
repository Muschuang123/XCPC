#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            res += a[i];
    }

    int sum = 0;
    vector<int> dis(n);
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
            dis[i] = a[i] - a[i - 1];
        else 
            dis[i] = a[i - 1] - a[i];
    }

    for (int i = 2; i < n; i++)
    {
        dis[i] += dis[i - 2];
    }

    vector<int> mn(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i >= 2)
            mn[i] = min(mn[i - 2], dis[i]);
        else 
            mn[i] = dis[i];
    }

    int ans = 0;
    // mn[0] = mn[1] = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= 2)
            ans = max(ans, dis[i] - min(0LL, mn[i - 2]));
        else 
            ans = max(ans, dis[i]);
    }
    cout << ans + res << '\n';
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