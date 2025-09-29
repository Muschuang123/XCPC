#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

const int mod = 998244353;
i64 dp[1 << 22];
int f[1 << 22], vis[1 << 22];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < 1 << n; i++) {
        int p = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                while (s[p] != s[j]) p++;
                f[i] |= 1 << p;
                p++;
            }
        }
    }

    dp[0] = 1;
    for (int i = 0; i < 1 << n; i++) {
        if (f[i] != i) continue;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                int mask = i ^ 1 << j;
                mask = f[mask];
                if (vis[mask] < i) {
                    vis[mask] = i;
                    dp[i] = (dp[i] + dp[mask]) % mod;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << '\n';

    return 0;
}