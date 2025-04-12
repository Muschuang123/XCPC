#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        mp[b[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!mp.count(a[i]))
        {
            cout << "NO\n";
            return;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] != b[i])
        {
            swap(a[i], a[mp[a[i]]]);
            cnt++;
        }
    }
    if (cnt % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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