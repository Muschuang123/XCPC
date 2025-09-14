// https://codeforces.com/gym/105901/problem/F
// ad-hoc 在指数上做运算，变量的单位 动态变化
// 及时剪枝，防止爆范围。
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

i64 p2[64];

void init() {
    p2[0] = 1;
    for (int i = 1; i <= 60; i++) {
        p2[i] = p2[i - 1] * 2;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, i64, greater<>> mp;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mp[b] += a;
    }

    // res 是 2^{k} 个空间，k 是随着当前的物品变化的。
    i64 res = 0, pre = 0, ans = 0;
    for (auto [b, a] : mp) {
        // 如果还有剩余空间
        if (res) {
            int gap = pre - b;
            // 差距太大，\sum{a_i} <= 1e14 < 2^{47}
            // 一旦有 res * 2^{pre - b} >= 2^{47} 
            // 剩下的就都能放下
            if (__lg(res) + gap >= 47) {
                break;
            }
            // 换算成当前的 b 能放多少个
            res *= p2[gap];
        }

        pre = b;

        // 剩余的都能放下
        if (res >= a) {
            res -= a;
            continue;
        }

        // 放不下的话，尽可能的放，然后开辟新空间
        a -= res;
        // 需要开辟 ne * 2^{b_i}
        i64 ne = (a + m - 1) / m;
        ans = (ans + ne % mod * ksm(2, b)) % mod;
        res = ne * m - a;
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