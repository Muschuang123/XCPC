#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

using T = ld;

const ld PI = acosl(-1);
const ld EPS = 1e-8;
const ld INF = 1e18;

#define setp(x) cout << fixed << setprecision(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool equal(T x, T y) {
    return -EPS < x - y && x - y < EPS;
}

int sgn(T x) {
    if (-EPS < x && x < EPS) {
        return 0;
    } else {
        return x < 0 ? -1 : 1;
    }
}

struct Pt {
    T x, y;
    Pt(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Pt &operator+=(Pt p) & { return x += p.x, y += p.y, *this; }
    Pt &operator+=(T t) & { return x += t, y += t, *this; }
    Pt &operator-=(Pt p) & { return x -= p.x, y -= p.y, *this; }
    Pt &operator-=(T t) & { return x -= t, y -= t, *this; }
    Pt &operator*=(T t) & { return x *= t, y *= t, *this; }
    Pt &operator/=(T t) & { return x /= t, y /= t, *this; }
    Pt operator-() const { return Pt(-x, -y); }
    int quadrant() const {
        if (sgn(x) > 0 && sgn(y) >= 0) return 1;
        if (sgn(x) <= 0 && sgn(y) > 0) return 2;
        if (sgn(x) < 0 && sgn(y) <= 0) return 3;
        return 4;
    }
    // 1 在左边 | 0 平行 | -1 在右边
    int toleft(Pt a) const {
        T t = cross(*this, a);
        return (t > EPS) - (t < -EPS);
    }
};

Pt operator+(Pt a, T b) { return a += b; }
Pt operator+(Pt a, Pt b) { return a += b; }
Pt operator-(Pt a, T b) { return a -= b; }
Pt operator-(Pt a, Pt b) { return a -= b; }
Pt operator*(Pt a, T b) { return a *= b; }
Pt operator*(T a, Pt b) { return b *= a; }
Pt operator/(Pt a, T b) { return a /= b; }
T cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
T dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
T dis2(Pt a, Pt b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) };
ld dis(Pt a, Pt b) { return sqrtl(dis2(a, b)); }
T manha(Pt a, Pt b) { return abs(a.x - b.x) + abs(a.y - b.y); }
bool operator<(Pt a, Pt b) { return equal(a.x, b.x) ? a.y < b.y - EPS : a.x < b.x - EPS; }
bool operator>(Pt a, Pt b) { return b < a; }
bool operator==(Pt a, Pt b) { return !(a < b) && !(b < a); }
bool operator!=(Pt a, Pt b) { return !(a == b); }
auto &operator>>(istream &is, Pt &p) { return is >> p.x >> p.y; }
auto &operator<<(ostream &os, Pt p) { return os << p.x << ' ' << p.y; }

// 叉乘 极角排序 cmp 可设置 o 为极点
// i64 类型最好用，因为 atan2l 引入浮点，又慢又精度误差
// ld 类型也可以用，乘法不会造成精度问题，但据说比 atan2l 慢
bool polarCmp(Pt a, Pt b) {
    // a = a - o, b = b - o;
    // 1. 判断 象限
    if (a.quadrant() != b.quadrant())
        return a.quadrant() < b.quadrant();
    // 2. 检查是否共线
    T pdc = cross(a, b);
    if (!equal(pdc, 0))
        return pdc > 0;
    // 3. 共线时 近点优先
    return dot(a, a) < dot(b, b);
}

// atan2l 极角排序 cmp
// atan2l(p.y, p.x) 其实就是 向量 p 的极角大小
bool polarCmp(Pt a, Pt b) {
    // a = a - o, b = b - o;
    return atan2l(a.y, a.x) < atan2l(b.y, b.x);
}

// 三点叉积
// (p1 - p0) x (p2 - p0)
T cross(Pt p0, Pt p1, Pt p2) {
    return cross(p1 - p0, p2 - p0);
}

// 三点点积
// (p1 - p0) · (p2 - p0)
T dot(Pt p0, Pt p1, Pt p2) {
    return dot(p1 - p0, p2 - p0);
}

// 向量旋转任意角度
// using T = ld;
Pt rotate(Pt p, ld rad) {
    return {p.x * cosl(rad) - p.y * sinl(rad), p.x * sinl(rad) + p.y * cosl(rad)};
}

// Lt(a, b) 逆时针旋转 90°
// 要想获取点 a 绕点 o 逆时针旋转 90° 后的点，
// 可以这样书写代码：auto ans = o + rotate90(o, a);
// 如果是顺时针旋转，那么只需更改符号即可：
// auto ans = o - rotate90(o, a);
Pt rotate90(Pt a, Pt b) {
    Pt vec = b - a;
    return {-vec.y, vec.x};
}

