i64 inv[maxn];
void init() {
    inv[0] = inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
}