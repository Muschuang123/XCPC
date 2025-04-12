#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = accumulate(a.begin() + 1, a.end(), 0LL);

    vector<int> pre(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {   
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        pre[i] = pre[i - 1] + a[i - n]; 
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int nl = l / n;
        int nr = r / n;
        int ans = (nr - nl) * sum;

        auto work = [&](int i, int ni) -> int
        {
            return pre[ni + i % n] - pre[ni];
        };
        ans += work(r, nr) - work(l, nl);
        cout << ans << '\n';
    }
    
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