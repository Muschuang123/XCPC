mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Hasher {
    static uint64_t f(uint64_t x) {
        x = x ^ (x << 16) ^ 0x9e3679b97f4a7c15;
        x = x ^ (x >> 8) ^ 0x94d049ba153151eb;
        x = x ^ (x << 24) ^ 0xbf58476d1ce4e5b9;
        return x ^ (x >> 32) ^ 0x13857ac66fed127e;
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t b = rng();
        return f(x + b);
    }
    // 针对 std::pair<int, int> 作为主键类型的哈希函数
    size_t operator()(const pair<uint64_t, uint64_t> &x) const {
        static const uint64_t b = rng();
        return f(x.first + b) ^
               (f(x.second + b) >> 1);
    }
};