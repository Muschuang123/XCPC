#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> a(n + 1);
    map<string, int> mp;
    map<string, int> lt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        mp[a[i].first] += a[i].second;
    }


    int mx = 0;
    for (auto &c : mp)
    {
        mx = max(mx, c.second);
    }
    set<string> winner;
    for (auto &c : mp)
        if (c.second == mx)
            winner.insert(c.first);

    mp.clear();
    for (int i = 1; i <= n; i++)
    {
        mp[a[i].first] += a[i].second;
        if (winner.count(a[i].first) && mp[a[i].first] >= mx)
        {
            cout << a[i].first;
            return 0;
        }
    }

    return 0;
}