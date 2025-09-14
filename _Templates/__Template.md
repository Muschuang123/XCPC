[TOC]
# 杂项
## 随机
```cpp
// 随机数生成器：
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// t is a random number:
t = rng();
// the period of mt19937_64 is so long
// so we can generate a random array by this:
for (int i = 1; i <= 1e6; i++) {
    a[i] = rng();
}
// 等概率的生成一个区间内的随机数
pair<int, int> ran(int l, int r) {
    return uniform_int_distribution{l, r}(rng);
}
```
## 离散化
```cpp
struct dicrete {
    vector<i64> a;
    void add(i64 x) {
        a.push_back(x);
    }
    int flush() {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()));
        return a.size();
    }
    int operator[](const i64 &x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
};
```
## int128流操纵
```cpp
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
```
## 三分查找
```cpp
// 寻找单峰，最大值
int l = 0, r = *max_element(a.begin() + 1, a.end()) + 1;
while (l + 1 < r) {
    int d = (r - l + 1) / 3;
    int ml = l + d;
    int mr = r - d;
    // 修改成 >= 就是最小值
    if (check(ml) <= check(mr)) {
        l = ml;
    } else {
        r = mr;
    }
}
cout << check(l) << '\n';
```
## 快速读入
```cpp
// 注意，在当前较新的 C++ 版本中，
// 使用 getchar() 的快读是无意义的，
// 只有使用 fread() 的才能提速

namespace FastRead { // 快读
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline int getc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <typename T> void Cin(T &a) {
        T ans = 0;
        bool f = 0;
        char c = getc();
        for (; c < '0' || c > '9'; c = getc()) {
            if (c == '-') f = 1;
        }
        for (; c >= '0' && c <= '9'; c = getc()) {
            ans = ans * 10 + c - '0';
        }
        a = f ? -ans : ans;
    }
    template <typename T, typename... Args> void Cin(T &a, Args &...args) {
        Cin(a), Cin(args...);
    }
    template <typename T> void write(T x) { // 注意，这里输出不带换行
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
} // namespace FastRead

using namespace FastRead;
```
## 多集维护中位数
```cpp
struct median {
    multiset<int> s1, s2;
    void balance() {
        int sz1 = s1.size(), sz2 = s2.size();
        if (sz2 > sz1 + 1) {
            int now = *s2.begin();
            s1.insert(now);
            s2.erase(s2.begin());
        } else if (sz1 > sz2) {
            int now = *s1.rbegin();
            s2.insert(now);
            s1.erase(prev(s1.end()));
        }
    }
    void insert(int x) {
        if (s2.empty()) {
            s2.insert(x);
        } else {
            int num = *s2.begin();
            if (x >= num) {
                s2.insert(x);
            } else {
                s1.insert(x);
            }
        }
        balance();
    }
    void erase(int x) {
        if (s1.count(x)) {
            s1.erase(s1.find(x));
        } else {
            s2.erase(s2.find(x));
        }
        balance();
    }
    int query() {
        return *s2.begin();
    }
};
```
## 高斯消元
```cpp
// Normal Gauss

const ld eps = 1e-8L;

// gauss(a, n).empty() : no solution or infinite solutions
vector<ld> gauss(vector<vector<ld>> a, int n) {
    for (int i = 1; i <= n; i++) {
        int fz = 0;
        for (int k = i; k <= n; k++) {
            if (fabsl(a[k][i]) > fabsl(a[fz][i])) {
                fz = k;
            }
        }
        if (fz != i) {
            swap(a[fz], a[i]);
        }
        if (fabsl(a[i][i]) < eps) {
            return {};
        }
        for (int j = n + 1; j >= i; j--) {
            a[i][j] /= a[i][i];
        }
        for (int k = i + 1; k <= n; k++) {
            for (int j = n + 1; j >= i; j--) {
                a[k][j] -= a[k][i] * a[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        }
    }
    vector<ld> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = a[i][n + 1];
    }
    return ans;
}


// -------------------------------
// Gauss-Jordan

const ld eps = 1e-8L;

// vector<vector<ld>> a(n + 1, vector<ld(n + 2));
// gauss[0] < 0 : no solution
// gauss[0] > 0 : infinite solutions
vector<ld> gauss_jordan(vector<vector<ld>> a, int n) {
    vector<ld> ans(n + 1);
    // cur 是当前处理的列
    int cur = 1;
    // i 是 主元 列 序号
    for (int i = 1; i <= n; i++) {
        int fz = cur;
        for (int k = cur + 1; k <= n; k++) {
            if (fabsl(a[k][i]) > fabsl(a[fz][i])) {
                fz = k;
            }
        }
        if (fz != cur) {
            swap(a[fz], a[cur]);
        }
        // 如果没有 非 0 主元，那么保持 cur (当前处理的行)，处理下一列
        if (fabsl(a[cur][i]) < eps) {
            continue;
        }
        for (int k = 1; k <= n; k++) {
            if (k == cur) {
                continue;
            }
            ld t = a[k][i] / a[cur][i];
            for (int j = i; j <= n + 1; j++) {
                a[k][j] -= t * a[cur][j];
            }
        }
        cur++;
    }
    if (cur <= n) {
        while (cur <= n) {
            if (fabsl(a[cur][n + 1]) > eps) {
                ans[0] = -1;
                return ans;
            }
            cur++;
        }
        ans[0] = 1;
        return ans;
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = a[i][n + 1] / a[i][i];
    }
    return ans;
}
```
## 线性基
```cpp
// 给定 a ，计算 a 的线性基
// return : 0-index | param : 1-index
// i64 可以改成 bitset，>> i & 1 改为 [i]
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
```

# 数论
## 组合数/快速幂
```cpp
// 阶乘及其逆元
i64 f[maxn], g[maxn];
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
void init() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        // g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
    g[maxn - 1] = ksm(f[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 1; i--) {
        g[i] = g[i + 1] * (i + 1) % mod;
    }
}
inline i64 C(i64 n, i64 m) {
    if (m > n || n < 0 || m < 0) {
        return 0;
    }
    if (m == 0) {
        return 1;
    }
    return f[n] * g[m] % mod * g[n - m] % mod;
}

// O(n) 递推求逆元
i64 inv[maxn];
void init() {
    inv[0] = inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
}
```
## 欧拉筛
```cpp
vector<int> pri;
bool not_prime[maxn];
// 最小质因数 | 欧拉函数 | 莫比乌斯函数
int minp[maxn], phi[maxn], mu[maxn];
void euler() {
    not_prime[0] = not_prime[1] = mu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!not_prime[i]) {
            pri.push_back(i);
            minp[i] = i;
            phi[i] = i - 1;
            mu[i] = -1;
        }
        for (int j : pri) {
            if (i * j >= maxn) {
                break;
            }
            not_prime[i * j] = true;
            minp[i * j] = j;
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                mu[i * j] = 0;
                break;
            }
            phi[i * j] = phi[i] * (j - 1);
            mu[i * j] = -mu[i];
        }
    }
}
```
## 数论分块
```cpp
for (i64 l = 1, r = 0; l <= n; l = r + 1) {
    i64 res = n / l;
    r = n / res;
    // 对于区间 [l, r] 内的所有整数 i，n / i 的结果（向下取整）都相同。
    // in [l, r] :
}

// -------------------------------------
for (int i = 1; i <= k; i++) {
    i = k / (k / i); 
    int c = k / i;
    // 此时 i * c <= k，i * c 可以构成所有的面积 <= k 的矩形
    // 这个 i 相当于上面那个 r
}
```
## 扩展欧几里得/中国剩余定理
```cpp
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
```

