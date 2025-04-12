#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * x ^ x == 0 弥补了一些偶数的劣势
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    if (n % 2 == 1 || sum == 0)
    {
        cout << "YES\n";
        vector<array<int, 3>> ans;
        for (int i = 2; i + 1 <= n; i += 2)
        {
            ans.push_back({1, i, i + 1});
        }
        for (int i = 2; i + 1 <= n; i += 2)
        {
            ans.push_back({1, i, i + 1});
        }
        cout << ans.size() << '\n';
        for (auto &v : ans)
        {
            cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}