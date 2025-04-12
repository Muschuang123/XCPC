#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, char>> a(3);
    a[0].second = 'T';
    a[1].second = 'I';
    a[2].second = 'L';

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'T') a[0].first++;
        if (s[i] == 'I') a[1].first++;
        if (s[i] == 'L') a[2].first++;
    }
    int ok = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] != s[i])
        {
            ok = 1;
        }
    }
    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    while (!(a[0].first == a[1].first && a[1].first == a[2].first))
    {
        int fl = 0;
        sort(a.begin(), a.end());
        // 尝试插入最小的
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] != s[i] && s[i - 1] != a[0].second && s[i] != a[0].second)
            {
                s.insert(i, string(1, a[0].second));
                a[0].first++;
                ans.push_back(i);
                fl = 1;
                break;
            }
        }
        if (fl)
            continue;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] != s[i] && s[i - 1] != a[2].second && s[i] != a[2].second)
            {
                s.insert(i, string(1, a[2].second));
                a[2].first++;
                ans.push_back(i);
                fl = 1;
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &e : ans)
        cout << e << '\n';

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