# 数据结构
## 并查集
```cpp
struct dsu {
    int n, cnt;
    vector<int> fa, sz;
    // Index 0 is invalid
    dsu(int _n = 0) {
        n = _n - 1;
        cnt = n;
        fa.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) fa[i] = i;
        sz.assign(n + 1, 1);
    }
    int fin(int x) {
        if (fa[x] == x) return x;
        return fa[x] = fin(fa[x]);
    }
    bool merg(int u, int v) {
        u = fin(u), v = fin(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        fa[v] = u;
        sz[u] += sz[v];
        cnt--;
        return 1;
    }
};
```
## 树状数组
```cpp
struct fenwick {
    int n;
    vector<i64> t;
    fenwick(int _n) {
        n = _n - 1;
        t.resize(n + 1);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int index, i64 delta) {
        for (int i = index; i <= n; i += lowbit(i)) {
            t[i] += delta;
        }
    }
    i64 query(int index) {
        i64 ans = 0;
        for (int i = index; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }
    i64 query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
```
## ST表
```cpp
struct SparseTable {
    int mx[maxn][25], lg[maxn];

    void build(vector<int> &a, int n) {
        lg[0] = -1;
        for (int i = 1; i <= n; i++) {
            mx[i][0] = a[i];
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = lg[r - l + 1];
        return max(mx[l][len], mx[r - (1 << len) + 1][len]);
    }
} ST;

// ---------------------------------------
// dynamic size version:

// 1-index
struct SparseTable {
    vector<vector<int>> mx;
    vector<int> a, lg;
    int n;

    // void assign(int _n) {
    SparseTable(int _n) {
        n = _n;
        a.assign(n + 1, 0);
        mx.assign(n + 1, vector<int>(__lg(n) + 2, 0));
        lg.assign(n + 1, 0);
    }

    void build() {
        lg[0] = -1;
        for (int i = 1; i <= n; i++) {
            mx[i][0] = a[i];
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = lg[r - l + 1];
        return max(mx[l][len], mx[r - (1 << len) + 1][len]);
    }
};
```
## 线段树
```cpp
struct SegTree {
    struct Node {
        int l, r, v, laz;
    } t[maxn * 4];

    int a[maxn];

    void pushup(int p) {
        auto &me = t[p];
        auto &lc = t[p << 1];
        auto &rc = t[p << 1 | 1];
        me.v = lc.v + rc.v;
    }

    void pushdown(int p) {
        auto &me = t[p];
        auto &lc = t[p << 1];
        auto &rc = t[p << 1 | 1];
        if (me.laz) {
            lc.v += me.laz * (lc.r - lc.l + 1);
            rc.v += me.laz * (rc.r - rc.l + 1);
            lc.laz += me.laz;
            rc.laz += me.laz;
            me.laz = 0;
        }
    }

    void build(int p, int l, int r) {
        auto &me = t[p];
        me.l = l, me.r = r;
        me.laz = 0;
        if (l == r) {
            me.v = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void add(int p, int l, int r, int d) {
        auto &me = t[p];
        if (l <= me.l && me.r <= r) {
            me.v += d * (me.r - me.l + 1);
            me.laz += d;
            return;
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        if (l <= mid)
            add(p << 1, l, r, d);
        if (r > mid)
            add(p << 1 | 1, l, r, d);
        pushup(p);
    }

    i64 query(int p, int l, int r) {
        auto &me = t[p];
        if (l <= me.l && me.r <= r) {
            return me.v; // 别忘了改这里
        }
        pushdown(p);
        int mid = me.l + me.r >> 1;
        i64 ans = 0;
        // if (r <= mid) { // left
        // } else if (l <= mid) { // left + right
        // } else { // right
        // }
        if (l <= mid)
            ans += query(p << 1, l, r);
        if (r > mid)
            ans += query(p << 1 | 1, l, r);
        return ans;
    }
} T;
```
## 笛卡尔树 
```cpp
// 一个元素的父亲元素 就是当前 山峰上最大的 / 当前山谷里最小的
// 左/右 孩子分别是 向 左/右 找 山谷中比它大的第一个 / 山峰上比它小的第一个
const int maxn = 1e7 + 7;
int stk[maxn], ls[maxn], rs[maxn];

// 0-index is invalid
void build(vector<i64> &w, int n) {
    int top = 0;
    for (int i = 1; i <= n; i++) {
        int k = top;                            // top 表示操作前的栈顶，k 表示当前栈顶
        while (k > 0 && w[stk[k]] > w[i]) k--;  // 维护右链上的节点
        if (k > 0) rs[stk[k]] = i;              // 栈顶元素.右儿子 := 当前元素
        if (k < top) ls[i] = stk[k + 1];        // 当前元素.左儿子 := 上一个被弹出的元素
        stk[++k] = i;                           // 当前元素入栈
        top = k;
    }
}
```
## 单调队列/滑动窗口
```cpp
deque<int> dq;
// 求最大值，单调递减的队列。
for (int i = 1; i <= n; i++) {
    while (dq.size() && a[dq.back()] >= a[i])
        dq.pop_back();
    dq.push_back(i);
    // i - k + 1 ~ i 是窗口大小
    if (dq.front() < i - k + 1)
        dq.pop_front();
    if (i >= k)
        cout << a[dq.front()] << " \n"[i == n];
}
```
## 莫队
```cpp
// https://www.luogu.com.cn/problem/P2709
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int B;
i64 res = 0;
vector<int> c;

struct Q {
    int l, r, i;
};

bool operator<(const Q &a, const Q &b) {
    if (a.l / B != b.l / B) {
        return a.l < b.l;
    } else {
        return a.r < b.r;
    }
}

inline void add(int x) {
    res -= c[x] * c[x];
    c[x]++;
    res += c[x] * c[x];
}

inline void del(int x) {
    res -= c[x] * c[x];
    c[x]--;
    res += c[x] * c[x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    B = sqrtl(n);
    c.resize(k + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Q> q(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }

    sort(q.begin() + 1, q.end());

    vector<i64> ans(m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        while (l > q[i].l) add(a[--l]);
        while (r < q[i].r) add(a[++r]);
        while (l < q[i].l) del(a[l++]);
        while (r > q[i].r) del(a[r--]);
        ans[q[i].i] = res;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
```
## 线段树实现矩形面积并
```cpp
// 矩形面积并，线段树求解。
// 区间左闭右开。
// https://www.luogu.com.cn/problem/P5490
// https://www.bilibili.com/video/BV1MX4y1Z7N5
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;

struct Line {
    int l, r, y, v;
};

bool operator<(const Line &a, const Line &b) {
    return a.y < b.y;
}

int len[maxn];

struct SegTree {
    int l, r, v, len;
} t[maxn * 8];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].v = 0;
        t[p].len = 0;
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void pushup(int p) {
    if (t[p].v)
        t[p].len = len[t[p].r + 1] - len[t[p].l];
    else
        t[p].len = t[p << 1].len + t[p << 1 | 1].len;
}

void add(int p, int l, int r, int d) {
    if (l <= t[p].l && t[p].r <= r) {
        t[p].v += d;
        pushup(p);
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid)
        add(p << 1, l, r, d);
    if (r > mid)
        add(p << 1 | 1, l, r, d);
    pushup(p);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    vector<Line> line(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        line[i].l = line[n + i].l = x;
        line[i].r = line[n + i].r = xx;
        line[i].y = y, line[n + i].y = yy;
        line[i].v = 1, line[n + i].v = -1;
        mp[x] = 0, mp[xx] = 0;
    }
    sort(line.begin() + 1, line.end());
    int cnt = 0;
    for (auto &[f, s] : mp) {
        s = ++cnt;
        len[s] = f;
    }
    cnt--;
    i64 ans = 0;
    build(1, 1, cnt);
    for (int i = 1; i <= 2 * n; i++) {
        // 每次询问区间固定 1 ~ cnt
        ans += 1LL * t[1].len * (line[i].y - line[i - 1].y);
        add(1, mp[line[i].l], mp[line[i].r] - 1, line[i].v);
    }
    cout << ans << '\n';
    return 0;
}
```

# 字符串
## 字典树
```cpp
// 默认 'a' ~ 'z'
// maxn = ∑|s| ，s 为模式串
const int Tsz = 26;
struct Trie {
    int ch[maxn][Tsz], cnt[maxn], tot;
    int mp(char c) { return c - 'a'; }
    void insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int &v = ch[u][mp(s[i])];
            if (!v) v = ++tot;
            u = v;
        }
        cnt[u]++;
    }
    int query(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = ch[u][mp(s[i])];
            if (!v) return 0;
            u = v;
        }
        return cnt[u];
    }
    void clear() {
        for (int i = 0; i <= tot; i++) {
            cnt[i] = 0;
            for (int j = 0; j < Tsz; j++) {
                ch[i][j] = 0;
            }
        }
        tot = 0;
    }
} D;
```
## 马拉车
```cpp
struct Manacher {
    // d1 奇数回文半径(不含自身),d2 偶数回文半径(abba d2[2] = 0,d2[3] = 2)
    vector<int> d1, d2;
    int n;

    // 1-indexed string
    void init(string s, int _n = 0) {
        n = _n ? _n : s.size() - 1;
        d1.assign(n + 1, 0), d2.assign(n + 1, 0);
        s[0] = '#', s.push_back('|');
        for (int i = 1, l = 1, r = 1; i <= n; i++) {
            if (i <= r) d1[i] = min(d1[r - i + l], r - i);
            while (s[i + d1[i] + 1] == s[i - d1[i] - 1]) d1[i]++;
            if (i + d1[i] > r) r = i + d1[i], l = i - d1[i];
        }
        for (int i = 2, l = 1, r = 2; i <= n; i++) {
            if (i <= r) d2[i] = min(d2[r - i + l], r - i);
            while (s[i + d2[i]] == s[i - d2[i] - 1]) d2[i]++;
            if (i + d2[i] > r) r = i + d2[i], l = i - d2[i];
        }
    }

    // 检查是否回文
    bool checkp(int l, int r) {
        if ((r - l + 1) & 1)
            return d1[(l + r) / 2] >= (r - l) / 2;
        return d2[l + (r - l + 1) / 2] >= (r - l + 1) / 2;
    }

    int getmax() {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max({ans, d1[i] * 2 + 1, d2[i] * 2});
        return ans;
    }
} ma;
```
## 后缀数组
```cpp
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
```
## AC自动机
```cpp
// 拓扑排序优化的 AC自动机
// 默认 'a' ~ 'z'
// maxn = ∑|s| ，s 为模式串
// insert() ==> build() ==> work() ==> topo()
// res[idx[i]] 为 s[i] 的答案
// dp 时注意 string 是 0-index
const int Tsz = 26;
struct Trie {
    int ch[maxn][Tsz], ne[maxn], in[maxn];
    int res[maxn], tot;
    int mp(char c) { return c - 'a'; }
    // 返回一个 idx ，用于定位答案，相同的模式串 idx 相同
    int insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int &v = ch[u][mp(s[i])];
            if (!v) {
                v = ++tot;
            }
            u = v;
        }
        return u;
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < Tsz; i++) {
            if (ch[0][i]) q.push(ch[0][i]);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < Tsz; i++) {
                int &v = ch[u][i];
                if (v) { // 有孩子，同步 ne[v] 为 ne[u] 的儿子
                    ne[v] = ch[ne[u]][i];
                    in[ne[v]]++;
                    q.push(v);
                } else { // 否则下一步就是 ne[u] 的儿子
                    v = ch[ne[u]][i];
                }
            }
        }
    }
    // work 之后， res[idx] 就是对应模式串的出现次数
    void work(const string &s) {
        // 未拓扑优化：
        // int u = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     u = ch[u][mp(s[i])];
        //     int t = u;
        //     while (t) {
        //         res[t]++;
        //     }
        // }
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            u = ch[u][mp(s[i])];
            res[u]++;
        }
    }
    void topo() {
        queue<int> q;
        for (int i = 0; i <= tot; i++) {
            if (!in[i]) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res[ne[u]] += res[u];
            if (!--in[ne[u]]) q.push(ne[u]);
        }
    }
    void clear() {
        for (int i = 0; i <= tot; i++) {
            res[i] = ne[i] = in[i] = 0;
            for (int j = 0; j < Tsz; j++) {
                ch[i][j] = 0;
            }
        }
        tot = 0;
    }
} AC;
```
## KMP
```cpp
string s1, s2;
cin >> s1 >> s2;
int n = s1.size(), m = s2.size();
s1 = " " + s1;
s2 = " " + s2;
// s1.substr(ok[i], s2.size()) == s2
vector<int> ok;

vector<int> ne(m + 1);
for (int i = 2, j = 0; i <= m; i++) {
    while (j > 0 && s2[j + 1] != s2[i]) j = ne[j];
    if (s2[j + 1] == s2[i]) j++;
    ne[i] = j;
}
for (int i = 1, j = 0; i <= n; i++) {
    while (j > 0 && s2[j + 1] != s1[i]) j = ne[j];
    if (s2[j + 1] == s1[i]) j++;
    if (j == m) {
        ok.push_back(i - j + 1);
        j = ne[j];
    }
}
```
## 字符串哈希
```cpp
struct StringHash {
    int bas = 13331, n = 0;
    vector<unsigned long long> pre;
    StringHash(int _n, int _base = 13331, string &s) {
        bas = _base;
        pre.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] * bas + s[i];
        }
    }
};
```

