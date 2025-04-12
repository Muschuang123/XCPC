#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> ans(n + 1);
    for (int j = 1; j <= n; j++)
    {
        ans[j].push_back(j);
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j] == '1')
                ans[j].push_back(i);
        }
        sort(ans[j].begin(), ans[j].end());
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].size() << ' ';
        for (auto &c : ans[i])
            cout << c << ' ';
        cout << '\n';
    }

    
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