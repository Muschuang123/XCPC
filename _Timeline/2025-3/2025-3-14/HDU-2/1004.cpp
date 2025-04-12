#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    string s, k;
    cin >> s >> k;
    int x = 0;
    if (k.size() >= 3 || stoi(k) > 26)
    {
        x = 26;
    }
    else
    {
        x = stoi(k);
    }

    string t;
    for (int i = 1; i <= x; i++)
    {
        t += s;
    }

    int n = t.size();
    t = " " + t;
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t[i] > dp[len])
        {
            len++;
            dp[len] = t[i];
        }
        else
        {
            dp[lower_bound(dp.begin(), dp.begin() + len, t[i]) - dp.begin()] = t[i];
        }
    }

    cout << len;

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