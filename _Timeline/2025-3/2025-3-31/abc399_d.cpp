#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        if (a[i - 1] == a[i])
            vis[a[i]] = 1;
    }
    map<pair<int, int>, vector<int>> mp;
    for (int i = 2; i <= 2 * n; i++)
    {
        if (!vis[a[i]] && !vis[a[i - 1]] && a[i - 1] != a[i])
            mp[{min(a[i - 1], a[i]), max(a[i - 1], a[i])}].push_back(i);
    }

    int ans = 0;
    for (auto &[f, s] : mp)
    {
        if (s.size() >= 2 && abs(s.front() - s.back()) > 1)
            ans++;
    }
    cout << ans << '\n';
    
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