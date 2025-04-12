#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 10;

i64 f[maxn], g[maxn];
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

i64 cc(i64 n, i64 m)
{
    if (m > n || n < 0 || m < 0)
        return 0;
    if (m == 0)
        return 1;
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(4, vector<char>(n + 1));
    vector<vector<int>> num(3, vector<int>(10));
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != '?')
                num[j % 3][a[i][j] - '0'] = 1;
        }
    }

    for (int j = 1; j <= n; j++)
    {
        if (a[1][j] == a[2][j] && a[1][j] != '?' || 
            a[1][j] == a[3][j] && a[1][j] != '?' || 
            a[2][j] == a[3][j] && a[2][j] != '?')
        {
            cout << 0 << '\n';
            return;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        int cnt = num[0][i] + num[1][i] + num[2][i];
        if (cnt > 1)
        {
            cout << 0 << '\n';
            return;
        }
    }

    int sum = 0;
    vector<int> t(3);
    for (int i = 0; i < 3; i++)
    {
        int cnt = count(num[i].begin() + 1, num[i].end(), 1);
        if (cnt > 3)
        {
            cout << 0 << '\n';
            return;
        }
        t[i] = 3 - cnt;
        sum += cnt;
    }

    sum = 9 - sum;

    i64 ans = cc(sum, t[0]) * cc(sum - t[0], t[1]) % mod;
    for (int i = 1; i <= n; i++)
    {
        int cnt = (a[1][i] == '?') + (a[2][i] == '?') + (a[3][i] == '?');
        ans = (ans * f[cnt]) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}