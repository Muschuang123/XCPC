#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int mx = 0, mxi;
        vector<int> s(n + 1);
        for (int j = i; j <= n; j++)
        {
            s[a[j]]++;
            if (mx < s[a[j]] || mx == s[a[j]] && a[j] < mxi)
            {
                mx = s[a[j]];
                mxi = a[j];
            }
            ans[mxi]++;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}