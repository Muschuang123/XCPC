// https://www.luogu.com.cn/problem/P1082
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 求解 a * x + b * y == gcd(a, b) 的一组(x, y)，顺便求出 gcd(a, b)
array<i64, 3> exgcd(i64 a, i64 b) {
    if (b == 0) {
        // 因为 b == 0 时，a == gcd(a, b)
        // 故 a * 1 + 0 == gcd(a, b)
        return {a, 1, 0};
    }
    // 由裴蜀定理
    // 存在 x, y 使得 a * x + b * y == gcd(a, b)
    // 存在 x', y' 使得 b * x' + a % b * y' == gcd(b, a % b)
    // 所以有 a * x + b * y == b * x' + a % b * y'
    // 即 a * x + b * y == b * x' + (a - a / b * b) * y' (取模展开)
    // 移项得 : a * (x - y') + b * (y - (x' - a / b * y')) == 0 
    // 得到的这个式子是恒成立的，不论 a, b 如何变化。
    // 故 x = y', y = x' - a / b * y' ，这就是递推式。
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

// 求 a 在 mod b 意义下的 逆元 inv(a)
// 使得 a * inv(a) == 1 (mod b)
// 当且仅当 a 与 b 互质的时候 才可以解
// 要不然 inv(a) 是什么 mod b 也不能 = 1
// 即 a * x + b * y == 1
// 则 a * x == 1 (mod b)
i64 inv(i64 a, i64 b) {
    auto [g, x, y] = exgcd(a, b);
    // x 是负的，直接提成正的。
    return x > 0 ? x % b : x % b + b; // && x % b != 0
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 a, b;
    cin >> a >> b;
    cout << inv(a, b) << '\n';

    return 0;
}