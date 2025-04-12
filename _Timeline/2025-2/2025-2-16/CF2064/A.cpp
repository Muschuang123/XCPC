#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for (int i = 1; i < s.size(); i++)
    {
        ans += s[i] != s[i - 1];
    }
    ans -= s[0] == '0';
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