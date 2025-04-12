#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int n = 62;
i64 f[70][70];

void init()
{
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int i = n; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                if (i - l >= 0)
                    f[i][j] = min(f[i][j], f[i - l][j] + (1LL << l));
                if (j - l >= 0)
                    f[i][j] = min(f[i][j], f[i][j - l] + (1LL << l));
            }
        }
    }
}

void solve()
{
    i64 x, y;
    cin >> x >> y;

    // save the numbers after divided by 2^i
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; i++) a[i] = x >> i;
    for (int i = 0; i <= n; i++) b[i] = y >> i;

    i64 ans = 9e18;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // we can cost f[i][j] to make x equal to y
            if (a[i] == b[j])
                ans = min(ans, f[i][j]);
        }
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