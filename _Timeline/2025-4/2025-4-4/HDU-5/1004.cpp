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

// 循环卷积
vector<i64> mul(vector<i64> &a, vector<i64> &b, int m) {
    vector<i64> ans(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ans[(i + j) % m] = (ans[(i + j) % m] + a[i] * b[j]) % mod;
        }
    }
    return ans;
}

// 多项式系数 快速幂
vector<i64> ksm(vector<i64> a, i64 n, int m) {
    vector<i64> ans(m);
    ans[0] = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a, m);
        }
        a = mul(a, a, m);
        n >>= 1;
    }
    return ans;
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    // 每一类的个数 (%m 分类)
    vector<i64> cnt(m);
    cnt[0] = n / m;
    for (int i = 1; i < m; i++) {
        cnt[i] = n / m + (i <= n % m);
    }

    // (x^0 + x^i)^cnt[i] 相乘
    vector<i64> ans(m);
    ans[0] = ksm(2, cnt[0]);
    for (int i = 1; i < m; i++) {
        vector<i64> res(m);
        res[0] = res[i] = 1;
        res = ksm(res, cnt[i], m);
        ans = mul(ans, res, m);
    }

    cout << (ans[0] - 1 + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}