#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

const ld PI = acosl(-1);
const ld EPS = 1e-8;
const ld INF = 1e18;
#define Pt Point<T>
#define Pi Point<i64>
#define Pd Point<ld>
#define Lt Line<T>
#define Li Line<i64>
#define Ld Line<ld>

#define setp(x) cout << fixed << setprecision(x)

template <class T, class S>
bool equal(T x, S y) {
    return -EPS < x - y && x - y < EPS;
}

template <class T>
int sign(T x) {
    if (-EPS < x && x < EPS) {
        return 0;
    } else {
        return x < 0 ? -1 : 1;
    }
}

template <class T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    template <class U>
    operator Point<U>() { return Point<U>(U(x), U(y)); }
    Point &operator+=(Point p) & { return x += p.x, y += p.y, *this; }
    Point &operator+=(T t) & { return x += t, y += t, *this; }
    Point &operator-=(Point p) & { return x -= p.x, y -= p.y, *this; }
    Point &operator-=(T t) & { return x -= t, y -= t, *this; }
    Point &operator*=(T t) & { return x *= t, y *= t, *this; }
    Point &operator/=(T t) & { return x /= t, y /= t, *this; }
    Point operator-() const { return Point(-x, -y); }
    friend Point operator+(Point a, Point b) { return a += b; }
    friend Point operator+(Point a, T b) { return a += b; }
    friend Point operator-(Point a, Point b) { return a -= b; }
    friend Point operator-(Point a, T b) { return a -= b; }
    friend Point operator*(Point a, T b) { return a *= b; }
    friend Point operator*(T a, Point b) { return b *= a; }
    friend Point operator/(Point a, T b) { return a /= b; }
    friend bool operator<(Point a, Point b) { return equal(a.x, b.x) ? a.y < b.y - EPS : a.x < b.x - EPS; }
    friend bool operator>(Point a, Point b) { return b < a; }
    friend bool operator==(Point a, Point b) { return !(a < b) && !(b < a); }
    friend auto &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
    friend auto &operator<<(ostream &os, Point p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

// A·B·sinθ
template <class T>
T cross(Pt a, Pt b) {
    return a.x * b.y - a.y * b.x;
}
// (p1 - p0) x (p2 - p0)
template <class T>
T cross(Pt p0, Pt p1, Pt p2) {
    return cross(p1 - p0, p2 - p0);
}

// A·B·cosθ
template <class T>
T dot(Pt a, Pt b) {
    return a.x * b.x + a.y * b.y;
}
// (p1 - p0) · (p2 - p0)
template <class T>
T dot(Pt p0, Pt p1, Pt p2) {
    return dot(p1 - p0, p2 - p0);
}

// 求距离 开方
template <class T>
ld dis(T x1, T y1, T x2, T y2) {
    ld val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrtl(val);
}
template <class T>
ld dis(Pt a, Pt b) {
    return dis(a.x, a.y, b.x, b.y);
}

// 求距离 不开方
template <class T>
T disEx(T x1, T y1, T x2, T y2) {
    T val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return val;
}
template <class T>
T disEx(Pt a, Pt b) {
    return disEx(a.x, a.y, b.x, b.y);
}

// 曼哈顿距离
template <class T>
T manha(Pt a, Pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Line(a, b) 逆时针旋转 90°
// 要想获取点 a 绕点 o 逆时针旋转 90° 后的点，
// 可以这样书写代码：auto ans = o + rotate90(o, a);
// 如果是顺时针旋转，那么只需更改符号即可：
// auto ans = o - rotate90(o, a);
template <class T>
Pt rotate90(Pt a, Pt b) {
    Pt vec = b - a;
    return {-vec.y, vec.x};
}

// 计算 oa, ob 夹角
template <class T>
ld angle(Pt a, Pt b) {
    ld res = atan2l(cross(a, b), dot(a, b));
    // 有向线段 360°
    return res + (sign(res) < 0) * 2 * PI;
    // 无向线段 180°
    // return abs(res);
}

template <class T>
struct Line {
    Pt a, b;
    Line(Pt _a = Pt(), Pt _b = Pt()) : a(_a), b(_b) {}
    template <class U>
    operator Line<U>() { return Line<U>(Point<U>(a), Point<U>(b)); }
    friend auto &operator<<(ostream &os, Line l) { return os << "<" << l.a << ", " << l.b << ">"; }
};

// 点到直线距离 有向 无向
template <class T>
ld disPointToLine(Pt p, Lt l) {
    ld ans = cross(p, l.a, l.b);
    return abs(ans) / dis(l.a, l.b);
}

// 两直线相交交点 long double
Pd lineIntersection(Ld l1, Ld l2) {
    ld val = cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b);
    return l1.a + (l1.b - l1.a) * val;
}

// 计算线段的中垂线
template <class T>
Lt midperp(Lt l) {
    Pt mid = (l.a + l.b) / 2; // 线段中点
    return {mid, mid + rotate90(l.a, l.b)};
}

// 点在直线上的投影点（垂足）
Pd pedal(Pd p, Ld l) {
    Pd vec = l.b - l.a;
    ld r = dot(vec, p - l.a) / dot(vec, vec);
    return l.a + vec * r;
}

template <class T>
struct Circle {
    Pt c;
    T r;
    Circle(Pt _c, T _r) : c(_c), r(_r) {}
};

// 过两点最小圆
template <class T>
Circle<T> cover(Pt a, Pt b) {
    return {(a + b) / 2, dis(a, b) / 2};
}

// 过三点最小圆
template <class T>
Circle<T> cover(Pt a, Pt b, Pt c) {
    auto u = midperp(Lt(a, b)), v = midperp(Lt(a, c));
    auto p = lineIntersection(u, v);
    return {p, dis(a, p)};
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// 期望 O(n) | 最小圆覆盖 | 1-index
Circle<ld> minCircleCover(vector<Point<ld>> &a, int n) {
    shuffle(a.begin() + 1, a.end(), rng);
    Circle<ld> C(a[1], 0);
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
