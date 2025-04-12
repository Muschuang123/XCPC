#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a.begin() + 1, a.end());

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((a[i] ^ a[j]) == __gcd(a[i], a[j]))
            {
                ans++;
                cout << a[i] << ' ' << a[j] << '\n';
            }
        }
    }
    cout << ans << '\n';

    return 0;
}