#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>, greater<>> mp;
    for (int i = 1; i <= n; i++)
    {
        int l, r, y;
        cin >> l >> r >> y;
        mp[y].push_back({l, r});
    }
    int x, y;
    cin >> x >> y;
    for (auto &[f, s] : mp)
    {
        sort(s.begin(), s.end());
    }

    while (y)
    {
        auto it = mp.lower_bound(y);
        if (it == mp.end())
        {
            break;
        }
        y = it->first;
        // vector<pair<int, int>> &a = mp[y];
        auto it2 = lower_bound(mp[y].begin(), mp[y].end(), pair<int, int>{x, x});
        if (it2 == mp[y].begin())
        {
            y--;
            continue;
        }
        auto [l, r] = *--it2;
        // cout << l << ' ' << r << '\n';
        if (x < r)
        {
            x = r;
        }
        y--;
    }
    cout << x << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}