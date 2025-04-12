#include <bits/stdc++.h>
#define double long double
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<i64, i64>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    vector<vector<double>> dis(n + 1, vector<double>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            i64 x = a[i].first - a[j].first;
            i64 y = a[i].second - a[j].second;
            dis[i][j] = sqrtl(x * x + y * y);
        }
    }

    vector<double> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[j - 1] + dis[j][i]);
        }
    }

    cout << fixed << setprecision(10) << dp[n] << '\n';

    return 0;
}