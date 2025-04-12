#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m >= n || n - m > 26) // m < (n + 1) / 2 ||
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string ans;
    for (int i = 0; i < n - m; i++)
    {
        ans.push_back('a' + i);
    }
    for (int i = 0; i < m; i++)
    {
        ans.push_back('a' + i % 26);
    }
    cout << ans << '\n';
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