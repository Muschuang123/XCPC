#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    vector<int> a(2 * n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        if (a[i - 1] == a[i])
            vis[a[i]] = 1;
    }
    for (int i = 2; i <= 2 * n; i++)
    {
        if (a[i - 1] == a[i] || vis[a[i]])
            continue;
        int x = a[i - 1], y = a[i];
        if (x > y)
        {
            mp[{y, x}] += 3;
        }
        else 
        {
            mp[{x, y}] += 2;
        }
    }
    int cnt = 0;
    for (auto &[f, s] : mp)
    {
        if (s > 3 && s < 6)
            cnt++;
    }

    cout << cnt << '\n';
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