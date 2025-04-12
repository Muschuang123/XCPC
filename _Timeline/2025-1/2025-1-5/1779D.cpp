#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    两个小的中间被大的隔开，那么这两个小的必须分开剃。
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int m;
    cin >> m;
    vector<int> x(m + 1);
    for (int i = 1; i <= m; i++) cin >> x[i];

    map<int, int> mp;
    vector<int> cur;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < b[i])
        {
            cout << "NO\n";
            return;
        }
        while (cur.size() && cur.back() < b[i])
        {
            cur.pop_back();
        }
        if (a[i] > b[i])
        {
            if (cur.empty() || cur.back() != b[i])
            {
                cur.push_back(b[i]);
                mp[b[i]]++;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (mp.count(x[i]))
        {
            mp[x[i]]--;
            if (mp[x[i]] == 0)
                mp.erase(x[i]);
        }
    }

    if (mp.size())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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