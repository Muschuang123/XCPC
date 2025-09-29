// n 个点确定一个 n - 1 阶多项式
// O(n^2)
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

const int maxn = 2e3 + 3;
const int mod = 998244353;

i64 X[maxn], Y[maxn];

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
    ios::sync_with_stdio(0), cin.tie(0);

    i64 n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 a = Y[i], b = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            a = a * (k - X[j] + mod) % mod;
            b = b * (X[i] - X[j] + mod) % mod;
        }
        ans = (ans + a * ksm(b, mod - 2)) % mod;
    }
    cout << ans << '\n';

    return 0;
}