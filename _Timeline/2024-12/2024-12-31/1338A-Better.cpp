#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    for the number behind who is bigger than it,
        it can be increase to equal with the bigger number by 2^(x - 1)
    
    so just calculate the difference's highest 1 bit.
        use the __lg() or log2().
*/

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    int pre = -1e9;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pre = max(pre, x);
        if (pre > x)
            ans = max(ans, __lg(pre - x) + 1);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}