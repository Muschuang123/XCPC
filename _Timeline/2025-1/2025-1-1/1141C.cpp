#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    correct the 1, if can't, then correct the n.
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans(n + 1);
    for (int i = 1; i < n; i++)
    {
        ans[i + 1] = ans[i] + a[i];
    }

    int mn = *min_element(ans.begin() + 1, ans.end());
    int mx = *max_element(ans.begin() + 1, ans.end());

    mn = -mn;
    if (mn >= 0)
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i] + mn + 1;
    }
    else 
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i] - mx;
    }

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] > n)
        {
            cout << -1 << '\n';
            return 0;
        }
        b[ans[i]]++;
        if (b[ans[i]] > 1)
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        cout << ans[i] << ' ';
    }


    return 0;
}