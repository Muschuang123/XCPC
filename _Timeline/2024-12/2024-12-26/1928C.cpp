#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    set<int> ans;

    for (auto c : vector<int>{n - x, n + x - 2})
    {
        for (int i = 1; i * i <= c; i++)
        {
            if (c % i == 0)
            {
                if (i % 2 == 0 && i / 2 + 1 >= x)
                    ans.insert(i);
                if (c / i % 2 == 0 && c / i / 2 + 1 >= x)
                    ans.insert(c / i);
            }
        }
    }
    cout << ans.size() << '\n';
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