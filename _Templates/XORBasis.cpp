// 给定 a ，计算 a 的线性基
// return : 0-index | params : 1-index
vector<i64> xorbasis(vector<i64> a) {
    int n = (int)a.size() - 1;
    int cur = 1;
    for (int i = 62; i >= 0; i--) {
        // 找到第一个第 i 位为 1 的行
        for (int j = cur; j <= n; j++) {
            if (a[j] >> i & 1) {
                swap(a[cur], a[j]);
                break;
            }
        }
        // 如果 cur 行第 i 位还是 0，跳过
        if (a[cur] >> i & 1 ^ 1) {
            continue;
        }
        // 消去其他行的第 i 位
        for (int j = 1; j <= n; j++) {
            if (j != cur && (a[j] >> i & 1)) {
                a[j] ^= a[cur];
            }
        }
        cur++;
        if (cur == n + 1) {
            break;
        }
    }
    // 收集并返回线性基
    vector<i64> ans;
    for (int i = 1; i < cur; i++) {
        ans.push_back(a[i]);
    }
    return ans;
}

// 可插入线性基
struct XORBasis {
    i64 bas[maxn];
    void insert(i64 x) {
        for (int i = maxn - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!bas[i]) {
                    bas[i] = x;
                    break;
                }
                x ^= bas[i];
            }
        }
    }
    i64 queryMax(i64 x = 0) { // 可提供初始数
        for (int i = maxn - 1; i >= 0; i--) {
            if (x >> i & 1 ^ 1) {
                x ^= bas[i];
            }
        }
        return x;
    }
    bool check(i64 x) { // 判断 x 是否能被异或得到
        for (int i = maxn - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!bas[i]) {
                    return false;
                }
                x ^= bas[i];
            }
        }
        return true;
    }
    void clear() {
        for (int i = 0; i < maxn; i++) {
            bas[i] = 0;
        }
    }
};