# 树/图
## 倍增LCA
```cpp
// 倍增 LCA | 在 main() 里面先 init() 一下，多测每次建好图 使用 lcabuild()
const int maxn = 2e5 + 5;
int root = 1;
vector<int> g[maxn];
int fa[maxn][__lg(maxn) + 1];
int dep[maxn], lg2[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= lg2[dep[u]]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto &v : g[u]) {
        if (v == f) continue;
        lcadfs(v, u);
    }
}

void lcabuild(int n) {
    for (int i = 0; i <= n; i++) {
        dep[i] = 0;
        for (int j = 0; j <= lg2[n]; j++) {
            fa[i][j] = 0;
        }
    }
    lcadfs(root, 0);
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    while (dep[x] > dep[y]) {
        x = fa[x][lg2[dep[x] - dep[y]]];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg2[dep[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}
```
## 树链剖分
```cpp
const int maxn = 
vector<int> g[maxn];
int fa[maxn];   // 父亲
int dep[maxn];  // 深度
int sz[maxn];   // 子树节点个数
int son[maxn];  // 重儿子
int top[maxn];  // 重链
int dfn[maxn];  // DFS序
int rnk[maxn];  // DFS序逆
int dfnknt = 0;
int root = 1;

void dfs1(int u, int f) {
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (auto &v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        if (!son[u] || sz[son[u]] < sz[v]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++dfnknt;
    rnk[dfnknt] = u;
    if (!son[u]) {
        return;
    }
    dfs2(son[u], t);
    for (auto &v : g[u]) {
        if (v == son[u] || v == fa[u]) {
            continue;
        }
        dfs2(v, v);
    }
}

void hldbuild(int n) {
    dfnknt = 0;
    for (int i = 0; i <= n; i++) {
        fa[i] = dep[i] = sz[i] = son[i] = top[i] = dfn[i] = rnk[i] = 0;
    }
    dfs1(root, 0);
    dfs2(root, root);
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int jump(int x, int k) {
    if (dep[x] < k)
        return -1;
    int d = dep[x] - k;
    while (dep[top[x]] > d)
        x = fa[top[x]];
    return rnk[dfn[x] - (dep[x] - d)];
}

// SegTree T;

void addseg(int x, int y, int z) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        T.add(1, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    T.add(1, dfn[y], dfn[x], z);
}

i64 queryseg(int x, int y) {
    i64 res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        res += T.query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    res += T.query(1, dfn[y], dfn[x]);
    return res;
}
```
## Tarjan强连通分量缩点
```cpp
// g: 原始图  |  h: 缩点图
vector<int> g[maxn], h[maxn];
// a: 原始点权  |  b: 缩点点权
// int a[maxn], b[maxn];

struct Tarjan {
    int n;
    int dfn[maxn], low[maxn], dfnknt;
    int stk[maxn], instk[maxn], top;
    int scc[maxn], sz[maxn], cnt;

    void tj(int x) {
        low[x] = dfn[x] = ++dfnknt;
        stk[++top] = x;
        instk[x] = 1;
        for (auto &v : g[x]) {
            if (!dfn[v]) {
                tj(v);
                low[x] = min(low[x], low[v]);
            } else if (instk[v]) {
                low[x] = min(low[x], dfn[v]);
            }
        }
        if (dfn[x] == low[x]) {
            int v;
            cnt++;
            do {
                v = stk[top--];
                instk[v] = 0;
                scc[v] = cnt;
                sz[cnt]++;
            } while (v != x);
        }
    }

    void init(int _n) {
        n = _n;
        dfnknt = cnt = 0;
        for (int i = 1; i <= n; i++) {
            dfn[i] = low[i] = 0;
            scc[i] = sz[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                tj(i);
            }
        }
    }

    void rebuild() {
        for (int i = 1; i <= cnt; i++) {
            h[i].clear();
            // b[i] = 0;
        }
        for (int x = 1; x <= n; x++) {
            // b[scc[x]] += a[x];
            for (auto &v : g[x]) {
                if (scc[x] != scc[v]) {
                    h[scc[x]].push_back(scc[v]);
                }
            }
        }
        for (int i = 1; i <= cnt; i++) {
            auto &H = h[i];
            sort(H.begin(), H.end());
            H.erase(unique(H.begin(), H.end()), H.end());
        }
    }
} tar;
```
## 树的重心
```cpp
// 没测过
vector<int> g[maxn];
int sz[maxn];
int root, mis = maxn;

void getroot(int u, int f) {
    sz[u] = 1;
    int s = 0;
    for (int v : g[u]) {
        if (v == f) continue;
        getroot(v, u);
        sz[u] += sz[v];
        s = max(s, sz[v]);
    }
    s = max(s, sum - sz[u]);
    if (s < mis) {
        mis = s;
        root = u;
    }
}
```
## 树的直径
```cpp
// 计算树的直径值 dp 法，负边权可用
vector<int> g[maxn];
int dia = 0;
int dp[maxn]; // dp[u]: 以 u 为根的子树中，从 u 出发的最长路径。
// 对于树的直径，实际上是可以通过枚举从某个节点出发不同的两条路径相加的最大值求出
// 所以 dp[u] = max(dp[u], dp[v] + w(u, v))
// 在更新 dp[u] 之前，dia = max(dia, dp[u] + dp[v] + w(u, v)) 算答案
void calcDiameter(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        calcDiameter(v, u);
        dia = max(dia, dp[u] + dp[v] + 1);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

// 找到具体的直径，负边权不可用
// 直接调用 initDiameter(int n)
// 第一次 dfs 找到最远的点
// 第二次 dfs 找出直径的两个端点
// 第三次 dfs 找到两个端点之间的连线
vector<int> g[maxn];
int dep[maxn], far1, far2;
vector<int> diaPath;
void calcDiameter(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        if (dep[far1] < dep[v]) far1 = v;
        calcDiameter(v, u);
    }
}
void findDiameter(int u, int f) {
    diaPath.push_back(u);
    if (u == far2) {
        far2 = -1;
        return;
    }
    for (int v : g[u]) {
        if (v == f) continue;
        findDiameter(v, u);
        if (far2 == -1) return;
    }
    diaPath.pop_back();
}
void initDiameter(int n) {
    diaPath.clear();
    far1 = far2 = dep[1] = 0;
    calcDiameter(1, 0);
    dep[far1] = 0;
    far2 = far1;
    calcDiameter(far1, 0);
    findDiameter(far1, 0);
}
```
## 虚树
```cpp
// 倍增 LCA | 在 main() 里面先 init() 一下，多测每次建好图 使用 lcabuild()
const int maxn = 2.5e5 + 5;
int root = 1;
vector<int> g[maxn], h[maxn];
int fa[maxn][__lg(maxn) + 1];
int dep[maxn], lg2[maxn], dfn[maxn], sz[maxn];
int dfnknt;

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    dfn[u] = ++dfnknt;
    sz[u] = 1;
    for (int i = 1; i <= lg2[dep[u]]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto &v : g[u]) {
        if (v == f) continue;
        lcadfs(v, u);
        sz[u] += sz[v];
    }
}

void lcabuild(int n) {
    dfnknt = 0;
    for (int i = 0; i <= n; i++) {
        dfn[i] = dep[i] = sz[i] = 0;
        for (int j = 0; j <= lg2[n]; j++) {
            fa[i][j] = 0;
        }
    }
    lcadfs(root, 0);
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    while (dep[x] > dep[y]) {
        x = fa[x][lg2[dep[x] - dep[y]]];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg2[dep[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

// vector<int> h[maxn];
{ // main() / solve()
    auto cmp = [&](const int &a, const int &b) {
        return dfn[a] < dfn[b];
    };

    // k 个虚树，i-th 虚树的关键点存在 b[i] 中
    for (int i = 1; i <= k; i++) {
        auto &vec = b[i];
        sort(vec.begin(), vec.end(), cmp);
        int sz = vec.size();
        for (int j = 1; j < sz; j++) {
            vec.push_back(LCA(vec[j - 1], vec[j]));
        }
        sort(vec.begin(), vec.end(), cmp);
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        // vec[0] 是 root
        for (int j = 1; j < vec.size(); j++) {
            int u = vec[j - 1], v = vec[j];
            int lca = LCA(u, v);
            h[lca].push_back(v);
            h[v].push_back(lca);
        }

        // operation...

        for (int j = 0; j < vec.size(); j++) {
            h[vec[j]].clear();
        }
    }
}
```
## 点分治
```cpp
// O(nQlogn)
const int maxn =
    const int ran = 1e7 + 7; // 值域
vector<pair<int, int>> g[maxn];
int del[maxn]; // 节点是否被删除
int sz[maxn];  // 以当前节点为根树大小
int mis;       // 最小的 max(所有子树大小)
int sum;       // 当前子树的所有节点数
int root;      // 当前的根
int bu[ran];   // 信息 桶
int res[maxn]; // 已有点到重心的 信息
int tot;       // 点到重心的距离个数
int n, Q;      // n 个点，Q 次询问
int ask[maxn]; // Q 次询问内容
int ans[maxn]; // Q 次答案

void getroot(int u, int f) {
    sz[u] = 1;
    int s = 0;
    for (auto [v, w] : g[u]) {
        if (f == v || del[v]) {
            continue;
        }
        getroot(v, u);
        sz[u] += sz[v];
        s = max(s, sz[v]);
    }
    s = max(s, sum - sz[u]);
    if (s < mis) {
        mis = s;
        root = u;
    }
}

void getres(int u, int f, int d) {
    res[++tot] = d;
    for (auto [v, w] : g[u]) {
        if (v == f || del[v]) {
            continue;
        }
        getres(v, u, d + w);
    }
}

void calc(int u) {
    // 计算经过根 u 的路径
    del[u] = bu[0] = 1;
    queue<int> q;
    for (auto [v, w] : g[u]) {
        if (del[v]) {
            continue;
        }
        // 子树 v 各点 到 u 的 信息
        tot = 0;
        getres(v, u, w);
        // 枚举 信息 和询问，判定答案
        for (int i = 1; i <= tot; i++) {
            for (int j = 1; j <= Q; j++) {
                if (ask[j] >= res[i]) {
                    // 计算信息
                    ans[j] |= bu[ask[j] - res[i]];
                }
            }
        }
        // 记录这个子树的合法距离，让其他子树对着枚举
        for (int i = 1; i <= tot; i++) {
            if (res[i] < ran) {
                q.push(res[i]);
                bu[res[i]] = 1;
            }
        }
    }
    // 清空所有信息
    while (!q.empty()) {
        bu[q.front()] = 0;
        q.pop();
    }

    // 对 u 的子树继续分治
    for (auto [v, w] : g[u]) {
        if (del[v]) {
            continue;
        }
        mis = sum = sz[v];
        getroot(v, 0);
        calc(root);
    }
}

// main():
{
    cin >> n >> Q;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= Q; i++) {
        cin >> ask[i];
    }
    mis = sum = n;
    getroot(1, 0);
    calc(root);
    for (int i = 1; i <= Q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}
```
## 欧拉路径(有向)
```cpp
struct EulerPath {
    vector<int> g[maxn];
    int indeg[maxn], outdeg[maxn];
    int val[maxm];
    bool vis[maxm];
    vector<int> vpa, epa;
    vector<pair<int, int>> e;

    int n, m;
    void init(int _n, int _m) {
        n = _n, m = _m;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            indeg[i] = outdeg[i] = 0;
        }
        for (int i = 0; i <= m; i++) {
            val[i] = vis[i] = 0;
        }
        vpa.clear();
        epa.clear();
        e.assign(m + 1, {0, 0});
    }
    // 1-index id
    void add(int x, int y, int id) {
        g[x].push_back(id);
        val[id] = x ^ y;
        outdeg[x]++;
        indeg[y]++;
        e[id] = {x, y};
    }

    void dfs(int x) {
        vector<int> stk;
        stk.push_back(x);
        while (!stk.empty()) {
            x = stk.back();
            while (!g[x].empty()) {
                int id = g[x].back();
                g[x].pop_back();
                if (!vis[id]) {
                    vis[id] = true;
                    x = val[id] ^ x;
                    stk.push_back(x);
                }
            }
            vpa.push_back(x);
            stk.pop_back();
        }
    }

    bool work(int st = 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] != outdeg[i]) {
                if (indeg[i] < outdeg[i]) {
                    st = i;
                }
                cnt += abs(indeg[i] - outdeg[i]);
                if (cnt > 2) {
                    return false;
                }
            }
        }
        dfs(st);
        bool isepa = (vpa.size() == m + 1);
        if (isepa) {
            map<i64, vector<int>> mp;
            for (int i = 1; i < e.size(); i++) {
                i64 x = e[i].first, y = e[i].second;
                i64 ke = x << 32 | y;
                mp[ke].push_back(i);
            }
            reverse(vpa.begin(), vpa.end());
            for (int i = 1; i < vpa.size(); i++) {
                i64 x = vpa[i - 1], y = vpa[i];
                i64 ke = x << 32 | y;
                epa.push_back(mp[ke].back());
                mp[ke].pop_back();
            }
        }
        return isepa;
    }
} ep;
```
## 欧拉路径(无向)
```cpp
struct EulerPath {
    vector<int> g[maxn];
    int deg[maxn];
    int val[maxm];
    bool vis[maxm];
    vector<int> vpa, epa;
    vector<pair<int, int>> e;

    int n, m;
    void init(int _n, int _m) {
        n = _n, m = _m;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            deg[i] = 0;
        }
        for (int i = 0; i <= m; i++) {
            val[i] = vis[i] = 0;
        }
        vpa.clear();
        epa.clear();
        e.assign(m + 1, {0, 0});
    }
    // 1-index id
    void add(int x, int y, int id) {
        g[x].push_back(id);
        g[y].push_back(id);
        val[id] = x ^ y;
        deg[x] ^= 1;
        deg[y] ^= 1;
        e[id] = {x, y};
    }
    void dfs(int x) {
        vector<int> stk;
        stk.push_back(x);
        while (!stk.empty()) {
            x = stk.back();
            while (!g[x].empty()) {
                int id = g[x].back();
                g[x].pop_back();
                if (!vis[id]) {
                    vis[id] = true;
                    x = val[id] ^ x;
                    stk.push_back(x);
                }
            }
            vpa.push_back(x);
            stk.pop_back();
        }
    }

    bool work(int st = 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                st = i;
                cnt++;
                if (cnt > 2) {
                    return false;
                }
            }
        }
        dfs(st);
        bool isepa = (vpa.size() == m + 1);
        if (isepa) {
            map<i64, vector<int>> mp;
            for (int i = 1; i < e.size(); i++) {
                i64 x = e[i].first, y = e[i].second;
                i64 ke = min(x, y) << 32 | max(x, y);
                mp[ke].push_back(i);
            }
            for (int i = 1; i < vpa.size(); i++) {
                i64 x = vpa[i - 1], y = vpa[i];
                i64 ke = min(x, y) << 32 | max(x, y);
                epa.push_back(mp[ke].back());
                mp[ke].pop_back();
            }
        }
        return isepa;
    }
} ep;
```
## Tarjan求割点
```cpp
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e4 + 4;
vector<int> g[maxn];
// low[u]​​：表示 u 或其子树中的节点通过最多一条回边（非树边）能追溯到的最小时间戳
// 多测必须清空这几个数组。
int dfn[maxn], low[maxn], cut[maxn];
int root = 1;
int dfnknt = 0;

void tj(int x) {
    dfn[x] = low[x] = ++dfnknt;
    int child = 0;
    for (auto &v : g[x]) {
        if (dfn[v]) {  // 已访问，是 dfn 更小的节点，直接从这个点转移 dfn
            low[x] = min(low[x], dfn[v]);
        } else {  // 未访问，属于 x 的子树，在 dfs 后 更新 low[x]
            tj(v);
            low[x] = min(low[x], low[v]);
            if (low[v] >= dfn[x]) {  // 这表明不通过 x，v 根本回不去
                child++;
                // 不是根节点 or 有超过两个孩子
                if (x != root || child > 1) {
                    cut[x] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tj(i);
        }
    }

    cout << count(cut + 1, cut + 1 + n, 1) << '\n';
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}
```
## Tarjan求割边
```cpp
// 这个板子没找到地方测。
// 可以参考：
// https://codeforces.com/contest/1986/problem/F
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 5e4 + 4;
vector<int> g[maxn];
// low[u]​​：表示 u 或其子树中的节点通过最多一条回边（非树边）能追溯到的最小时间戳
// 多测必须清空这几个数组。
int dfn[maxn], low[maxn], cut[maxn];
int ans, dfnknt, root = 1;

void tj(int u, int f) {
    dfn[u] = low[u] = ++dfnknt;
    int child = 0;
    for (auto &v : g[u]) {
        if (dfn[v] && v != f) {  // 已访问，是 dfn 更小的节点，直接从这个点转移 dfn
            low[u] = min(low[u], dfn[v]);
        } else if (!dfn[v]) {  // 未访问，属于 u 的子树，在 dfs 后 更新 low[u]
            tj(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {  // 这表明不通过 x，v 根本回不去
                child++;
                // 不是根节点 or 有超过两个孩子
                if (u != root || child > 1) {
                    ans++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tj(i, 0);
        }
    }

    cout << ans << '\n';

    return 0;
}
```
## 链式前向星建图
```cpp
// 注意边数要开两倍，存无向图
const int maxn = 2e5 + 5;

struct edge {
    int ne, to;
    // int w; (边权)
} g[maxn];

int head[maxn];

int eknt = 0;
void adde(int u, int v /*, int w*/) {
    eknt++;
    g[eknt].to = v;
    g[eknt].ne = head[u];
    // g[eknt].w = w;
    head[u] = eknt;
}

// dfs():
for (int i = head[v]; i; i = g[i].ne) {
    int v = g[i].to;
}
```

