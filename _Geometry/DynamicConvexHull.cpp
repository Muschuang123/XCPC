// https://codeforces.com/problemset/problem/70/D
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

// 有浮点数但是大部分都是 i64 时，可以选择用 pair<ld, ld> 替换必需内容
// 然后删去强制浮点数的函数，改用手写 pair<ld, ld> 替代。
using T = i64; // 全局数据类型

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
};

// 极角排序
struct Argcmp {
    bool operator()(const Pt &a, const Pt &b) const {
        const int qa = a.quad(), qb = b.quad();
        if (qa != qb) return qa < qb;
        const auto t = a ^ b;
        // 不同长度的向量需要分开
        if (abs(t) <= eps) return a * a < b * b - eps;
        return t > eps;
    }
};

// 注意整数时需要全体坐标在外面 * 3，才能保证准确
// 注意要把 Argcmp 的 区分长度注释解除
struct DynamicConvex {
    Pt o;
    set<Pt, Argcmp> ss; // 注意 ss 中的点 已经 - o
    using iter = set<Pt, Argcmp>::iterator;
    DynamicConvex(const Pt &a, const Pt &b, const Pt &c) {
        o = (a + b + c) / 3;
        ss.insert(a - o);
        ss.insert(b - o);
        ss.insert(c - o);
    }
    iter pre(iter it) const { return it == ss.begin() ? --ss.end() : (--it); }
    iter nxt(iter it) const { return (++it) == ss.end() ? ss.begin() : it; }
    // -1 点在多边形边上 | 0 点在多边形外 | 1 点在多边形内
    int is_in(Pt x) const {
        x = x - o;
        auto it = ss.lower_bound(x);
        if (it != ss.end() && (*it ^ x) == 0) return x * x <= *it * *it;
        iter l = pre(it);
        iter r = (it == ss.end()) ? ss.begin() : it;
        T res = (*l - x ^ *r - x);
        if (abs(res) <= eps) return -1;
        return res > 0;
    }
    // 凸包中加入点
    void insert(Pt x) {
        if (is_in(x)) return;
        x = x - o;
        auto [it, _] = ss.insert(x);
        while (ss.size() >= 4 && (*it - (*nxt(it)) ^ (*nxt(nxt(it))) - *nxt(it)) >= 0) ss.erase(nxt(it));
        while (ss.size() >= 4 && ((*pre(pre(it))) - *pre(it) ^ *it - (*pre(it))) >= 0) ss.erase(pre(it));
    }
    // 判断加入了这个点后...
    bool tryToInsert(Pt x) {
        // 能否成功加入这个点
        if (is_in(x)) return false;
        x = x - o;
        auto [it, _] = ss.insert(x);
        // 是否会删除其他的点
        if (ss.size() >= 4 && ((*it - (*nxt(it)) ^ (*nxt(nxt(it))) - *nxt(it)) >= 0 || ((*pre(pre(it))) - *pre(it) ^ *it - (*pre(it))) >= 0)) {
            ss.erase(x);
            return 0;
        }
        ss.erase(x);
        return 1;
    }
    // 强制擦除点
    // 注意如果 erase 导致凸包重心转移，需要重新创建新的凸包
    void erase(Pt x) {
        x = x - o;
        ss.erase(x);
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> op(n + 1);
    vector<Pt> pts(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> pts[i].x >> pts[i].y;
        pts[i] = pts[i] * 3;
    }
    DynamicConvex D(pts[1], pts[2], pts[3]);
    for (int i = 4; i <= n; i++) {
        if (op[i] == 1) { // 添加
            D.insert(pts[i]);
        } else { // 查询
            if (D.is_in(pts[i])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}