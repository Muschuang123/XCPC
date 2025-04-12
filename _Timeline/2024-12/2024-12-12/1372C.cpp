#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int fl = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fl % 2 == 0 && a[i] != i)
            fl++;
        if (fl % 2 == 1 && a[i] == i)
            fl++;
    }
    if (fl == 0)
    {
        cout << 0 << '\n';
        return;
    }
    if (fl % 2 == 0)
    {
        fl--;
    }
    if (fl == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }
    

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