# SG函数
SG值是 0 的时候是必败态。
一个状态的SG值 = mex { 所有后继状态的SG值 }

# 高精度
```cpp
const int base = 1000000000;
const int base_digits = 9; // 分解为九个数位一个数字
struct bigint {
    vector<int> a;
    int sign;
    bigint() : sign(1) {}
    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }
    bigint(long long v) {
        *this = v;
    }
    bigint(const string &s) {
        read(s);
    }
    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }
    void check(int v) { // 检查输入的是否为负数
        if (v < 0) {
            sign = -sign;
            v = -v;
        }
    }
    void trim() { // 去除前导零
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
    bool isZero() const { // 判断是否等于零
        return a.empty() || (a.size() == 1 && !a[0]);
    }
    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }
    void operator=(long long v) {
        a.clear();
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base) {
            a.push_back(v % base);
        }
    }
    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(int v) {
        check(v);
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i) {
            if (i == (int)a.size()) {
                a.push_back(0);
            }
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
        }
        trim();
    }
    void operator/=(int v) {
        check(v);
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long)base;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }
    void operator%=(const int &v) {
        *this = *this % v;
    }
    // 基础加减乘除
    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;
            for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int)res.a.size()) {
                    res.a.push_back(0);
                }
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry) {
                    res.a[i] -= base;
                }
            }
            return res;
        }
        return *this - (-v);
    }
    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) {
                        res.a[i] += base;
                    }
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }
    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }
    int operator%(int v) const {
        if (v < 0) {
            v = -v;
        }
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            m = (a[i] + m * (long long)base) % v;
        }
        return m * sign;
    }
    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }
    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }
    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream &operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
    /* 大整数乘除大整数部分 */
    typedef vector<long long> vll;
    bigint operator*(const bigint &v) const { // 大整数乘大整数
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int)c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int)(cur % 1000000));
            carry = (int)(cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) { // 大整数除大整数，同时返回答案与余数
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long)base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back((int)(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i + j] += a[i] * b[j];
                }
            }
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int)a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int)r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }
    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }
    void operator%=(const bigint &v) {
        *this = *this % v;
    }
};
```

