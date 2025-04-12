#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string a;
    cin >> a;
    a = " " + a;
    int ans = 0;

    vector<int> c(26);
    vector<int> ind(26);
    for (int i = 1; i <= n; i++)
    {
        c[a[i] - 'a']++;
        if (c[a[i] - 'a'] >= 2)
        {
            ans = max(ans, ind[a[i] - 'a']);
        }
        ind[a[i] - 'a'] = i;
    }

    c.clear();
    c.resize(26);
    ind.clear();
    ind.resize(26);
    for (int i = n; i >= 1; i--)
    {
        c[a[i] - 'a']++;
        if (c[a[i] - 'a'] >= 2)
        {
            ans = max(ans, n - ind[a[i] - 'a'] + 1);
        }
        ind[a[i] - 'a'] = i;
    }

    cout << ans << '\n';

    return 0;
}