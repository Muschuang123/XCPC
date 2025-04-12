#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    
    if (n & 1)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> ab(26);
    for (int i = 1; i <= n; i++)
    {
        ab[s[i] - 'a']++;
        if (ab[s[i] - 'a'] > n / 2)
        {
            cout << -1 << '\n';
            return;
        }
    }

    ab.clear();
    ab.resize(26);
    int mx = 0;
    int cnt = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (s[i] == s[n - i + 1])
        {
            cnt++;
            ab[s[i] - 'a']++;
            mx = max(mx, ab[s[i] - 'a']);
        }
    }
    if (2 * mx > cnt)
    {
        cout << mx << '\n';
    }
    else
    {
        cout << (cnt + 1) / 2 << '\n';
    }
    
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