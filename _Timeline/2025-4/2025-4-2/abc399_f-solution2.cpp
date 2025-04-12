#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

i64 ksm(i64 a, i64 n) {
    i64 ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 杨辉三角做出 12 以内的组合数
    int C[13][13] = {0};
    for (int i = 0; i <= 12; i++) {
        C[i][0] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
        C[i][i] = 1;
    }

    int n, k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<i64> dp(k + 1);
    dp[0] = 1;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<i64> tp(k + 1);
        tp[0] = 1;
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= j; l++) {
                tp[j] = (tp[j] + C[j][l] * dp[l] % mod * ksm(a[i], j - l) % mod) % mod;
            }
        }
        dp = tp;
        ans = (ans + tp[k]) % mod;
    }
    cout << ans << '\n';

    return 0;
}