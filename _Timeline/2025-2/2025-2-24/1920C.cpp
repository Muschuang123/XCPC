#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](int o) -> int
    {
        if (o == n)
            return 1;
        int g = abs(a[o + 1] - a[1]);
        for (int i = o + 2; i <= n; i++)
        {
            int idx = i % o == 0 ? o : i % o;
            g = gcd(g, abs(a[i] - a[idx]));
        }
        return g != 1;
    };

    int ans = 0;
    for (int o = 1; o * o <= n; o++)
    {
        if (n % o == 0)
        {
            ans += check(o);
            if (o == n / o)
                break;
            ans += check(n / o);
        }
    }
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