#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (count(a.begin() + 1, a.end(), 0) == 0)
    {
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
    }
    else if (a[1] != 0)
    {
        cout << 2 << '\n';
        cout << 2 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
    else if (a[n] != 0)
    {
        cout << 2 << '\n';
        cout << 1 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
    else
    {
        cout << 3 << '\n';
        cout << 3 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
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