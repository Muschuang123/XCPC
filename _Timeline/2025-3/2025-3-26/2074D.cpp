#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> r[i];

    // 存住每一列能取多少个 y
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = x[i] - r[i]; j <= x[i] + r[i]; j++)
        {
            int y = sqrtl(1LL * r[i] * r[i] - 1LL * (j - x[i]) * (j - x[i]));
            mp[j] = max(mp[j], y);
        }
    }

    i64 ans = 0;
    for (auto &[f, s] : mp)
    {
        ans += 2LL * s + 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}