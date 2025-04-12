#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 x;
    cin >> x;
    vector<pair<int, int>> res;
    i64 acu = 1;
    int cnt = 0;
    while (acu * 2 <= x)
    {
        acu *= 2;
        cnt++;
    }

    while (x)
    {
        if (x >= acu)
        {
            x -= acu;
            res.push_back({cnt, 1});
        }
        while (x >= acu)
        {
            x -= acu;
            res.back().second++;
        }
        acu /= 2;
        cnt--;
    }

    cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= res.front().first; i++)
    {
        ans.push_back(cnt++);
    }
    res.front().second--;
    
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < res.size(); i++)
    {
        while (res[i].second--)
        {
            ans.push_back(cnt - res[i].first - 1);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int &e : ans)
    {
        cout << e << ' ';
    }
    cout << '\n';

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