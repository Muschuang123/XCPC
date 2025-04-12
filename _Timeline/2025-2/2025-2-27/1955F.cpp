#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    vector<int> a(5);
    for (int i = 1; i <= 4; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    ans += a[1] % 2 && a[2] % 2 && a[3] % 2;
    ans += a[1] / 2 + a[2] / 2 + a[3] / 2 + a[4] / 2;
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