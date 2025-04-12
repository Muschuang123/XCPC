#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 最优情况：删1数 = 剩0数。此时再删不会更优：删1完蛋，删0没用。
 * 删数 = 删1数 + 删0数 = 删0数 + 剩0数 = 0数。
 * 只能从左右删，两极。
 */

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int n0 = count(s.begin(), s.end(), '0');
    int n1 = count(s.begin(), s.end(), '1');
    s = " " + s;
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n0; i++)
    {
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    int ans = max(c1, n0 - c0);
    for (int i = 1; i <= n0; i++)
    {
        c0 -= s[n0 - i + 1] == '0';
        c1 -= s[n0 - i + 1] == '1';
        c0 += s[n - i + 1] == '0';
        c1 += s[n - i + 1] == '1';
        ans = min(ans, max(c1, n0 - c0));
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