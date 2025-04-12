#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    // 一直取模，如果 j > i 说明是 0，取到 0 就是 k
    i64 n, k;
    cin >> n >> k;
    for (int e = 1; e <= n; e++)
    {
        i64 i = n, j = e;
        int fl = 1;
        while (i > 1)
        {
            i64 dec = 1 << __lg(i);
            if (i == dec)
                dec >>= 1;
            i -= dec;
            if (j - dec > 0)
                j -= dec;
            if (j > i)
            {
                fl = 0;
                break;
            }
        }
        cout << (fl ? k : 0) << " \n"[e == n];
    }
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