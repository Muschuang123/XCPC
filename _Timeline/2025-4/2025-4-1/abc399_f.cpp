// https://www.cnblogs.com/wfc284/p/18799817#f
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 一个区间 和/差 的 k 次方，我们可以计算前缀和的 二项式
// 注意通常需要计算正负号，因为 是 sum[r] - sum[l - 1]
// 写成二项式之后，变成两项乘积的求和，1 <= l < r <= n，
// 对于每一个 r ，它要乘上所有小于他的 l，即 A[r] * pre[l - 1]

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
        a[i] = (a[i - 1] + a[i]) % mod;
    }

    vector<vector<i64>> pre(n + 1, vector<i64>(k + 1));
    pre[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            pre[i][j] = (pre[i - 1][j] + ksm(a[i], j)) % mod;
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            ans = (ans + pre[i - 1][j] * ksm(a[i], k - j) % mod * C[k][j] * ksm(-1, j) % mod + mod) % mod;
        }
    }

    cout << ans << '\n';

    return 0;
}