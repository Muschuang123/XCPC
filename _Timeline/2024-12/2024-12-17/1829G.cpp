#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[2001][2001];
int dp[1000006];

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int p = 1;
    for (int i = 1; p <= 1000000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = p * p;
            a[i][j] += a[i - 1][j - 1] + a[i - 1][j];
            if (i > 1)
                a[i][j] -= a[i - 2][j - 1];
            dp[p] = a[i][j];
            p++;
        }
    }

    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}