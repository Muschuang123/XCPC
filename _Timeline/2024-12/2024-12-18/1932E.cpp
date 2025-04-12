#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 0; i <= n; i++)
        a[i] = s[i] - '0';

    sum[0] = a[0];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];

    for (int i = n; i > 0; i--)
    {
        a[i] += sum[i - 1];
        a[i - 1] += a[i] / 10;
        a[i] %= 10;
    }

    int fl = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] != 0)
            fl = 1;
        if (fl)
            cout << a[i];
    }
    cout << '\n';

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}