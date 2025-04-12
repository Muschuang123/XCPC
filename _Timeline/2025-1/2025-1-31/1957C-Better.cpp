#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
i64 dp[maxn];

void init()
{
    dp[0] = 1;
    for (int i = 1; i <= 3e5; i++)
    {
        dp[i] = dp[i - 1];
        if (i >= 2)
        {
            // calc the case of: pick up two in once time.
            // we pick up them from dp[i - 2]
            // i - 1 which donate to we can choose i and anyone to make up "two".
            // the anyone was shown by "i - 1". 
            // 插空法，i - 2 个 拿 算上两边，有 i - 1 个空，拿这个空和 i。
            // on the other hand, the location of black and white could exchange.
            // this operation was shown by "2".
            dp[i] = (dp[i] + dp[i - 2] * (i - 1) * 2) % mod;
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        n -= 1 + (u != v);
    }
    cout << dp[n] << '\n';
}

int main()
{
    init();

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}