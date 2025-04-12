#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

i64 ksm(i64 a, i64 n)
{
    i64 ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

i64 inv(i64 x)
{
    return ksm(x, mod - 2);
}

void solve()
{
    int n;
    cin >> n;
    vector<i64> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }

    auto cal1 = [&](i64 l1, i64 r1, i64 l2, i64 r2) -> i64
    {
        if (l1 > r1 || l2 > r2)
            return 0;
        return (((l2 + r2) * inv(2) % mod - (l1 + r1) * inv(2) % mod) % mod + mod) *
               (r1 - l1 + 1) % mod * (r2 - l2 + 1) % mod;
    };

    auto cal2 = [&](i64 l, i64 r) -> i64
    {
        if (l > r)
            return 0;
        i64 len = r - l + 1;
        return len * (len - 1) % mod * (len + 1) % mod * inv(3) % mod;
    };

    i64 ans = 0;
    for (int i = 2; i <= n; i++)
    {
        i64 res = 0;
        i64 l1 = l[i - 1], r1 = r[i - 1];
        i64 l2 = l[i], r2 = r[i];
        if (r2 < r1)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        i64 x = max(l1, l2);
        i64 y = min(r1, r2);

        if (x > y)
        {
            res = cal1(l1, r1, l2, r2);
        }
        else if (l1 < l2)
        {
            res = cal1(l1, l2 - 1, l2, r2) + cal1(l2, r1, r1 + 1, r2) + cal2(x, y);
        }
        else
        {
            res = cal1(l2, l1 - 1, l1, r1) + cal1(l1, r1, r1 + 1, r2) + cal2(x, y);
        }
        res = (res + mod) % mod;
        res = res * inv((r2 - l2 + 1) * (r1 - l1 + 1) % mod) % mod;
        ans = (ans + res) % mod;
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