#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int dig = 0;
    int t = n;
    vector<int> pre;
    while (t > 0)
    {
        pre.push_back(t % 10);
        t /= 10;
        dig++;
    }

    reverse(pre.begin(), pre.end());

    vector<pair<int, int>> ans;
    for (int a = 1; a <= 1e4; a++)
    {
        for (int r = a * dig - 1; a * dig - r <= 6; r--)
        {
            if (r < 1)
                continue;
            int res = 0;
            for (int i = 0; i < a * dig - r; i++)
            {
                res *= 10;
                res += pre[i % dig];
            }

            if (a * n - r == res)
            {
                ans.emplace_back(a, r);
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [f, s] : ans)
    {
        cout << f << ' ' << s << '\n';
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