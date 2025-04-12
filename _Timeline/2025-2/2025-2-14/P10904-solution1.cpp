#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end());
    if (a[1] >= 0)
    {
        cout << --upper_bound(a.begin() + 1, a.end(), m) - a.begin() << '\n';
        return 0;
    }
    if (a[n] <= 0)
    {
        cout << a.end() - lower_bound(a.begin() + 1, a.end(), -m) << '\n';
        return 0;
    }

    int ans = 0;

    for (int i = 0; i <= m; i++)
    {
        ans = max({ans, (int)(upper_bound(a.begin() + 1, a.end(), m - 2 * i) - 
                lower_bound(a.begin() + 1, a.end(), -i)), 
            (int)(upper_bound(a.begin() + 1, a.end(), 0) - 
                lower_bound(a.begin() + 1, a.end(), -i))});
    }

    for (int i = 0; i <= m; i++)
    {
        ans = max({ans, (int)(upper_bound(a.begin() + 1, a.end(), i) - 
                lower_bound(a.begin() + 1, a.end(), -(m - 2 * i))), 
            (int)(upper_bound(a.begin() + 1, a.end(), 0) - 
                lower_bound(a.begin() + 1, a.end(), -(m - 2 * i)))});
    }

    cout << ans << '\n';

    return 0;
}