#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    if (n == 1)
    {
        for (int i = 1; i <= m; i++)
            cout << a[1] + b[i] << ' ';
        return 0;
    }

    int g = a[2] - a[1];
    for (int i = 3; i <= n; i++) 
        g = gcd(g, a[i] - a[1]);

    for (int i = 1; i <= m; i++)
    {
        cout << gcd(g, a[1] + b[i]) << ' ';
    }

    return 0;
}