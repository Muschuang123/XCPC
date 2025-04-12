#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    // dp[i] 为 以 i 结尾的 所有子串（共 i 个）的贡献
    // 先求出每一个，最后再 accumulate
    vector<i64> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            // 如果 s[i] 是 '1' 的话，那 这个 '1' 必须被覆盖到。
            // 因为我们可以用 一个 '1' 覆盖 3 个点，所以可以跳过前两个。
            dp[i] = dp[max(0, i - 3)] + i;
        else 
            dp[i] = dp[i - 1];
    }
    cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << '\n';
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