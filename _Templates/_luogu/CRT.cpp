// 中国剩余定理
// https://www.luogu.com.cn/problem/P1495
// https://www.bilibili.com/video/BV1AN4y1N7Su
// i64 都会爆啊，逆天
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

array<i64, 3> exgcd(i64 a, i64 b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

i64 inv(i64 a, i64 b) {
    auto [g, x, y] = exgcd(a, b);
    return x > 0 ? x % b : x % b + b;
}

// CRT() = a[i] (mod b[i])
i64 CRT(vector<i64> &a, vector<i64> &b, int n) {
    i64 M = 1;
    for (int i = 1; i <= n; i++) {
        M *= b[i];
    }
    vector<i64> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = M / b[i];
        d[i] = inv(c[i], b[i]);
    }
    i64 x = 0;
    for (int i = 1; i <= n; i++) {
        x = (x + (__int128_t)a[i] * c[i] * d[i]) % M;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i] >> a[i];
    }

    i64 x = CRT(a, b, n);
    cout << x << '\n';

    return 0;
}