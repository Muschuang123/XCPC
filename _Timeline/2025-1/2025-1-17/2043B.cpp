#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> ans(10);
    ans[1] = 1;
    ans[5] = d == 5;

    for (int i = 1; i <= min(n, 9LL); i++)
    {
        d *= i;
        ans[3] |= d % 3 == 0;
        ans[7] |= d % 7 == 0;
        ans[9] |= d % 9 == 0;
    }
    ans[7] |= n >= 3;

    for (int i = 1; i <= 9; i++)
    {
        if (ans[i])
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
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