#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

i64 ksm(i64 a, i64 n)
{
    i64 ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sort(a.begin() + 1, a.end());
    
    vector<i64> dp(5003);
    dp[0] = 1;
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 5e3; j++)
        {
            if (j > a[i])
            {
                ans = (ans + (j + a[i] + 1) / 2 * dp[j]) % mod;
            }
            else
            {
                ans = (ans + a[i] * dp[j]) % mod;
            }
        }
        for (int j = 5e3; j >= a[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }

    cout << ans;

    return 0;
}