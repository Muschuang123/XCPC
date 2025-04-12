#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 推式子糕手：
 * 写出公式，不要对着图想，尤其是这种好几层式子的题，
 * 公式更容易推出代码如何写。
 */

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1), pre(n + 1), pre2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        pre2[i] = pre2[i - 1] + pre[i];
    }

    auto query = [&](int l, int r)
    {
        return pre2[r] - pre2[l - 1] - pre[l - 1] * (r - l + 1); 
    };

    // block sum
    vector<i64> bs(n + 1), prebs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        bs[i] = query(i, n);
        prebs[i] = prebs[i - 1] + bs[i];
    }

    vector<i64> id(n + 1, 1);
    id[0] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        id[i] += id[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        id[i] += id[i - 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        i64 l, r;
        cin >> l >> r;
        i64 li = --lower_bound(id.begin() + 1, id.end(), l) - id.begin();
        i64 ri = --lower_bound(id.begin() + 1, id.end(), r) - id.begin();
        i64 ans = prebs[ri] - prebs[li];
        ans += query(1 + ri, ri + r - id[ri]) - query(1 + li, li + l - 1 - id[li]);
        cout << ans << '\n';
    }


}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}