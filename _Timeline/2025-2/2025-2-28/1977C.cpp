#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 若 n 个数的最小公倍数是 L，
// 则从中取任意个数，最小公倍数肯定为 L 的因数。
// 证：如果不是 L 的因数的话，最小公倍数就是 lcm(L, 最小公倍数)。 

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    i64 L = 1;
    for (int i = 1; i <= n; i++)
    {
        L = lcm(L, a[i]);
        if (L > a[n])
        {
            cout << n << '\n';
            return;
        }
    }

    // 这个时候 L == a[n] 了，只有 L 的因数 才可能是答案。
    int ans = 0;
    auto check = [&](int l) -> void
    {
        // 看看 是不是 l 的因数的最小公倍数就是 l
        i64 LCM = 1;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (l % a[i] == 0)
            {
                LCM = lcm(LCM, a[i]);
                res++;
            }
        }
        if (LCM == l)
            ans = max(ans, res);
    };

    for (int i = 1; i * i <= L; i++)
    {
        if (L % i == 0)
        {
            if (*lower_bound(a.begin() + 1, a.end(), i) != i)
                check(i);
            if (*lower_bound(a.begin() + 1, a.end(), L / i) != L / i)
                check(L / i);
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