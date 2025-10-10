// https://codeforces.com/gym/106056/problem/D
// 求弧段上所有点构成的凸包上点的最长距离
// 显然最长距离两侧都是凸包的顶点
// 大弧从小弧上转移（大弧比小弧多一个点）
// 新的距离仅可能出现在：
// 1. 大弧两侧端点
// 2. 大弧缺一个端点构成的小弧内的顶点
// 因为大弧缺一个端点构成的小弧仅可能有两个，所以转移 O(1)
// 所以能写出一个 O(n^2) 的 dp
// 同类题目：
// https://codeforces.com/problemset/problem/2074/G
// 也是从弧的新端点两侧转移，但是这个枚举的不是线段，枚举的是三角形
// 所有中间还需要再枚举一个断点，从而是 O(n^3)
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

// 有浮点数但是大部分都是 i64 时，可以选择用 pair<ld, ld> 替换必需内容
// 然后删去强制浮点数的函数，改用手写 pair<ld, ld> 替代。
using T = i64; // 全局数据类型

const T eps = 1e-12; // 注意一旦使用 T = i64，eps 就是 0LL ！！！
const T INF = numeric_limits<T>::max();
const T PI = acosl(-1); // 注意一旦使用 T = i64，PI 就是 3LL ！！！

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

struct Convex {
    vector<Pt> p; // 以逆时针顺序存储
    int ne(const int i) const { return i == p.size() - 1 ? 0 : i + 1; }
    int pre(const int i) const { return i == 0 ? p.size() - 1 : i - 1; }
};

void solve() {
    int n;
    cin >> n;
    Convex C;
    C.p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> C.p[i].x >> C.p[i].y;
    }

    vector<vector<i64>> a(n, vector<i64>(n));
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n; i++) {
            int j = (i + l) % n;
            a[i][j] = max({a[C.ne(i)][j], a[i][C.pre(j)], C.p[i].dis2(C.p[j])});
        }
    }

    i64 ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p = C.ne(i), q = C.pre(i);
            if ((C.p[i] - C.p[p] ^ C.p[p] - C.p[j]) &&
                (C.p[i] - C.p[q] ^ C.p[q] - C.p[j])) {
                ans = min(ans, a[i][j] + a[j][i]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}