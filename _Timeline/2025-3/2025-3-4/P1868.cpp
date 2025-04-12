#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 3e6 + 1;

int dp[maxn + 6];
vector<int> lf[maxn + 6];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        l++, r++;
        lf[r].push_back(l);
    }

    for (int i = 1; i <= maxn; i++)
    {
        dp[i] = dp[i - 1];
        for (int &e : lf[i])
            dp[i] = max(dp[i], dp[e - 1] + i - e + 1);
    }

    cout << dp[maxn];

    return 0;
}