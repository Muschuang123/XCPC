#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> t(m + 1), x(m + 1), y(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    vector<int> dp(m + 1, 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin() + 1, dp.end());

    return 0;
}