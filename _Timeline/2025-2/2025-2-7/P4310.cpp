#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(32);
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        for (int j = 0; j < 32; j++)
        {
            if (1 << j & a[i])
            {
                mx = max(mx, dp[j] + 1);
            }
        }
        for (int j = 0; j < 32; j++)
        {
            if (1 << j & a[i])
            {
                dp[j] = max(dp[j], mx);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}