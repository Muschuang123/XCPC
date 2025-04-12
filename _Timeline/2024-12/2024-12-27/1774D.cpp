#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> num(m + 1);
    vector<int> hh(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                num[j]++;
                hh[i]++;
            }
        }
    }
    int sum = accumulate(num.begin() + 1, num.end(), 0);
    if (sum % n != 0)
    {
        cout << -1 << '\n';
        return;
    }
    sum /= n;

    set<pair<int, int>> ss;
    for (int i = 1; i <= n; i++)
    {
        if (hh[i] != sum)
        {
            ss.insert({hh[i], i});
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    while (ss.size())
    {
        int l = ss.begin()->second;
        int r = (--ss.end())->second;
        for (int j = 1; j <= m && hh[l] < sum && hh[r] > sum; j++)
        {
            if (!a[l][j] && a[r][j])
            {
                a[l][j] = 1;
                a[r][j] = 0;
                ans.push_back({{l, r}, j});
                hh[l]++;
                hh[r]--;
            }
        }
        if (hh[l] == sum)
            ss.erase(ss.begin());
        if (hh[r] == sum)
            ss.erase(--ss.end());
    }
    
    cout << ans.size() << '\n';
    for (auto c : ans)
    {
        cout << c.first.first << ' ' << c.first.second << ' ' << c.second << '\n';
    }
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