#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * this the solution of hash version.
 * prefix ----reverse----> suffix
 * 
 * !!Critical: 字符串哈希 从 1 ~ n
 * 1号位乘base的次数最多，是n
 * n号位一次base也没乘
 */

const int bas1 = 13331, bas2 = 20180720;
const int mod = 1e9 + 7;

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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;

    // double hash to increase accuracy.
    vector<int> pre1(n + 1), pre2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre1[i] = (pre1[i - 1] * bas1 + s[i]) % mod;
        pre2[i] = (pre2[i - 1] * bas2 + s[i]) % mod;
    }

    vector<int> suf1(n + 2), suf2(n + 2);
    for (int i = n; i >= 1; i--)
    {
        suf1[i] = (suf1[i + 1] * bas1 + s[i]) % mod;
        suf2[i] = (suf2[i + 1] * bas2 + s[i]) % mod;
    }

    string cs1, cs2;
    for (int i = 1; i <= n / k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cs1.push_back(i % 2 + '0');
            cs2.push_back(1 - (i % 2) + '0');
        }
    }

    int c11 = 0, c12 = 0, c21 = 0, c22 = 0;
    for (int i = 0; i < n; i++)
    {
        c11 = (c11 * bas1 + cs1[i]) % mod;
        c12 = (c12 * bas1 + cs2[i]) % mod;
        c21 = (c21 * bas2 + cs1[i]) % mod;
        c22 = (c22 * bas2 + cs2[i]) % mod;
    }

    for (int i = 0; i <= n; i++)
    {
        int h1 = (pre1[i] * ksm(bas1, n - i) + suf1[i + 1]) % mod;
        int h2 = (pre2[i] * ksm(bas2, n - i) + suf2[i + 1]) % mod;
        if (h1 == c11 && h2 == c21 || h1 == c12 && h2 == c22)
        {
            if (i == 0)
                i = n;
            cout << i << '\n';
            return;
        }
        cout << "";
    }
    
    cout << -1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}