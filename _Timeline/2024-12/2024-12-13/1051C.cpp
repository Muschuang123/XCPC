#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = 0;
    int res = 0;
    int fl = 0;
    for (auto &c : mp)
    {
        if (c.second == 1)
            cnt++;
        if (c.second >= 3)
        {
            if (!fl)
                fl = c.first;
            res++;
        }
    }
    if (res || cnt % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO";
        return 0;
    }
    
    vector<char> ans(n + 1);
    if (cnt % 2 == 0)
    {
        int p = 0;
        for (int i = 1; i <= n && p < cnt / 2; i++)
        {
            if (mp[a[i]] == 1)
            {
                ans[i] = 'A';
                p++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
            {
                ans[i] = 'B';
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == fl)
            {
                ans[i] = 'A';
                break;
            }
        }

        int p = 0;
        for (int i = 1; i <= n && p < (cnt - 1) / 2; i++)
        {
            if (mp[a[i]] == 1)
            {
                ans[i] = 'A';
                p++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
            {
                ans[i] = 'B';
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    return 0;
}