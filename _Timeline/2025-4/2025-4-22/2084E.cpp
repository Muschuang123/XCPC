// https://www.luogu.com.cn/article/2164egqm
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 5e3 + 3;

i64 f[maxn], g[maxn];
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

void init() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
}

inline i64 C(i64 n, i64 m) {
    if (m > n || n < 0 || m < 0) {
        return 0;
    }
    if (m == 0) {
        return 1;
    }
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n);
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1];
        if (a[i] != -1) {
            b[a[i]] = i;
        } else {
            pre[i]++;
        }
    }

    vector<i64> sec(pre[n] + 1);
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            sec[pre[r] - pre[l - 1]]++;
        }
    }
    auto dec = [&](int l, int r) {
        sec[pre[r] - pre[l - 1]]--;
    };
    
    int cnt = 0;
    i64 ans = 0;
    int cl = 0, cr = 0;
    for (int i = 0; i < n; i++) { // 计算 mex == i + 1 的情况
        if (b[i] == 0) {
            cnt++;
        } else { // 所有不包含 [min{b[j]}, max{b[j]}] (0 < j <= i) 的区间都删掉
            if (cl == 0 && cr == 0) { // 第一次有区间
                for (int l = 1; l < b[i]; l++) {
                    for (int r = l; r < b[i]; r++) {
                        dec(l, r);
                    }
                }
                for (int l = b[i] + 1; l <= n; l++) {
                    for (int r = l; r <= n; r++) {
                        dec(l, r);
                    }
                }
                cl = cr = b[i];
            } else if (b[i] > cr) { // 新增的 b[i] 是 max{b[j]} (0 < j <= i)
                for (int l = 1; l <= cl; l++) {
                    for (int r = cr; r < b[i]; r++) {
                        dec(l, r);
                    }
                }
                cr = b[i];
            } else if (b[i] < cl) { // 新增的 b[i] 是 min{b[j]} (0 < j <= i)
                for (int l = b[i] + 1; l <= cl; l++) {
                    for (int r = cr; r <= n; r++) {
                        dec(l, r);
                    }
                }
                cl = b[i];
            }
        }
        // 计算 >= cnt 的、包含 [min{b[j]}, max{b[j]}] (0 < j <= i) 区间
        for (int j = cnt; j <= pre[n]; j++) {
            ans = (ans + sec[j] * C(j, cnt) % mod * f[cnt] % mod * f[pre[n] - cnt] % mod) % mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}