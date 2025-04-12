#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int mxi = 0;
    bool fl = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == n)
        {
            mxi = i;
            if (i == 1)
                fl = 1;
        }
        if (a[i] == n - 1 && fl)
            mxi = i;
    }

    vector<int> ans(1);
    if (mxi == n)
    {
        int p = mxi - 1;
        for (; a[p] > a[1]; p--);
        p++;

        for (int i = mxi; i <= n; i++)
            ans.push_back(a[i]);
        for (int i = mxi - 1; i >= p; i--)
            ans.push_back(a[i]);
        for (int i = 1; i < p; i++)
            ans.push_back(a[i]);
    }
    else
    {
        int p = mxi - 2;
        for (; a[p] > a[1]; p--);
        p++;
        for (int i = mxi; i <= n; i++)
            ans.push_back(a[i]);
        for (int i = mxi - 1; i >= p; i--)
            ans.push_back(a[i]);
        for (int i = 1; i < p; i++)
            ans.push_back(a[i]);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];

    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}