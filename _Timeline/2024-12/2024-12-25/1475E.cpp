#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e3 + 3;
const int mod = 1e9 + 7;
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a.begin() + 1, a.end(), greater<int>());
    int mm = upper_bound(a.begin() + 1, a.end(), a[k], greater<int>()) -
        lower_bound(a.begin() + 1, a.end(), a[k], greater<int>());
    int nn = k - (--lower_bound(a.begin() + 1, a.end(), a[k], greater<int>()) - a.begin());
    cout << cc(mm, nn) << '\n';
}

signed main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}