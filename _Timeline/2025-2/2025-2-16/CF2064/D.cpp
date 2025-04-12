#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> c(31, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int x = a[i];
        int dig = 0;
        while (x)
        {
            c[dig][i] = x & 1;
            x >>= 1;
            dig++;
        }
    }

    // a[0] = (1 << 30) - 1;
    b[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        b[i] = b[i + 1] ^ a[i];
    }

    for (int j = 0; j <= 30; j++)
        c[j][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            c[j][i] += c[j][i - 1];
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        int t = x;
        int ans = 0;
        int cur = n;
        for (int dig = 30; dig >= 0; dig--)
        {
            int res = lower_bound(c[dig].begin(), c[dig].end(), c[dig][cur]) - c[dig].begin();
            if (x >> dig & 1)
            {
                if (res == 0)
                {
                    cur = 0;
                    break;
                }
                if (res < n)
                    x = t ^ b[res + 1];
                if (a[res] > x)
                {
                    ans = max(ans, res);
                    cur = res;
                    break;
                }
                x ^= a[res];
                cur = res - 1;
                ans = max(ans, (int)(lower_bound(c[dig].begin(), c[dig].end(), c[dig][cur]) - c[dig].begin()));
            }
            else
            {
                ans = max(ans, res);
            }
        }

        ans = max(ans, cur);
        cout << n - ans << ' ';
    }
    cout << '\n';
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