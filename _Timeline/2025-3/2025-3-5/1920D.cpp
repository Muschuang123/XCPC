#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1);
    vector<i64> x(n + 1), len(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i] >> x[i];
        if (b[i] == 1)
        {
            len[i] = len[i - 1] + 1 > (i64)2e18 ? (i64)2e18 : len[i - 1] + 1;
        }
        else 
        {
            i128 t = (i128)len[i - 1] * (i128)(x[i] + 1);
            len[i] = t > (i128)2e18 ? (i64)2e18 : (i64)t;
        }
    }

    while (q--)
    {
        i64 k;
        cin >> k;
        i64 idx = lower_bound(len.begin() + 1, len.end(), k) - len.begin();
        while (b[idx] != 1) // len[idx] != k || 
        {
            // k = (k - 1) % (len[idx] / (x[idx] + 1)) + 1;
            k = (k - 1) % len[idx - 1] + 1;
            idx = lower_bound(len.begin() + 1, len.end(), k) - len.begin();
        }
        cout << x[idx] << ' ';
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