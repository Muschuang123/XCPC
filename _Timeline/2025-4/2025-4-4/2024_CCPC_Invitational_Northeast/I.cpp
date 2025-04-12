#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 998244353;

i64 fac[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    fac[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int n, k;
    cin >> n >> k;
    vector<i64> f(n + 1), g(k + 1);
    for (int i = 1; i <= k; i++) {
        g[i] = fac[i];
        for (int j = 1; j < i; j++) {
            // 枚举不合法的状态，让所有的状态减去不合法的。
            // 什么状态不合法？[1, j] 是 1 ~ j 的排列就不合法 
            // j! (fac[j]) 是这种排列的个数
            // 后面的情况就让他合法，防止重复。
            g[i] = (g[i] - fac[j] * g[i - j] % mod + mod) % mod;
        }
    }

    // 前 k 个先随意排列
    f[k] = fac[k];
    for (int i = k + 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // 注意这里 g[j] 不能换成 fac[j]，设排列为 a[n]
            // 如果换成 fac[j]，当 a[i] == a[i - k]
            // 这个时候 a[i - 1] 其实也计算了一遍这种情况，这样会导致重复
            // 保证不出现这种情况的前提是，不存在：
            // j ∈ (i - k, i) 使得 a[j - k] ~ a[j] 是一个 1 ~ j 的排列
            // 即，对于每一个 [i - k, i - k + j]，都存在一个 排列之外的数
            // 所以我们要计算一个 g[] 来解决这个问题：↑
            f[i] = (f[i] + f[i - j] * g[j]) % mod;
        }
    }

    cout << f[n] << '\n';

    return 0;
}