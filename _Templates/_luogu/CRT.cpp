// 中国剩余定理
// https://www.luogu.com.cn/problem/P1495
// https://www.bilibili.com/video/BV1AN4y1N7Su
// i64 都会爆啊，逆天
#include <bits/stdc++.h>
using i64 = __int128_t;
using namespace std;

istream &operator>>(istream &it, __int128_t &j) {
    string val;
    it >> val;
    reverse(val.begin(), val.end());
    __int128_t ans = 0;
    bool f = 0;
    char c = val.back();
    val.pop_back();
    for (; c < '0' || c > '9'; c = val.back(), val.pop_back()) {
        if (c == '-')
            f = 1;
        if (val.empty())
            break;
    }
    for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back()) {
        ans = ans * 10 + c - '0';
        if (val.empty())
            break;
    }
    j = f ? -ans : ans;
    return it;
}

ostream &operator<<(ostream &os, const __int128_t &j) {
    string ans;
    function<void(__int128_t)> write = [&](__int128_t x) {
        if (x < 0)
            ans += '-', x = -x;
        if (x > 9)
            write(x / 10);
        ans += x % 10 + '0';
    };
    write(j);
    return os << ans;
}

array<i64, 3> exgcd(i64 a, i64 b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

i64 inv(i64 a, i64 b) {
    auto [g, x, y] = exgcd(a, b);
    return x > 0 && x % b != 0 ? x % b : x % b + b;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    i64 M = 1;
    for (int i = 1; i <= n; i++) {
        cin >> b[i] >> a[i];
        M *= b[i];
    }

    vector<i64> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = M / b[i];
        d[i] = inv(c[i], b[i]);
    }

    i64 x = 0;
    for (int i = 1; i <= n; i++) {
        x = (x + a[i] * c[i] * d[i]) % M;
    }

    cout << x << '\n';

    return 0;
}