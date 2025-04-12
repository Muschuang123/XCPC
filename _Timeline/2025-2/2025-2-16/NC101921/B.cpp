#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    int ok = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            ok &= a[i][j] <= a[i + 1][j] && a[i][j] <= a[i + 1][j + 1];
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}