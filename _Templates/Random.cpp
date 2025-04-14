mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

// t is a random number:
t = rnd();

// the epoch of mt19937_64 is so long
// so we can generate a random array by this:
for (int i = 1; i <= 1e6; i++) {
    a[i] = rnd();
}

// 等概率的生成一个区间内的随机数
pair<int, int> ran(int l, int r) {
    return uniform_int_distribution{l, r}(rnd);
}
