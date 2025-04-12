#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int p2[200005];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int mn = *min_element(pre.begin() + 1, pre.end());
    // 前缀和没有负的。所有值取不取绝对值无所谓
    if (mn >= 0)
    {
        cout << p2[n] << '\n';
        return;
    }

    // 前缀和有负的。
    //      在每个最小前缀和前，前缀和为正的说明这个 i 取不取绝对值无所谓。--> 2 ^ cnt
    //      这个前缀和之后，所有 i 取不取绝对值无所谓。--> 2^(n - i)
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] >= 0)
            cnt++;
        /* 这里顺序其实无所谓，因为如果是正的话前缀和不可能是最小 */
        if (pre[i] == mn)
        {
            ans = (ans + p2[n - i + cnt]) % mod;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    p2[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        p2[i] = p2[i - 1] * 2 % mod;

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}