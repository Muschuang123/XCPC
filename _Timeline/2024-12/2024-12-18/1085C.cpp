#include <bits/stdc++.h>
#define int long long
using namespace std;

int n = 1e3;
// vector<vector<int>> f(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
vector<pair<int, int>> a(3);
vector<pair<int, int>> ans;
int xxx, yyy;

pair<int, int> dfs1(int x, int y)
{
    ans.push_back({x, y});

    if (x + 1 <= a[1].first && x + 1 <= a[2].first)
        return dfs1(x + 1, y);

    if (y - 1 >= a[1].second && y - 1 >= a[2].second)
        return dfs1(x, y - 1);

    if (y + 1 <= a[1].second && y + 1 <= a[2].second)
        return dfs1(x, y + 1);
    
    return make_pair(x, y);
}

pair<int, int> dfs2(int x, int y)
{
    if (x != xxx || y != yyy)
        ans.push_back({x, y});

    if (x + 1 <= a[1].first)
        return dfs2(x + 1, y);

    if (y - 1 >= a[1].second)
        return dfs2(x, y - 1);

    if (y + 1 <= a[1].second)
        return dfs2(x, y + 1);
    
    return make_pair(x, y);
}

pair<int, int> dfs3(int x, int y)
{
    if (x != xxx || y != yyy)
        ans.push_back({x, y});

    if (x + 1 <= a[2].first)
        return dfs3(x + 1, y);

    if (y - 1 >= a[2].second)
        return dfs3(x, y - 1);

    if (y + 1 <= a[2].second)
        return dfs3(x, y + 1);
    
    return make_pair(x, y);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 0; i < 3; i++)
        cin >> a[i].first >> a[i].second;
    
    sort(a.begin(), a.end());

    auto [xx, yy] = dfs1(a[0].first, a[0].second);
    xxx = xx, yyy = yy;
    dfs2(xx, yy);
    dfs3(xx, yy);

    cout << ans.size() << '\n'; 
    for (auto &c : ans)
    {
        cout << c.first << ' ' << c.second << '\n';
    }


    return 0;
}