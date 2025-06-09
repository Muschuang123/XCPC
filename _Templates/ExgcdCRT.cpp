// 这种题目太容易爆范围了，都用 i64 保险。求解 CRT 的过程中需要 int128。
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
    return x > 0 ? x % b : x % b + b;  // && x % b != 0
}

{
    i64 a, b, c;
    cin >> a >> b >> c;
    auto [g, x, y] = exgcd(a, b);
    if (c % g != 0) {
        cout << -1 << '\n';
        return;
    }

    a /= g, b /= g, c /= g;
    x *= c, y *= c;

    // 这里min是只最小正整数解，所以max求出来有可能是负的，说明没有正整数解。
    // x 和 y 是此消彼长的关系。
    // && x % b != 0 和 && y % a != 0 去掉的话，就可以解出 0
    i64 minx = x > 0 && x % abs(b) != 0 ? x % abs(b) : x % abs(b) + abs(b);
    i64 maxy = (c - a * minx) / b;
    i64 miny = y > 0 && y % abs(a) != 0 ? y % abs(a) : y % abs(a) + abs(a);
    i64 maxx = (c - b * miny) / a;
}

// x = a[i] (mod b[i]) (1 <= i <= n)
// 求解 x
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