// od[] 作为辅助数组，作为 oldsa[] / oldrk[]
// ct[] 计数，用于排序
int rk[2 * maxn], sa[maxn], ht[maxn];
struct SuffixArray {
    // n 字符串长度，m 字符集大小
    int n, m;
    int od[2 * maxn], ct[maxn];

    void sor(int k) {
        for (int i = 0; i <= m; i++) ct[i] = 0;
        for (int i = 1; i <= n; i++) od[i] = sa[i];
        for (int i = 1; i <= n; i++) ct[rk[od[i] + k]]++;
        for (int i = 1; i <= m; i++) ct[i] += ct[i - 1];
        for (int i = n; i >= 1; i--) sa[ct[rk[od[i] + k]]--] = od[i];
    }

    // 1-indexed string, max ascii in string
    void init(string &s, int _n, int _m = 128) {
        n = _n;
        m = _m;
        // 按第一个字母排序
        for (int i = 1; i <= n; i++) rk[i] = s[i];
        for (int i = n + 1; i <= 2 * n; i++) rk[i] = od[i] = 0;
        for (int i = 1; i <= n; i++) sa[i] = i;
        sor(0);
        // 倍增
        for (int k = 1; k <= n; k *= 2) {
            // 第二关键字排序
            sor(k);
            // 第一关键字排序
            sor(0);
            // 把已经能分辨出的 放进不同的桶
            for (int i = 1; i <= n; i++) od[i] = rk[i];
            m = 0;
            for (int i = 1; i <= n; i++) {
                // 如果分辨不出和前一个的差距，
                // 即 这一位 和 后k位 都一样，就和前一个放在一起。
                if (od[sa[i]] == od[sa[i - 1]] && od[sa[i] + k] == od[sa[i - 1] + k]) {
                    rk[sa[i]] = m;
                } else {
                    rk[sa[i]] = ++m;
                }
            }
            // 全部都能分开，已排好。
            if (m == n) break;
        }
        // 计算 ht[i] 代表 lcp(sa[i - 1], sa[i])
        for (int i = 1, k = 0; i <= n; i++) {
            // 第一名 ht 是 0
            if (rk[i] == 1) continue;
            // 如果上一个 ht 不是 0，按照引理这里可能会倒退 1
            if (k) k--;
            // 计算 lcp(i, j)，和 前一个计算，用 rk[i] - 1 找前一个
            int j = sa[rk[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
            ht[rk[i]] = k;
        }
    }
} sf;