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
    friend Pt operator+(Pt a, T b) { return a += b; }
    friend Pt operator+(Pt a, Pt b) { return a += b; }
    friend Pt operator-(Pt a, T b) { return a -= b; }
    friend Pt operator-(Pt a, Pt b) { return a -= b; }
    friend Pt operator*(Pt a, T b) { return a *= b; }
    friend Pt operator*(T a, Pt b) { return b *= a; }
    friend T cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
    friend T dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
    friend Pt operator/(Pt a, T b) { return a /= b; }
    friend bool operator<(Pt a, Pt b) { return equal(a.x, b.x) ? a.y < b.y - EPS : a.x < b.x - EPS; }
    friend bool operator>(Pt a, Pt b) { return b < a; }
    friend bool operator==(Pt a, Pt b) { return !(a < b) && !(b < a); }
    friend auto &operator>>(istream &is, Pt &p) { return is >> p.x >> p.y; }
    friend auto &operator<<(ostream &os, Pt p) { return os << p.x << ' ' << p.y << '\n'; }
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
    if (!equal(T, 0))
        return pdc > 0;
    // 3. 共线时 近点优先
    return dot(a, a) < dot(b, b);
}

struct Lt {
    Pt a, b;
    Lt(Pt _a = Pt(), Pt _b = Pt()) : a(_a), b(_b) {}
    Pt v() const { return b - a; }
    int toleft(Pt c) const { return v().toleft(c - a); }
    friend bool operator<(Lt &a, Lt &b) {
        // 平行时，靠内的排在前面
        if (abs(cross(a.v(), b.v())) <= EPS && dot(a.v(), b.v()) >= -EPS)
            return a.toleft(b.a) < 0;
        return polarCmp(a.v(), b.v());
    }
};
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

// 求距离 开方
ld dis(T x1, T y1, T x2, T y2) {
    ld val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrtl(val);
}
ld dis(Pt a, Pt b) {
    return dis(a.x, a.y, b.x, b.y);
}

// 求距离 不开方
T disEx(T x1, T y1, T x2, T y2) {
    T val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return val;
}
T disEx(Pt a, Pt b) {
    return disEx(a.x, a.y, b.x, b.y);
}

// 曼哈顿距离
T manha(Pt a, Pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// atan2l 极角排序 cmp
// atan2l(p.y, p.x) 其实就是 向量 p 的极角大小
bool polarCmp(Pt a, Pt b) {
    // a = a - o, b = b - o;
    return atan2l(a.y, a.x) < atan2l(b.y, b.x);
}

// 向量旋转任意角度
// using T = ld;
Pt rotate(Pt p, ld rad) {
    return {p.x * cosl(rad) - p.y * sinl(rad), p.x * sin(rad) + p.y * cosl(rad)};
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

// 点到直线距离 有向 无向
ld disPointToLine(Pt p, Lt l) {
    ld ans = cross(p, l.a, l.b);
    return abs(ans) / dis(l.a, l.b);
}

// 两直线相交交点 long double
// using T = ld;
Pt inter(Lt l1, Lt l2) {
    ld val = cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b);
    return l1.a + (l1.b - l1.a) * val;
}

// 计算线段的中垂线
Lt midperp(Lt l) {
    Pt mid = (l.a + l.b) / 2; // 线段中点
    return {mid, mid + rotate90(l.a, l.b)};
}

// 点在直线上的投影点（垂足）
// using T = ld;
Pt pedal(Pt p, Lt l) {
    Pt vec = l.b - l.a;
    ld r = dot(vec, p - l.a) / dot(vec, vec);
    return l.a + vec * r;
}

// 获取直线构成的多边形 交点 (首尾相同)
vector<Pt> getPointsBaseLines(vector<Lt> &ln) {
    if (ln.size() <= 2) {
        return vector<Pt>();
    }
    vector<Pt> pts;
    pts.push_back(inter(ln[0], ln.back()));
    for (int i = 1; i < ln.size(); i++) {
        pts.push_back(inter(ln[i - 1], ln[i]));
    }
    pts.push_back(inter(ln[0], ln.back()));
    return pts;
}

// 给定多边形求面积 (首尾相同)
T polygonArea(vector<Pt> &pts) {
    T S = 0;
    for (int i = 1; i < pts.size(); i++) {
        S += cross(pts[i - 1], pts[i]);
    }
    return S / 2;
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

// Andrew 求凸包 O(nlogn)
vector<Pt> tubao(vector<Pt> a, int n) {
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
    // 逆时针凸包
    auto tb = bot;
    // i >= 0 则第一个点和最后一个点相同
    // i >= 1 则省略最后一个点
    for (int i = top.size() - 2; i >= 0; i--) {
        tb.push_back(top[i]);
    }
    return tb;
}

// 求凸包直径
T diameter(vector<Pt> &tb) {
    int n = tb.size();
    // 凸包上只有两个点
    if (n == 3) {
        cout << disEx(tb[0], tb[1]) << '\n';
        return 0;
    }
    T ans = 0;
    for (int l = 1, r = 1; l < n; l++) {
        while (cross(tb[l - 1], tb[l], tb[r]) <= cross(tb[l - 1], tb[l], tb[(r + 1) % n])) {
            r = (r + 1) % n;
        }
        ans = max({ans, disEx(tb[l], tb[r]), disEx(tb[l - 1], tb[r])});
    }
    return ans;
}

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