// 计算 oa, ob 夹角
ld angle(Pt a, Pt b) {
    ld res = atan2l(cross(a, b), dot(a, b));
    // 有向线段 360°
    return res + (sgn(res) < 0) * 2 * PI;
    // 无向线段 180°
    // return abs(res);
}

struct Lt {
    Pt a, b;
    Lt(Pt _a, Pt _b) : a(_a), b(_b) {}
    // 方向向量
    Pt v() const { return b - a; }
    int toleft(Pt c) const { return v().toleft(c - a); }
    // 判断点是否在线段上
    // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
    int isOn(Pt p) const {
        if (p == a || p == b) return -1;
        return (p - a).toleft(p - b) == 0 && dot(p - a, p - b) < -EPS;
    }
};

// 判断线段直线是否相交
// -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
int isInterLS(Lt l, Lt s) const {
    if (l.toleft(s.a) == 0 || l.toleft(s.b) == 0) return -1;
    return l.toleft(s.a) != l.toleft(s.b);
}
// 判断两线段是否相交
// -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
int isInterSS(Lt s1, Lt s2) const {
    if (isOn(s1.a) || isOn(s1.b) || s1.isOn(s2.a) || s1.isOn(s2.b)) return -1;
    const Lt l(s2.a, s2.b), ls(s1.a, s1.b);
    return l.toleft(s1.a) * l.toleft(s1.b) == -1 && ls.toleft(s2.a) * ls.toleft(s2.b) == -1;
}
// 点到直线距离 (去掉 abs 变有向)
ld disLP(Lt l, Pt p) const {
    ld ans = cross(p, l.a, l.b);
    return abs(ans) / dis(l.a, l.b);
}
// 点到线段距离
ld disSP(Lt s, Pt p) const {
    if (dot(p - s.a, s.b - s.a) < -EPS || dot(p - s.b, s.a - s.b) < -EPS)
        return min(dis(p, s.a), dis(p, s.b));
    return Lt(s.a, s.b).disLP(p);
}
// 两线段间距离
ld disSS(Lt s1, Lt s2) const {
    if (isInterSS(s1)) return 0;
    return min({disLP(s2, s1.a), disLP(s2, s1.b), disLP(s1, s2.a), disLP(s1, s2.b)});
}

// 半平面交标准 对 有方向的直线 排序
bool operator<(Lt a, Lt b) {
    // 平行时，靠内的排在前面
    if (abs(cross(a.v(), b.v())) <= EPS && dot(a.v(), b.v()) >= -EPS)
        return a.toleft(b.a) < 0;
    return polarCmp(a.v(), b.v());
}

// 两直线相交交点（必须用浮点数）
Pt inter(Lt l1, Lt l2) {
    ld val = cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b);
    return l1.a + (l1.b - l1.a) * val;
}

// 计算线段的中垂线
Lt midperp(Lt l) {
    Pt mid = (l.a + l.b) / 2; // 线段中点
    return {mid, mid + rotate90(l.a, l.b)};
}

// 点在直线上的投影点（垂足）（必须用浮点数）
Pt pedal(Pt p, Lt l) {
    Pt vec = l.b - l.a;
    ld r = dot(vec, p - l.a) / dot(vec, vec);
    return l.a + vec * r;
}

// 半平面交 排序增量法，复杂度 O(nlogn)
// 输入与返回值都是用直线表示的半平面集合
vector<Lt> halfPlaneIntersection(vector<Lt> ln, T lim = 1e9) {
    if (ln.empty()) return vector<Lt>();
    // b 与 c 的交点 在 a 的右侧
    auto check = [](Lt &a, Lt &b, Lt &c) {
        return a.toleft(inter(b, c)) < 0;
    };
    ln.push_back(Lt({-lim, 0}, {0, -lim}));
    ln.push_back(Lt({0, -lim}, {lim, 0}));
    ln.push_back(Lt({lim, 0}, {0, lim}));
    ln.push_back(Lt({0, lim}, {-lim, 0}));
    sort(ln.begin(), ln.end());
    deque<Lt> dq;
    dq.push_back(ln[0]);
    for (int i = 1; i < ln.size(); i++) {
        Pt A = ln[i - 1].v(), B = ln[i].v();
        // 平行时，因为已经排序，前面的线一定更靠内
        if (A.toleft(B) == 0 && dot(A, B) > EPS) continue;
        while (dq.size() > 1 && check(ln[i], dq.back(), dq[dq.size() - 2])) dq.pop_back();
        while (dq.size() > 1 && check(ln[i], dq[0], dq[1])) dq.pop_front();
        if (!dq.empty() && dq.back().v().toleft(ln[i].v()) <= 0) return vector<Lt>();
        dq.push_back(ln[i]);
    }
    while (dq.size() > 1 && check(dq[0], dq.back(), dq[dq.size() - 2])) dq.pop_back();
    while (dq.size() > 1 && check(dq.back(), dq[0], dq[1])) dq.pop_front();
    return vector<Lt>(dq.begin(), dq.end());
}

