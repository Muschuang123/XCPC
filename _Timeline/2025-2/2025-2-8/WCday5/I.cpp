#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
    {
        cout << "Yes\n";
        return;
    }

    if (n == 0 || m == 0)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
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