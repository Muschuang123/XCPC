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
    int n, k;
    cin >> n >> k;
    vector<i64> a(k + 1);
    for (int i = 0; i <= k; i++)
        cin >> a[i];
    
    i64 me = a[0];
    sort(a.begin() + 1, a.end());

    vector<i64> res;

    i64 la = 0;
    for (i64 i = 2; i <= n; i <<= 1)
    {
        i64 up = (me + i - 1) / i * i;
        i64 low = (me - 1) / i * i;
        i64 w = upper_bound(a.begin() + 1, a.end(), up) - 
            upper_bound(a.begin() + 1, a.end(), low);
        i64 p = (i / 2 - w + la) * ksm(i / 2, mod - 2) % mod;
        res.push_back(p);
        la = w;
    }

    i64 ans = 1;
    for (i64 &e : res)
    {
        ans = (ans * e) % mod;
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