#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int ans = 0;
    for (int len = 1; len <= n / 2; len++)
    {
        int cnt = 0;
        for (int i = 1; i + len <= n; i++)
        {
            if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            if (cnt >= len)
                ans = max(ans, len * 2);
        }
    }
    cout << ans << '\n';
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