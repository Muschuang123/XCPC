#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    let every 1 go to back, and then let every 2 go to back;
        until sorted.

    why? because we can't move 2 to 0 directly. 
    so that just use 1.
    the answer is existed so we have 1.

    it can be proved that operations less than n.

    just consider the  2 2 2 1 0 0 0.
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> ans;

    vector<set<int>> ss(3);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0) ss[0].insert(i);
        if (a[i] == 1) ss[1].insert(i);
        if (a[i] == 2) ss[2].insert(i);
    }

    while (ss[1].size() && ss[2].size() && *ss[2].begin() < *--ss[1].end() || 
        ss[1].size() && ss[0].size() && *ss[1].begin() < *--ss[0].end())
    {
        while (ss[1].size() && ss[0].size() && *ss[1].begin() < *--ss[0].end())
        {
            int y = *ss[1].begin();
            int x = *--ss[0].end();
            swap(a[x], a[y]);
            ans.push_back({x, y});
            ss[1].erase(y);
            ss[0].erase(x);
            ss[0].insert(y);
            ss[1].insert(x);
        }
        while (ss[1].size() && ss[2].size() && *ss[2].begin() < *--ss[1].end())
        {
            int z = *ss[2].begin();
            int y = *--ss[1].end();
            swap(a[z], a[y]);
            ans.push_back({z, y});
            ss[1].erase(y);
            ss[2].erase(z);
            ss[2].insert(y);
            ss[1].insert(z);
        }
    }

    cout << ans.size() << '\n';
    for (auto &c : ans)
    {
        cout << c.first << ' ' << c.second << '\n';
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