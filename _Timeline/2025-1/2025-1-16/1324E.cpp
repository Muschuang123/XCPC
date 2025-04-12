#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 对于这种题的dp。
 * 当前状态从上个状态延续而来，中间不能丢失转移，
 * 所以每次都要保证dp是上次的状态。
 * 我们新建一个空的rp来保证rp必须是从上次dp延续而来，
 * 并且在下个状态转移时，把rp交给dp。
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(h, -1e18), rp(h, -1e18);
    dp[a[1]] = (a[1] >= l && a[1] <= r);
    dp[a[1] - 1] = (a[1] - 1 >= l && a[1] - 1 <= r);
    for (int i = 2; i <= n; i++)
    {
        rp.clear();
        rp.resize(h, -1e18);
        for (int j = 0; j < h; j++)
        {
            int cur = (j + a[i]) % h;
            int cur2 = (j + a[i] - 1) % h;
            if (dp[j] != -1e18)
            {
                rp[cur2] = max(rp[cur2], dp[j] + (cur2 >= l && cur2 <= r));
                rp[cur] = max(rp[cur], dp[j] + (cur >= l && cur <= r));
            }
        }
        dp = rp;
        cout << "";
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}