#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i % 3 == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}