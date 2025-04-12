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

i64 inv(i64 n) {
    return ksm(n, mod - 2);
}

i64 calc(i64 n) {
    // 直接计算 轮到Kc0操作的时候 小凯胜率不好计算
    // 计算 轮到 小凯操作的时候，小凯的胜率
    // 手玩 得到前五个的概率
    // 1   2   3   4   5
    // 1  1/2  1   1  1/2
    // 当 n > 5 时：
    // n % 5 == 1: 拿 1 个，必胜
    // n % 5 == 3: 拿 1 个，必胜
    // n % 5 == 4: 拿 4 个，必胜
    // n % 5 == 2: 拿 4 个，有 1 / 2^(n/5+1) 的概率输
    //      什么时候输？ Kc0 一直拿 1 个就会输
    // n % 5 == 0: 拿 1 个，有 1 / 2^(n/5) 的概率输
    //      什么时候输？ Kc0 一直拿 4 个就会输
    i64 t = n % 5;
    if (t == 1 || t == 3 || t == 4) {
        return 1;
    } else if (t == 2) {
        return (1 - inv(ksm(2, n / 5 + 1)) + mod) % mod;
    } else {
        return (1 - inv(ksm(2, n / 5)) + mod) % mod;
    }
}

void solve() {
    // 手玩 轮到 Kc0 操作的时候，前五个的概率：
    //  1   2   3   4   5
    // 1/2  1   1  1/2  1
    // 其余的时间，小凯可以通过控制，来得到最大胜率
    i64 n;
    cin >> n;
    if (n == 1 || n == 4) {
        cout << inv(2) << '\n';
    } else if (n == 2 || n == 5) {
        cout << 1 << '\n';
    } else if (n == 3) {
        cout << inv(4) * 3 % mod << '\n';
    } else {
        cout << (calc(n - 1) + calc(n - 4)) % mod * inv(2) % mod << '\n';
    }
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