#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    i64 ans = 1;
    for (int i = 1; i <= n; i++)
    {
        i64 cur = 0;
        i64 now = 0;
        if (a[i] > b[i])
        {
            while (a[i])
            {
                i64 res = 0;
                while (a[i] + now > b[i] && a[i])
                {
                    res = 1 << __lg(a[i]);
                    a[i] -= 1 << __lg(a[i]);
                }
                if (a[i] + now <= b[i])
                    cur = (cur + ksm(2, __builtin_popcount(a[i]))) % mod;
                now += res;
            }
        }
        else
        {
            cur = ksm(2, __builtin_popcount(a[i]));
        }
        
        ans = (ans * cur) % mod;
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