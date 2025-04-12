#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1), c(n + 1);
    i64 sa = 0, sb = 0, sc = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sa += a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], sb += b[i];
    for (int i = 1; i <= n; i++) cin >> c[i], sc += c[i];

    cout << (sc - sb) / sa << '\n';

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