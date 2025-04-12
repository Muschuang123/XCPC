#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> l(k + 1), r(k + 1);
    vector<vector<int>> c(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> l[i];
    for (int i = 1; i <= k; i++)
        cin >> r[i];
    for (int i = 1; i <= k; i++)
        c[i] = vector<int>((r[i] - l[i] + 2) / 2);
    
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int i = --upper_bound(l.begin() + 1, l.end(), x) - l.begin();
        x = min(x - l[i], r[i] - x);
        c[i][x]++;
    }

    for (int i = 1; i <= k; i++)
    {
        int sz = c[i].size();
        for (int j = 1; j < sz; j++)
        {
            c[i][j] += c[i][j - 1];
        }
        for (int j = 0; j < sz; j++)
        {
            if (c[i][j] % 2)
                swap(s[l[i] + j], s[r[i] - j]);
        }
    }
    cout << s.substr(1, n) << '\n';

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