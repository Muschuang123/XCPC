#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    if (n % 6 == 3 && n >= 9)
    {
        for (int i = 1; i <= n - 9; i += 6)
        {
            a.push_back({i, i + 1, i + 3});
            a.push_back({i + 2, i + 4, i + 5});
        }
        int i = n - 9;
        a.push_back({i + 1, i + 2, i + 4});
        a.push_back({i + 3, i + 5, i + 9});
        a.push_back({i + 6, i + 7, i + 8});
    }
    else 
    {
        for (int i = 1; i + 3 <= n; i += 6)
        {
            a.push_back({i, i + 1, i + 3});
            if (i + 5 <= n)
                a.push_back({i + 2, i + 4, i + 5});
        }
    }
    cout << a.size() << '\n';
    for (auto &[z, x, c] : a)
    {
        cout << z << ' ' << x << ' ' << c << '\n';
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