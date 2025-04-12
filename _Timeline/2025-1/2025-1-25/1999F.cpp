#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;

int f[maxn], g[maxn];

int ksm(int a, int n)
{
    int ans = 1;
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

void init()
{
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
}

int cc(int n, int m)
{
    if (m > n || n < 0 || m < 0)
        return 0;
    if (m == 0)
        return 1;
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt0 += x == 0;
        cnt1 += x == 1;
    }
    
    int ans = 0;
    for (int i = 0; (k + 1) / 2 + i <= cnt1; i++)
    {
        ans = (ans + cc(cnt1, (k + 1) / 2 + i) * cc(cnt0, (k - 1) / 2 - i) % mod) % mod;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}