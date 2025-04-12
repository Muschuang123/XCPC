// https://www.luogu.com.cn/problem/P1435
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 最长公共子序列

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    string v = s;
    reverse(v.begin() + 1, v.end());
    vector<int> dp(n + 1), vp;
    for (int i = 1; i <= n; i++)
    {
        vp = dp;
        for (int j = 1; j <= n; j++)
        {
            if (s[i] == v[j])
                dp[j] = vp[j - 1] + 1;
            else 
                dp[j] = max(dp[j - 1], vp[j]);
        }
    }

    cout << n - dp[n];

    return 0;
}