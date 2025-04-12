#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum != n * (n + 1) / 2)
    {
        cout << -1 << '\n';
        return 0;
    }

    int ans = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > i)
        {
            ans += a[i] - i;
        }
    }
    cout << ans << '\n';

    return 0;
}