struct Polygon {
    // 逆时针存储 (首尾相同)
    vector<Pt> p;
    // vector<Pt> 构造 直接给 p 赋值就行
    // vector<Lt> 构造
    Polygon(vector<Lt> &ln) {
        if (ln.size() <= 2) return vector<Pt>();
        p.push_back(inter(ln[0], ln.back()));
        for (int i = 1; i < ln.size(); i++) {
            p.push_back(inter(ln[i - 1], ln[i]));
        }
        p.push_back(inter(ln[0], ln.back()));
    }
    // 多边形面积的两倍，负数说明顺时针
    T area() const {
        T S = 0;
        for (int i = 1; i < p.size(); i++) {
            S += cross(p[i - 1], p[i]);
        }
        return S;
        // return S / 2;
    }
    // 多边形周长
    T circ() const {
        T C = 0;
        for (int i = 1; i < p.size(); i++) {
            C += dis(p[i - 1], p[i]);
        }
    }
};

struct Convex : Polygon {
    // Andrew 算法求凸包 O(nlogn)
    // a : 1-index
    void andrew(vector<Pt> a) {
        int n = a.size() - 1;
        // 按照 x 坐标排序
        sort(a.begin() + 1, a.end());
        vector<Pt> top, bot;
        for (int i = 1; i <= n; i++) {
            auto [x, y] = a[i];
            while (top.size() > 1) {
                auto [x1, y1] = top[top.size() - 1];
                auto [x2, y2] = top[top.size() - 2];
                if ((y - y1) * (x1 - x2) >= (y1 - y2) * (x - x1)) {
                    top.pop_back();
                } else {
                    break;
                }
            }
            top.push_back(a[i]);
            while (bot.size() > 1) {
                auto [x1, y1] = bot[bot.size() - 1];
                auto [x2, y2] = bot[bot.size() - 2];
                if ((y - y1) * (x1 - x2) <= (y1 - y2) * (x - x1)) {
                    bot.pop_back();
                } else {
                    break;
                }
            }
            bot.push_back(a[i]);
        }
        p = bot;
        for (int i = top.size() - 2; i >= 0; i--) {
            p.push_back(top[i]);
        }
    }
    // 求凸包直径平方 O(n)
    T diameter() {
        int n = p.size();
        if (n == 2) return 0;
        if (n == 3) return dis2(p[0], p[1]);
        T ans = 0;
        for (int l = 1, r = 1; l < n; l++) {
            while (cross(p[l - 1], p[l], p[r]) <= cross(p[l - 1], p[l], p[(r + 1) % n])) {
                r = (r + 1) % n;
            }
            ans = max({ans, dis2(p[l], p[r]), dis2(p[l - 1], p[r])});
        }
        return ans;
    }
};

struct Circle {
    Pt c;
    T r;
    Circle(Pt _c, T _r) : c(_c), r(_r) {}
};

// 过两点最小圆
Circle cover(Pt a, Pt b) {
    return {(a + b) / 2, dis(a, b) / 2};
}

// 过三点最小圆
Circle cover(Pt a, Pt b, Pt c) {
    auto u = midperp(Lt(a, b)), v = midperp(Lt(a, c));
    auto p = inter(u, v);
    return {p, dis(a, p)};
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// 期望 O(n) | 最小圆覆盖 | 1-index
// using T = ld;
Circle minCircleCover(vector<Pt> &a, int n) {
    shuffle(a.begin() + 1, a.end(), rng);
    Circle C(a[1], 0);
    for (int i = 2; i <= n; i++) {
        if (C.r < dis(C.c, a[i])) {
            C = {a[i], 0};
            for (int j = 1; j < i; j++) {
                if (C.r < dis(C.c, a[j])) {
                    C = cover(a[i], a[j]);
                    for (int k = 1; k < j; k++) {
                        if (C.r < dis(C.c, a[k])) {
                            C = cover(a[i], a[j], a[k]);
                        }
                    }
                }
            }
        }
    }
    return C;
}
