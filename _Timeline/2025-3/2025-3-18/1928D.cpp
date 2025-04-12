#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, b, x;
    cin >> n >> b >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](int mid)
    {
        i64 ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // mid 是组数
            int uh = a[i] / mid;
            int yu = a[i] % mid;
            ans += 1LL * (a[i] - (uh + 1)) * (uh + 1) * yu;
            ans += 1LL * (a[i] - uh) * uh * (mid - yu);
        }
        ans /= 2;
        return ans * b - 1LL * (mid - 1) * x;
    };

    int l = 0, r = *max_element(a.begin() + 1, a.end()) + 1;
    while (l + 1 < r)
    {
        int d = (r - l + 1) / 3;
        int ml = l + d;
        int mr = r - d;
        if (check(ml) <= check(mr))
            l = ml;
        else
            r = mr;
    }
    cout << check(l) << '\n';
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