# 计算几何
## 二维全集
```cpp
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

// 有浮点数但是大部分都是 i64 时，可以选择用 pair<ld, ld> 替换必需内容
// 然后删去强制浮点数的函数，改用手写 pair<ld, ld> 替代。
using T = ld; // 全局数据类型

const T eps = 1e-12;
const T INF = numeric_limits<T>::max();
const T PI = acosl(-1);
#define setp(x) cout << fixed << setprecision(x)

// 点与向量
struct Pt {
    T x, y;
    bool operator==(const Pt &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    bool operator!=(const Pt &a) const { return !(*this == a); }
    bool operator<(const Pt &a) const {
        if (abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }
    bool operator>(const Pt &a) const { return !(*this < a || *this == a); }
    Pt operator+(const Pt &a) const { return {x + a.x, y + a.y}; }
    Pt operator-(const Pt &a) const { return {x - a.x, y - a.y}; }
    Pt operator-() const { return {-x, -y}; }
    Pt operator*(const T k) const { return {k * x, k * y}; }
    Pt operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const Pt &a) const { return x * a.x + y * a.y; } // 点积
    T operator^(const Pt &a) const { return x * a.y - y * a.x; } // 叉积，注意优先级
    int toleft(const Pt &a) const {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    } // to-left 测试
    T len2() const { return (*this) * (*this); }               // 向量长度的平方
    T dis2(const Pt &a) const { return (a - (*this)).len2(); } // 两点距离的平方
    // 0:原点 | 1:x轴正 | 2:第一象限
    // 3:y轴正 | 4:第二象限 | 5:x轴负
    // 6:第三象限 | 7:y轴负 | 8:第四象限
    int quad() const {
        if (abs(x) <= eps && abs(y) <= eps) return 0;
        if (abs(y) <= eps) return x > eps ? 1 : 5;
        if (abs(x) <= eps) return y > eps ? 3 : 7;
        return y > eps ? (x > eps ? 2 : 4) : (x > eps ? 8 : 6);
    }
    // i64 + pair<ld, ld>
    // ld dis(const pair<ld, ld> &a) { return sqrtl((a.first - x) * (a.first - x) + (a.second - y) * (a.second - y)); }
    // 必须用浮点数
    T len() const { return sqrtl(len2()); }                                                              // 向量长度
    T dis(const Pt &a) const { return sqrtl(dis2(a)); }                                                  // 两点距离
    T ang(const Pt &a) const { return acosl(max(-1.0L, min(1.0L, ((*this) * a) / (len() * a.len())))); } // 向量夹角
    Pt rot(const T rad) const { return {x * cosl(rad) - y * sinl(rad), x * sinl(rad) + y * cosl(rad)}; }     // 逆时针旋转（给定角度）
    Pt rot(const T cosr, const T sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; }      // 逆时针旋转（给定角度的正弦与余弦）
};

// 极角排序
struct Argcmp {
    bool operator()(const Pt &a, const Pt &b) const {
        const int qa = a.quad(), qb = b.quad();
        if (qa != qb) return qa < qb;
        const auto t = a ^ b;
        // 不同长度的向量需要分开
        // if (abs(t) <= eps) return a * a < b * b - eps;
        return t > eps;
    }
};

// 直线
struct Lt {
    Pt p, v; // p 为直线上一点，v 为方向向量
    bool operator==(const Lt &a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
    int toleft(const Pt &a) const { return v.toleft(a - p); } // to-left 测试
    // 半平面交算法定义的排序
    bool operator<(const Lt &a) const {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
        return Argcmp()(v, a.v);
    }
    // i64 + pair<ld, ld>
    // pair<ld, ld> inter(const Lt &a) const {
    //     ld k = 1.0L * (a.v ^ (p - a.p)) / (v ^ a.v);
    //     return {p.x + v.x * k, p.y + v.y * k};
    // }
    // 必须用浮点数
    Pt inter(const Lt &a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); } // 直线交点
    T dis(const Pt &a) const { return abs(v ^ (a - p)) / v.len(); }                 // 点到直线距离
    Pt pedal(const Pt &a) const { return p + v * ((v * (a - p)) / (v * v)); }       // 点在直线上的投影
};

// 线段
struct St {
    Pt a, b;
    bool operator<(const St &s) const { return make_pair(a, b) < make_pair(s.a, s.b); }
    // 判定性函数建议在整数域使用
    // 判断点是否在线段上
    // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
    int is_on(const Pt &p) const {
        if (p == a || p == b) return -1;
        return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
    }
    // 判断线段直线是否相交
    // -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
    int is_inter(const Lt &l) const {
        if (l.toleft(a) == 0 || l.toleft(b) == 0) return -1;
        return l.toleft(a) != l.toleft(b);
    }
    // 判断两线段是否相交
    // -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
    int is_inter(const St &s) const {
        if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
        const Lt l{a, b - a}, ls{s.a, s.b - s.a};
        return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
    }
    // 点到线段距离（必须用浮点数）
    T dis(const Pt &p) const {
        if ((p - a) * (b - a) < -eps || (p - b) * (a - b) < -eps) return min(p.dis(a), p.dis(b));
        const Lt l{a, b - a};
        return l.dis(p);
    }
    // 两线段间距离（必须用浮点数）
    T dis(const St &s) const {
        if (is_inter(s)) return 0;
        return min({dis(s.a), dis(s.b), s.dis(a), s.dis(b)});
    }
    // 计算线段的中垂线
    Lt midperp() const {
        Pt mid = (a + b) / 2; // 线段中点
        Pt vec = b - a;
        return {mid, mid + Pt{-vec.y, vec.x} - mid};
    }
};

// 多边形
struct Polygon {
    vector<Pt> p; // 以逆时针顺序存储
    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
    // 回转数
    // 返回值第一项表示点是否在多边形边上
    // 对于狭义多边形，回转数为 0 表示点在多边形外，否则点在多边形内
    pair<bool, int> winding(const Pt &a) const {
        int cnt = 0;
        for (size_t i = 0; i < p.size(); i++) {
            const Pt u = p[i], v = p[nxt(i)];
            if (abs((a - u) ^ (a - v)) <= eps && (a - u) * (a - v) <= eps) return {true, 0};
            if (abs(u.y - v.y) <= eps) continue;
            const Lt uv = {u, v - u};
            if (u.y < v.y - eps && uv.toleft(a) <= 0) continue;
            if (u.y > v.y + eps && uv.toleft(a) >= 0) continue;
            if (u.y < a.y - eps && v.y >= a.y - eps) cnt++;
            if (u.y >= a.y - eps && v.y < a.y - eps) cnt--;
        }
        return {false, cnt};
    }
    // 多边形面积的两倍
    // 可用于判断点的存储顺序是顺时针或逆时针
    T area() const {
        T sum = 0;
        for (size_t i = 0; i < p.size(); i++) sum += p[i] ^ p[nxt(i)];
        return sum;
    }
    // 多边形的周长
    T circ() const {
        T sum = 0;
        for (size_t i = 0; i < p.size(); i++) sum += p[i].dis(p[nxt(i)]);
        return sum;
    }
};

// 凸多边形
struct Convex : Polygon {
    // 闵可夫斯基和
    Convex operator+(const Convex &c) const {
        const auto &p = this->p;
        vector<St> e1(p.size()), e2(c.p.size()), edge(p.size() + c.p.size());
        vector<Pt> res;
        res.reserve(p.size() + c.p.size());
        const auto cmp = [](const St &u, const St &v) { return Argcmp()(u.b - u.a, v.b - v.a); };
        for (size_t i = 0; i < p.size(); i++) e1[i] = {p[i], p[this->nxt(i)]};
        for (size_t i = 0; i < c.p.size(); i++) e2[i] = {c.p[i], c.p[c.nxt(i)]};
        rotate(e1.begin(), min_element(e1.begin(), e1.end(), cmp), e1.end());
        rotate(e2.begin(), min_element(e2.begin(), e2.end(), cmp), e2.end());
        merge(e1.begin(), e1.end(), e2.begin(), e2.end(), edge.begin(), cmp);
        const auto check = [](const vector<Pt> &res, const Pt &u) {
            const auto back1 = res.back(), back2 = *prev(res.end(), 2);
            return (back1 - back2).toleft(u - back1) == 0 && (back1 - back2) * (u - back1) >= -eps;
        };
        auto u = e1[0].a + e2[0].a;
        for (const auto &v : edge) {
            while (res.size() > 1 && check(res, u)) res.pop_back();
            res.push_back(u);
            u = u + v.b - v.a;
        }
        if (res.size() > 1 && check(res, res[0])) res.pop_back();
        return {res};
    }
    // 旋转卡壳
    // 例：凸多边形的直径的平方
    T rotcaliper() const {
        const auto &p = this->p;
        if (p.size() == 1) return 0;
        if (p.size() == 2) return p[0].dis2(p[1]);
        const auto area = [](const Pt &u, const Pt &v, const Pt &w) { return (w - u) ^ (w - v); };
        T ans = 0;
        for (size_t i = 0, j = 1; i < p.size(); i++) {
            const auto nxti = this->nxt(i);
            ans = max({ans, p[j].dis2(p[i]), p[j].dis2(p[nxti])});
            while (area(p[this->nxt(j)], p[i], p[nxti]) >= area(p[j], p[i], p[nxti])) {
                j = this->nxt(j);
                ans = max({ans, p[j].dis2(p[i]), p[j].dis2(p[nxti])});
            }
        }
        return ans;
    }
    // 最小矩形覆盖 O(n)，返回面积和矩形端点（必须用浮点数）
    // 矩形端点按逆时针给出。
    pair<T, vector<Pt>> min_rectangle_cover() const {
        const auto &p = this->p;
        if (p.size() == 1) return {0, {}};
        if (p.size() == 2) return {0, {}};
        const auto dot = [&](const size_t u, const size_t v, const size_t w) { return (p[v] - p[u]) * (p[w] - p[u]); };
        const auto cross = [&](const size_t u, const size_t v, const size_t w) { return (p[v] - p[u]) ^ (p[w] - p[u]); };
        size_t u = 1, d = 1;
        T mu = INF, md = -INF;
        for (size_t i = 0; i < p.size(); i++) {
            if (mu >= dot(0, 1, i)) {
                mu = dot(0, 1, i);
                u = i;
            }
            if (md <= dot(0, 1, i)) {
                md = dot(0, 1, i);
                d = i;
            }
        }
        T ans = INF;
        vector<Pt> rec(4);
        for (size_t l = 0, r = 1; l < p.size(); l++) {
            const auto nxtl = this->nxt(l);
            while (cross(l, nxtl, r) <= cross(l, nxtl, this->nxt(r))) r = this->nxt(r);
            while (dot(l, nxtl, u) >= dot(l, nxtl, this->nxt(u))) u = this->nxt(u);
            while (dot(l, nxtl, d) <= dot(l, nxtl, this->nxt(d))) d = this->nxt(d);
            Lt mid = St{p[l], p[nxtl]}.midperp();
            Lt L = {p[l], p[nxtl] - p[l]};
            Lt R = {p[r], p[nxtl] - p[l]};
            T res = L.dis(p[r]) * (mid.dis(p[u]) + mid.dis(p[d]));
            if (ans > res) {
                ans = res;
                rec[0] = L.pedal(p[u]);
                rec[1] = L.pedal(p[d]);
                rec[2] = R.pedal(p[d]);
                rec[3] = R.pedal(p[u]);
            }
        }
        return {ans, rec};
    }
    // 判断点是否在凸多边形内
    // 复杂度 O(logn)
    // -1 点在多边形边上 | 0 点在多边形外 | 1 点在多边形内
    int is_in(const Pt &a) const {
        const auto &p = this->p;
        if (p.size() == 1) return a == p[0] ? -1 : 0;
        if (p.size() == 2) return St{p[0], p[1]}.is_on(a) ? -1 : 0;
        if (a == p[0]) return -1;
        if ((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0]) == 1) return 0;
        const auto cmp = [&](const Pt &u, const Pt &v) { return (u - p[0]).toleft(v - p[0]) == 1; };
        const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
        if (i == 1) return St{p[0], p[i]}.is_on(a) ? -1 : 0;
        if (i == p.size() - 1 && St{p[0], p[i]}.is_on(a)) return -1;
        if (St{p[i - 1], p[i]}.is_on(a)) return -1;
        return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
    }
    // 求点在凸多边形上的两侧的点，逆时针给出下标
    // 必须保证 is_in(a) == -1
    pair<size_t, size_t> around_points(const Pt &a) const {
        const auto &p = this->p;
        if (a == p[0]) return {p.size() - 1, 1};
        if (St{p.back(), p[0]}.is_on(a) == 1) return {p.size() - 1, 0};
        if (St{p[0], p[1]}.is_on(a) == 1) return {0, 1};
        const auto cmp = [&](const Pt &u, const Pt &v) { return (u - p[0]).toleft(v - p[0]) == 1; };
        const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
        if (St{p[this->pre(i)], p[i]}.is_on(a) == -1) return {pre(i), nxt(i)};
        return {this->pre(i), i};
    }
    // 凸多边形关于某一方向的极点
    // 复杂度 O(logn)
    // 参考资料：https://codeforces.com/blog/entry/48868
    // 凸包点数 >= 3
    template <typename F>
    size_t extreme(const F &dir) const {
        const auto &p = this->p;
        const auto check = [&](const size_t i) { return dir(p[i]).toleft(p[this->nxt(i)] - p[i]) >= 0; };
        const auto dir0 = dir(p[0]);
        const auto check0 = check(0);
        if (!check0 && check(p.size() - 1)) return 0;
        const auto cmp = [&](const Pt &v) {
            const size_t vi = &v - p.data();
            if (vi == 0) return 1;
            const auto checkv = check(vi);
            const auto t = dir0.toleft(v - p[0]);
            if (vi == 1 && checkv == check0 && t == 0) return 1;
            return checkv ^ (checkv == check0 && t <= 0);
        };
        return partition_point(p.begin(), p.end(), cmp) - p.begin();
    }
    // 过凸多边形外一点求凸多边形的切线，逆时针返回切点下标
    // 复杂度 O(logn)
    // 必须保证 点不在多边形内
    // 凸多边形上返回两侧的点
    // 凸包点数 >= 3
    pair<size_t, size_t> tangent(const Pt &a) const {
        if (is_in(a) == -1) return around_points(a);
        const size_t i = extreme([&](const Pt &u) { return u - a; });
        const size_t j = extreme([&](const Pt &u) { return a - u; });
        return {i, j};
    }
    // 求平行于给定直线的凸多边形的切线，返回切点下标
    // 复杂度 O(logn)
    // 凸包点数 >= 3
    pair<size_t, size_t> tangent(const Lt &a) const {
        const size_t i = extreme([&](...) { return a.v; });
        const size_t j = extreme([&](...) { return -a.v; });
        return {i, j};
    }
};

// 圆 用浮点数
struct Circle {
    Pt c;
    T r;
    bool operator==(const Circle &a) const { return c == a.c && abs(r - a.r) <= eps; }
    T circ() const { return 2 * PI * r; } // 周长
    T area() const { return PI * r * r; } // 面积
    // 点与圆的关系
    // -1 圆上 | 0 圆外 | 1 圆内
    int is_in(const Pt &p) const {
        const T d = p.dis(c);
        return abs(d - r) <= eps ? -1 : d < r - eps;
    }
    // 直线与圆关系
    // 0 相离 | 1 相切 | 2 相交
    int relation(const Lt &l) const {
        const T d = l.dis(c);
        if (d > r + eps) return 0;
        if (abs(d - r) <= eps) return 1;
        return 2;
    }
    // 圆与圆关系
    // -1 相同 | 0 相离 | 1 外切 | 2 相交 | 3 内切 | 4 内含
    int relation(const Circle &a) const {
        if (*this == a) return -1;
        const T d = c.dis(a.c);
        if (d > r + a.r + eps) return 0;
        if (abs(d - r - a.r) <= eps) return 1;
        if (abs(d - abs(r - a.r)) <= eps) return 3;
        if (d < abs(r - a.r) - eps) return 4;
        return 2;
    }
    // 直线与圆的交点
    vector<Pt> inter(const Lt &l) const {
        const T d = l.dis(c);
        const Pt p = l.pedal(c);
        const int t = relation(l);
        if (t == 0) return vector<Pt>();
        if (t == 1) return vector<Pt>{p};
        const T k = sqrt(r * r - d * d);
        return vector<Pt>{p - (l.v / l.v.len()) * k, p + (l.v / l.v.len()) * k};
    }
    // 圆与圆交点
    vector<Pt> inter(const Circle &a) const {
        const T d = c.dis(a.c);
        const int t = relation(a);
        if (t == -1 || t == 0 || t == 4) return vector<Pt>();
        Pt e = a.c - c;
        e = e / e.len() * r;
        if (t == 1 || t == 3) {
            if (r * r + d * d - a.r * a.r >= -eps) return vector<Pt>{c + e};
            return vector<Pt>{c - e};
        }
        const T costh = (r * r + d * d - a.r * a.r) / (2 * r * d), sinth = sqrt(1 - costh * costh);
        return vector<Pt>{c + e.rot(costh, -sinth), c + e.rot(costh, sinth)};
    }
    // 圆与圆交面积
    T inter_area(const Circle &a) const {
        const T d = c.dis(a.c);
        const int t = relation(a);
        if (t == -1) return area();
        if (t < 2) return 0;
        if (t > 2) return min(area(), a.area());
        const T costh1 = (r * r + d * d - a.r * a.r) / (2 * r * d), costh2 = (a.r * a.r + d * d - r * r) / (2 * a.r * d);
        const T sinth1 = sqrt(1 - costh1 * costh1), sinth2 = sqrt(1 - costh2 * costh2);
        const T th1 = acos(costh1), th2 = acos(costh2);
        return r * r * (th1 - costh1 * sinth1) + a.r * a.r * (th2 - costh2 * sinth2);
    }
    // 过圆外一点圆的切线
    vector<Lt> tangent(const Pt &a) const {
        const int t = is_in(a);
        if (t == 1) return vector<Lt>();
        if (t == -1) {
            const Pt v = {-(a - c).y, (a - c).x};
            return vector<Lt>{{a, v}};
        }
        Pt e = a - c;
        e = e / e.len() * r;
        const T costh = r / c.dis(a), sinth = sqrt(1 - costh * costh);
        const Pt t1 = c + e.rot(costh, -sinth), t2 = c + e.rot(costh, sinth);
        return vector<Lt>{{a, t1 - a}, {a, t2 - a}};
    }
    // 两圆的公切线 
    vector<Lt> tangent(const Circle &a) const {
        const int t = relation(a);
        vector<Lt> lines;
        if (t == -1 || t == 4) return lines;
        if (t == 1 || t == 3) {
            const Pt p = inter(a)[0], v = {-(a.c - c).y, (a.c - c).x};
            lines.push_back({p, v});
        }
        const T d = c.dis(a.c);
        const Pt e = (a.c - c) / (a.c - c).len();
        if (t <= 2) {
            const T costh = (r - a.r) / d, sinth = sqrt(1 - costh * costh);
            const Pt d1 = e.rot(costh, -sinth), d2 = e.rot(costh, sinth);
            const Pt u1 = c + d1 * r, u2 = c + d2 * r, v1 = a.c + d1 * a.r, v2 = a.c + d2 * a.r;
            lines.push_back({u1, v1 - u1});
            lines.push_back({u2, v2 - u2});
        }
        if (t == 0) {
            const T costh = (r + a.r) / d, sinth = sqrt(1 - costh * costh);
            const Pt d1 = e.rot(costh, -sinth), d2 = e.rot(costh, sinth);
            const Pt u1 = c + d1 * r, u2 = c + d2 * r, v1 = a.c - d1 * a.r, v2 = a.c - d2 * a.r;
            lines.push_back({u1, v1 - u1});
            lines.push_back({u2, v2 - u2});
        }
        return lines;
    }
    // 圆的反演
    // auto result = circle.inverse(line);
    // if (std::holds_alternative<Circle>(result))
    // Circle c = std::get<Circle>(result);
    std::variant<Circle, Lt> inverse(const Lt &l) const {
        if (l.toleft(c) == 0) return l;
        const Pt v = l.toleft(c) == 1 ? Pt{l.v.y, -l.v.x} : Pt{-l.v.y, l.v.x};
        const T d = r * r / l.dis(c);
        const Pt p = c + v / v.len() * d;
        return Circle{(c + p) / 2, d / 2};
    }
    std::variant<Circle, Lt> inverse(const Circle &a) const {
        const Pt v = a.c - c;
        if (a.is_in(c) == -1) {
            const T d = r * r / (a.r + a.r);
            const Pt p = c + v / v.len() * d;
            return Lt{p, {-v.y, v.x}};
        }
        if (c == a.c) return Circle{c, r * r / a.r};
        const T d1 = r * r / (c.dis(a.c) - a.r), d2 = r * r / (c.dis(a.c) + a.r);
        const Pt p = c + v / v.len() * d1, q = c + v / v.len() * d2;
        return Circle{(p + q) / 2, p.dis(q) / 2};
    }
};

// 点集的凸包
// Andrew 算法，复杂度 O(nlogn)
Convex convexhull(vector<Pt> p) {
    vector<Pt> st;
    if (p.size() <= 2) return Convex{p};
    sort(p.begin(), p.end());
    const auto check = [](const vector<Pt> &st, const Pt &u) {
        const auto back1 = st.back(), back2 = *prev(st.end(), 2);
        return (back1 - back2).toleft(u - back1) <= 0;
    };
    for (const Pt &u : p) {
        while (st.size() > 1 && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    size_t k = st.size();
    p.pop_back();
    reverse(p.begin(), p.end());
    for (const Pt &u : p) {
        while (st.size() > k && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    st.pop_back();
    return Convex{st};
}

// 最小圆覆盖 | 期望 O(n) | 必须用浮点数
Circle min_circle_cover(vector<Pt> a) {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    // 两点确定一个圆
    auto get2 = [](const Pt &a, const Pt &b) -> Circle {
        return {(a + b) / 2, a.dis(b) / 2};
    };
    // 三点确定一个圆
    auto get3 = [](const Pt &a, const Pt &b, const Pt &c) -> Circle {
        Lt u = St{a, b}.midperp(), v = St{a, c}.midperp();
        Pt p = u.inter(v);
        return {p, a.dis(p)};
    };
    shuffle(a.begin(), a.end(), rng);
    Circle C{a[0], 0};
    for (size_t i = 1; i < a.size(); i++) {
        if (C.r < C.c.dis(a[i])) {
            C = {a[i], 0};
            for (size_t j = 0; j < i; j++) {
                if (C.r < C.c.dis(a[j])) {
                    C = get2(a[i], a[j]);
                    for (size_t k = 0; k < j; k++) {
                        if (C.r < C.c.dis(a[k])) {
                            C = get3(a[i], a[j], a[k]);
                        }
                    }
                }
            }
        }
    }
    return C;
}

// 半平面交
// 排序增量法，复杂度 O(nlogn)
// 输入与返回值都是用直线表示的半平面集合
vector<Lt> halfinter(vector<Lt> l, const T lim = 1e9) {
    // 必须用浮点数，return <= 则会去掉冗余线
    const auto check = [](const Lt &a, const Lt &b, const Lt &c) { return a.toleft(b.inter(c)) < 0; };
    // 无精度误差的方法，但注意取值范围会扩大到三次方
    // const auto check = [](const Lt &a, const Lt &b, const Lt &c) {
    //     const Pt p = a.v * (b.v ^ c.v), q = b.p * (b.v ^ c.v) + b.v * (c.v ^ (b.p - c.p)) - a.p * (b.v ^ c.v);
    //     return p.toleft(q) < 0;
    // };
    l.push_back({{-lim, 0}, {0, -1}});
    l.push_back({{0, -lim}, {1, 0}});
    l.push_back({{lim, 0}, {0, 1}});
    l.push_back({{0, lim}, {-1, 0}});
    sort(l.begin(), l.end());
    deque<Lt> q;
    for (size_t i = 0; i < l.size(); i++) {
        if (i > 0 && l[i - 1].v.toleft(l[i].v) == 0 && l[i - 1].v * l[i].v > eps) continue;
        while (q.size() > 1 && check(l[i], q.back(), q[q.size() - 2])) q.pop_back();
        while (q.size() > 1 && check(l[i], q[0], q[1])) q.pop_front();
        if (!q.empty() && q.back().v.toleft(l[i].v) <= 0) return vector<Lt>();
        q.push_back(l[i]);
    }
    while (q.size() > 1 && check(q[0], q.back(), q[q.size() - 2])) q.pop_back();
    while (q.size() > 1 && check(q.back(), q[0], q[1])) q.pop_front();
    return vector<Lt>(q.begin(), q.end());
}

// 平面最近点对
// 扫描线，复杂度 O(nlogn)
// 返回最近点对距离平方
T closest_pair(vector<Pt> pts) {
    sort(pts.begin(), pts.end());
    const auto cmpy = [](const Pt &a, const Pt &b) {
        if (abs(a.y - b.y) <= eps) return a.x < b.x - eps;
        return a.y < b.y - eps;
    };
    multiset<Pt, decltype(cmpy)> s{cmpy};
    T ans = INF;
    for (size_t i = 0, l = 0; i < pts.size(); i++) {
        const T sqans = sqrtl(ans) + 1;
        while (l < i && pts[i].x - pts[l].x >= sqans) s.erase(s.find(pts[l++]));
        for (auto it = s.lower_bound(Pt{-INF, pts[i].y - sqans}); it != s.end() && it->y - pts[i].y <= sqans; it++) {
            ans = min(ans, pts[i].dis2(*it));
        }
        s.insert(pts[i]);
    }
    return ans;
}

// 点集形成的最小最大三角形
// 极角序扫描线，复杂度 O(n^2logn)
// 最大三角形问题可以使用凸包与旋转卡壳做到 O(n^2)
pair<T, T> minmax_triangle(const vector<Pt> &vec) {
    if (vec.size() <= 2) return {0, 0};
    vector<pair<int, int>> evt;
    evt.reserve(vec.size() * vec.size());
    T maxans = 0, minans = INF;
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size(); j++) {
            if (i == j) continue;
            if (vec[i] == vec[j])
                minans = 0;
            else
                evt.push_back({i, j});
        }
    }
    sort(evt.begin(), evt.end(), [&](const pair<int, int> &u, const pair<int, int> &v) {
        const Pt du = vec[u.second] - vec[u.first], dv = vec[v.second] - vec[v.first];
        return Argcmp()({du.y, -du.x}, {dv.y, -dv.x});
    });
    vector<size_t> vx(vec.size()), pos(vec.size());
    for (size_t i = 0; i < vec.size(); i++) vx[i] = i;
    sort(vx.begin(), vx.end(), [&](int x, int y) { return vec[x] < vec[y]; });
    for (size_t i = 0; i < vx.size(); i++) pos[vx[i]] = i;
    for (auto [u, v] : evt) {
        const size_t i = pos[u], j = pos[v];
        const size_t l = min(i, j), r = max(i, j);
        const Pt vecu = vec[u], vecv = vec[v];
        if (l > 0) minans = min(minans, abs((vec[vx[l - 1]] - vecu) ^ (vec[vx[l - 1]] - vecv)));
        if (r < vx.size() - 1) minans = min(minans, abs((vec[vx[r + 1]] - vecu) ^ (vec[vx[r + 1]] - vecv)));
        maxans = max({maxans, abs((vec[vx[0]] - vecu) ^ (vec[vx[0]] - vecv)), abs((vec[vx.back()] - vecu) ^ (vec[vx.back()] - vecv))});
        if (i < j) swap(vx[i], vx[j]), pos[u] = j, pos[v] = i;
    }
    return {minans, maxans};
}

// 判断多条线段是否有交点
// 扫描线，复杂度 O(nlogn)
bool segs_inter(const vector<St> &segs) {
    if (segs.empty()) return false;
    using seq_t = tuple<T, int, St>; // x坐标 出入点 线段
    const auto seqcmp = [](const seq_t &u, const seq_t &v) {
        const auto [u0, u1, u2] = u;
        const auto [v0, v1, v2] = v;
        if (abs(u0 - v0) <= eps) return make_pair(u1, u2) < make_pair(v1, v2);
        return u0 < v0 - eps;
    };
    vector<seq_t> seq;
    for (auto seg : segs) {
        if (seg.a.x > seg.b.x + eps) swap(seg.a, seg.b);
        seq.push_back({seg.a.x, 0, seg});
        seq.push_back({seg.b.x, 1, seg});
    }
    sort(seq.begin(), seq.end(), seqcmp);
    T x_now;
    auto cmp = [&](const St &u, const St &v) {
        if (abs(u.a.x - u.b.x) <= eps || abs(v.a.x - v.b.x) <= eps) return u.a.y < v.a.y - eps;
        return ((x_now - u.a.x) * (u.b.y - u.a.y) + u.a.y * (u.b.x - u.a.x)) * (v.b.x - v.a.x) < ((x_now - v.a.x) * (v.b.y - v.a.y) + v.a.y * (v.b.x - v.a.x)) * (u.b.x - u.a.x) - eps;
    };
    multiset<St, decltype(cmp)> s{cmp};
    for (const auto [x, o, seg] : seq) {
        x_now = x;
        const auto it = s.lower_bound(seg);
        if (o == 0) {
            if (it != s.end() && seg.is_inter(*it)) return true;
            if (it != s.begin() && seg.is_inter(*prev(it))) return true;
            s.insert(seg);
        } else {
            if (next(it) != s.end() && it != s.begin() && (*prev(it)).is_inter(*next(it))) return true;
            s.erase(it);
        }
    }
    return false;
}

// 圆与多边形面积交
T area_inter(const Circle &circ, const Polygon &poly) {
    const auto cal = [](const Circle &circ, const Pt &a, const Pt &b) {
        if ((a - circ.c).toleft(b - circ.c) == 0) return 0.0L;
        const auto ina = circ.is_in(a), inb = circ.is_in(b);
        const Lt ab = {a, b - a};
        if (ina && inb) return ((a - circ.c) ^ (b - circ.c)) / 2;
        if (ina && !inb) {
            const auto t = circ.inter(ab);
            const Pt p = t.size() == 1 ? t[0] : t[1];
            const T ans = ((a - circ.c) ^ (p - circ.c)) / 2;
            const T th = (p - circ.c).ang(b - circ.c);
            const T d = circ.r * circ.r * th / 2;
            if ((a - circ.c).toleft(b - circ.c) == 1) return ans + d;
            return ans - d;
        }
        if (!ina && inb) {
            const Pt p = circ.inter(ab)[0];
            const T ans = ((p - circ.c) ^ (b - circ.c)) / 2;
            const T th = (a - circ.c).ang(p - circ.c);
            const T d = circ.r * circ.r * th / 2;
            if ((a - circ.c).toleft(b - circ.c) == 1) return ans + d;
            return ans - d;
        }
        const auto p = circ.inter(ab);
        if (p.size() == 2 && St{a, b}.dis(circ.c) <= circ.r + eps) {
            const T ans = ((p[0] - circ.c) ^ (p[1] - circ.c)) / 2;
            const T th1 = (a - circ.c).ang(p[0] - circ.c), th2 = (b - circ.c).ang(p[1] - circ.c);
            const T d1 = circ.r * circ.r * th1 / 2, d2 = circ.r * circ.r * th2 / 2;
            if ((a - circ.c).toleft(b - circ.c) == 1) return ans + d1 + d2;
            return ans - d1 - d2;
        }
        const T th = (a - circ.c).ang(b - circ.c);
        if ((a - circ.c).toleft(b - circ.c) == 1) return circ.r * circ.r * th / 2;
        return -circ.r * circ.r * th / 2;
    };
    T ans = 0;
    for (size_t i = 0; i < poly.p.size(); i++) {
        const Pt a = poly.p[i], b = poly.p[poly.nxt(i)];
        ans += cal(circ, a, b);
    }
    return ans;
}

// 多边形面积并
// 轮廓积分，复杂度 O(n^2logn)，n为边数
// ans[i] 表示被至少覆盖了 i+1 次的区域的面积
vector<T> area_union(const vector<Polygon> &polys) {
    const size_t siz = polys.size();
    vector<vector<pair<Pt, Pt>>> segs(siz);
    const auto check = [](const Pt &u, const St &e) { return !((u < e.a && u < e.b) || (u > e.a && u > e.b)); };
    auto cut_edge = [&](const St &e, const size_t i) {
        const Lt le{e.a, e.b - e.a};
        vector<pair<Pt, int>> evt;
        evt.push_back({e.a, 0});
        evt.push_back({e.b, 0});
        for (size_t j = 0; j < polys.size(); j++) {
            if (i == j) continue;
            const auto &pj = polys[j];
            for (size_t k = 0; k < pj.p.size(); k++) {
                const St s = {pj.p[k], pj.p[pj.nxt(k)]};
                if (le.toleft(s.a) == 0 && le.toleft(s.b) == 0) {
                    evt.push_back({s.a, 0});
                    evt.push_back({s.b, 0});
                } else if (s.is_inter(le)) {
                    const Lt ls{s.a, s.b - s.a};
                    const Pt u = le.inter(ls);
                    if (le.toleft(s.a) < 0 && le.toleft(s.b) >= 0)
                        evt.push_back({u, -1});
                    else if (le.toleft(s.a) >= 0 && le.toleft(s.b) < 0)
                        evt.push_back({u, 1});
                }
            }
        }
        sort(evt.begin(), evt.end());
        if (e.a > e.b) reverse(evt.begin(), evt.end());
        int sum = 0;
        for (size_t i = 0; i < evt.size(); i++) {
            sum += evt[i].second;
            const Pt u = evt[i].first, v = evt[i + 1].first;
            if (!(u == v) && check(u, e) && check(v, e)) segs[sum].push_back({u, v});
            if (v == e.b) break;
        }
    };
    for (size_t i = 0; i < polys.size(); i++) {
        const auto &pi = polys[i];
        for (size_t k = 0; k < pi.p.size(); k++) {
            const St ei = {pi.p[k], pi.p[pi.nxt(k)]};
            cut_edge(ei, i);
        }
    }
    vector<T> ans(siz);
    for (size_t i = 0; i < siz; i++) {
        T sum = 0;
        sort(segs[i].begin(), segs[i].end());
        int cnt = 0;
        for (size_t j = 0; j < segs[i].size(); j++) {
            if (j > 0 && segs[i][j] == segs[i][j - 1])
                segs[i + (++cnt)].push_back(segs[i][j]);
            else
                cnt = 0, sum += segs[i][j].first ^ segs[i][j].second;
        }
        ans[i] = sum / 2;
    }
    return ans;
}

// 圆面积并
// 轮廓积分，复杂度 O(n^2logn)
// ans[i] 表示被至少覆盖了 i+1 次的区域的面积
vector<T> area_union(const vector<Circle> &circs) {
    const size_t siz = circs.size();
    using arc_t = tuple<Pt, T, T, T>;
    vector<vector<arc_t>> arcs(siz);
    const auto eq = [](const arc_t &u, const arc_t &v) {
        const auto [u1, u2, u3, u4] = u;
        const auto [v1, v2, v3, v4] = v;
        return u1 == v1 && abs(u2 - v2) <= eps && abs(u3 - v3) <= eps && abs(u4 - v4) <= eps;
    };
    auto cut_circ = [&](const Circle &ci, const size_t i) {
        vector<pair<T, int>> evt;
        evt.push_back({-PI, 0});
        evt.push_back({PI, 0});
        int init = 0;
        for (size_t j = 0; j < circs.size(); j++) {
            if (i == j) continue;
            const Circle &cj = circs[j];
            if (ci.r < cj.r - eps && ci.relation(cj) >= 3) init++;
            const auto inters = ci.inter(cj);
            if (inters.size() == 1) evt.push_back({atan2l((inters[0] - ci.c).y, (inters[0] - ci.c).x), 0});
            if (inters.size() == 2) {
                const Pt dl = inters[0] - ci.c, dr = inters[1] - ci.c;
                T argl = atan2l(dl.y, dl.x), argr = atan2l(dr.y, dr.x);
                if (abs(argl + PI) <= eps) argl = PI;
                if (abs(argr + PI) <= eps) argr = PI;
                if (argl > argr + eps) {
                    evt.push_back({argl, 1});
                    evt.push_back({PI, -1});
                    evt.push_back({-PI, 1});
                    evt.push_back({argr, -1});
                } else {
                    evt.push_back({argl, 1});
                    evt.push_back({argr, -1});
                }
            }
        }
        sort(evt.begin(), evt.end());
        int sum = init;
        for (size_t i = 0; i < evt.size(); i++) {
            sum += evt[i].second;
            if (abs(evt[i].first - evt[i + 1].first) > eps) arcs[sum].push_back({ci.c, ci.r, evt[i].first, evt[i + 1].first});
            if (abs(evt[i + 1].first - PI) <= eps) break;
        }
    };
    const auto oint = [](const arc_t &arc) {
        const auto [cc, cr, l, r] = arc;
        if (abs(r - l - PI - PI) <= eps) return 2.0L * PI * cr * cr;
        return cr * cr * (r - l) + cc.x * cr * (sinl(r) - sinl(l)) - cc.y * cr * (cosl(r) - cosl(l));
    };
    for (size_t i = 0; i < circs.size(); i++) {
        const auto &ci = circs[i];
        cut_circ(ci, i);
    }
    vector<T> ans(siz);
    for (size_t i = 0; i < siz; i++) {
        T sum = 0;
        sort(arcs[i].begin(), arcs[i].end());
        int cnt = 0;
        for (size_t j = 0; j < arcs[i].size(); j++) {
            if (j > 0 && eq(arcs[i][j], arcs[i][j - 1]))
                arcs[i + (++cnt)].push_back(arcs[i][j]);
            else
                cnt = 0, sum += oint(arcs[i][j]);
        }
        ans[i] = sum / 2;
    }
    return ans;
}
```
## 三维基础
```cpp
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

using T = ld; // 全局数据类型

const T eps = 1e-12;
const T INF = numeric_limits<T>::max();
const T PI = acosl(-1);
#define setp(x) cout << fixed << setprecision(x)

struct Pt {
    T x, y, z;
    bool operator==(const Pt &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps) && abs(z - a.z) <= eps; }
    bool operator!=(const Pt &a) const { return !(*this == a); }
    bool operator<(const Pt &a) const {
        if (abs(x - a.x) <= eps && abs(y - a.y) <= eps) return z < a.z - eps;
        if (abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }
    bool operator>(const Pt &a) const { return !(*this < a || *this == a); }
    Pt operator+(const Pt &a) const { return {x + a.x, y + a.y, z + a.z}; }
    Pt operator-(const Pt &a) const { return {x - a.x, y - a.y, z - a.z}; }
    Pt operator-() const { return {-x, -y - z}; }
    Pt operator*(const T k) const { return {k * x, k * y, k * z}; }
    Pt operator/(const T k) const { return {x / k, y / k, z / k}; }
    T operator*(const Pt &a) const { return x * a.x + y * a.y + z * a.z; }
    // 注意三维叉积是向量
    Pt operator^(const Pt &a) const { return {y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x}; }
    T len2() const { return (*this) * (*this); }               // 向量长度的平方
    T dis2(const Pt &a) const { return (a - (*this)).len2(); } // 两点距离的平方
    // 必须用浮点数
    T len() const { return sqrtl(len2()); }                                                              // 向量长度
    T dis(const Pt &a) const { return sqrtl(dis2(a)); }                                                  // 两点距离
    T ang(const Pt &a) const { return acosl(max(-1.0L, min(1.0L, (*this) * a) / (len() * a.len()))); } // 向量夹角
    // 自身绕 向量v 逆时针旋转
    Pt rot(Pt v, const T a) const {
        v = v / v.len();         // 单位化轴
        Pt p1 = v * (v * *this); // 平行分量
        Pt p2 = *this - p1;      // 垂直分量 1
        if (p2.len() <= eps) return *this;
        Pt p3 = v ^ p2;                  // 垂直分量 2
        p3 = p3 * (p2.len() / p3.len()); // 调整成 p2 长度
        return p1 + p2 * cosl(a) - p3 * sinl(a);
    }
};

struct Plane {
    // 点 法向量
    Pt p, n;
    int tofront(const Pt &a) const { // 点在法向量方向
        T t = (a - p) * n;
        return (t > eps) - (t < -eps);
    }
    // 必须用浮点数
    T dis(const Pt &a) const { return abs((a - p) * n) / n.len(); }
    // 求所有点距离平面的最大值：
    // (所有点的法向量的点积的 max - min) / n.len()
};
```