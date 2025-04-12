#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
int n;
string s;
i64 ans = 0;

void dfs(int i)
{
    if (i == n + 1)
    {
        ans = (ans + (s[1] == s[n] ? n - 2 : 2)) % mod;
        return;
    }
    if (s[i] == '?')
    {
        s[i] = '1';
        dfs(i + 1);
        s[i] = '0';
        dfs(i + 1);
        s[i] = '?';
    }
    else
    {
        dfs(i + 1);
    }
}

void solve()
{
    ans = 0;
    cin >> n;
    cin >> s;

    if (n == 1)
    {
        cout << (s[0] == '?' ? 2 : 1) << '\n';
        return;
    }

    s = " " + s;
    dfs(1);
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