
using ld = long double;
const ld PI = acos(-1);
const ld EPS = 1e-7;
const ld INF = 1E18;
#define Pt Point<T> // 简写
#define Pi Point<int>
#define Pd Point<ld>
#define Lt Line<T>
#define Li Line<int>
#define Ld Line<ld>

#define cc(x) cout << fixed << setprecision(x);

template <class T, class S>
bool equal(T x, S y) {
    return -EPS < x - y && x - y < EPS;
}

template <class T>
int sign(T x) {
    if (-EPS < x && x < EPS)
        return 0;
    return x < 0 ? -1 : 1;
}

template <class T>
struct Point { // 在C++17下使用emplace_back绑定可能会导致CE！
    T x, y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {} // 初始化
    template <class U>
    operator Point<U>() { // 自动类型匹配
        return Point<U>(U(x), U(y));
    }
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
    friend bool operator!=(Point a, Point b) { return a < b || b < a; }
    friend auto &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
    friend auto &operator<<(ostream &os, Point p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

template <class T>
struct Line {
    Point<T> a, b;
    Line(Point<T> a_ = Point<T>(), Point<T> b_ = Point<T>()) : a(a_), b(b_) {}
    template <class U>
    operator Line<U>() { // 自动类型匹配
        return Line<U>(Point<U>(a), Point<U>(b));
    }
    friend auto &operator<<(ostream &os, Line l) {
        return os << "<" << l.a << ", " << l.b << ">";
    }
};

// a x b 从a看b，b在顺时针方向是负，逆时针方向是正 (rad < 90)
template <class T>
T cross(Point<T> a, Point<T> b) { // 叉乘
    return a.x * b.y - a.y * b.x;
}
template <class T>
T cross(Point<T> p1, Point<T> p2, Point<T> p0) { // 叉乘 (p1 - p0) x (p2 - p0);
    return cross(p1 - p0, p2 - p0);
}

template <class T>
T dot(Point<T> a, Point<T> b) // 点乘
{
    return a.x * b.x + a.y * b.y;
}
template <class T>
T dot(Point<T> p1, Point<T> p2, Point<T> p0) // 点乘 (p1 - p0) * (p2 - p0);
{
    return dot(p1 - p0, p2 - p0);
}

// 求距离 开方版
template <class T>
ld dis(T x1, T y1, T x2, T y2) {
    ld val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(val);
}
template <class T>
ld dis(Point<T> a, Point<T> b) {
    return dis(a.x, a.y, b.x, b.y);
}

// 求距离 不开方
template <class T>
T disEx(T x1, T y1, T x2, T y2) { // dis无开根版
    T val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return val;
}
template <class T>
T disEx(Point<T> a, Point<T> b) { // dis无开根版
    return disEx(a.x, a.y, b.x, b.y);
}

// 曼哈顿距离
template <class T>
T dis1(Point<T> a, Point<T> b) // 曼哈顿距离公式
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// 转换为单位向量
Point<ld> standardize(Point<ld> vec) { // 转换为单位向量
    return vec / sqrt(vec.x * vec.x + vec.y * vec.y);
}

// 旋转 90°
template <class T>
Point<T> rotate(Point<T> a, Point<T> b) { // 旋转
    Point<T> vec = a - b;
    return {-vec.y, vec.x};
}
/*
要想获取点a绕点o顺时针旋转90∘后的点，
可以这样书写代码：auto ans = o + rotate(o, a);
；如果是逆时针旋转，那么只需更改符号即可：
auto ans = o - rotate(o, a);
*/

/*角度与弧度*/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

// 互相转换
ld toDeg(ld x) { // 弧度转角度
    return x * 180 / PI;
}
ld toArc(ld x) { // 角度转弧度
    return PI / 180 * x;
}

// 余弦定理
ld angle(ld a, ld b, ld c) {
    ld val = acos((a * a + b * b - c * c) / (2.0 * a * b)); // 计算弧度
    return val;
}

// 计算两向量之间的夹角
ld angle(Point<ld> a, Point<ld> b) {
    ld val = abs(cross(a, b));
    return abs(atan2(val, a.x * b.x + a.y * b.y));
}

// 向量旋转任意角度
Point<ld> rotate(Point<ld> p, ld rad) {
    return {p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad)};
}

// 点绕点旋转任意角度
Point<ld> rotate(Point<ld> a, Point<ld> b, ld rad) {
    ld x = (a.x - b.x) * cos(rad) + (a.y - b.y) * sin(rad) + b.x;
    ld y = (b.x - a.x) * sin(rad) + (a.y - b.y) * cos(rad) + b.y;
    return {x, y};
}

/*平面直线*/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

// 判断直线共线
template <class T>
bool onLine(Point<T> a, Point<T> b, Point<T> c) {
    return sign(cross(b, a, c)) == 0;
}
template <class T>
bool onLine(Point<T> p, Line<T> l) {
    return onLine(p, l.a, l.b);
}

// 点是否在向量（直线）左侧 : 向量的方向会影响答案；点在向量上时不视为在左侧。
template <class T>
bool pointOnLineLeft(Pt p, Lt l) {
    return cross(l.b, p, l.a) > 0;
}

// 两点是否在直线同侧
template <class T>
bool pointOnLineSide(Pt p1, Pt p2, Lt vec) {
    T val = cross(p1, vec.a, vec.b) * cross(p2, vec.a, vec.b);
    return sign(val) == 1;
}

// 两点是否在直线(线段?)异侧
template <class T>
bool pointNotOnLineSide(Pt p1, Pt p2, Lt vec) {
    T val = cross(p1, vec.a, vec.b) * cross(p2, vec.a, vec.b);
    return sign(val) == -1;
}

// 两直线相交交点
Pd lineIntersection(Ld l1, Ld l2) {
    ld val = cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b);
    return l1.a + (l1.b - l1.a) * val;
}

// 判断两直线是否平行
template <class T>
bool lineParallel(Lt p1, Lt p2) {
    return sign(cross(p1.a - p1.b, p2.a - p2.b)) == 0;
}

// 判断两直线是否垂直
template <class T>
bool lineVertical(Lt p1, Lt p2) {
    return sign(dot(p1.a - p1.b, p2.a - p2.b)) == 0;
}

// 判断两直线是否相同
template <class T>
bool same(Line<T> l1, Line<T> l2) {
    return lineParallel(Line{l1.a, l2.b}, {l1.b, l2.a}) && lineParallel(Line{l1.a, l2.a}, {l1.b, l2.b}) && lineParallel(l1, l2);
}

// 点到直线的最近距离
pair<Pd, ld> pointToLine(Pd p, Ld l) {
    Pd ans = lineIntersection({p, p + rotate(l.a, l.b)}, l);
    return {ans, dis(p, ans)};
}
template <class T>
ld disPointToLine(Pt p, Lt l) {
    ld ans = cross(p, l.a, l.b);
    return abs(ans) / dis(l.a, l.b); // 面积除以底边长
}

// 点是否在线段上
template <class T>
bool pointOnSegment(Pt p, Lt l) // 不含端点修改符号
{
    return sign(cross(p, l.a, l.b)) == 0 && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x) && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
}

// 点到线段的最近距离与最近点
pair<Pd, ld> pointToSegment(Pd p, Ld l) {
    if (sign(dot(p, l.b, l.a)) == -1) { // 特判到两端点的距离
        return {l.a, dis(p, l.a)};
    } else if (sign(dot(p, l.a, l.b)) == -1) {
        return {l.b, dis(p, l.b)};
    }
    return pointToLine(p, l);
}

// 点在直线上的投影点（垂足）
Pd project(Pd p, Ld l) { // 投影
    Pd vec = l.b - l.a;
    ld r = dot(vec, p - l.a) / (vec.x * vec.x + vec.y * vec.y);
    return l.a + vec * r;
}

// 计算线段的中垂线
template <class T>
Lt midSegment(Lt l) {
    Pt mid = (l.a + l.b) / 2; // 线段中点
    return {mid, mid + rotate(l.a, l.b)};
}

// 两线段是否相交及交点 该扩展版可以同时返回相交状态和交点，分为四种情况：0 代表不相交； 1 代表普通相交； 2 代表重叠（交于两个点）； 3 代表相交于端点。
template <class T>
tuple<int, Pt, Pt> segmentIntersection(Lt l1, Lt l2) {
    auto [s1, e1] = l1;
    auto [s2, e2] = l2;
    auto A = max(s1.x, e1.x), AA = min(s1.x, e1.x);
    auto B = max(s1.y, e1.y), BB = min(s1.y, e1.y);
    auto C = max(s2.x, e2.x), CC = min(s2.x, e2.x);
    auto D = max(s2.y, e2.y), DD = min(s2.y, e2.y);
    if (A < CC || C < AA || B < DD || D < BB) {
        return {0, {}, {}};
    }
    if (sign(cross(e1 - s1, e2 - s2)) == 0) {
        if (sign(cross(s2, e1, s1)) != 0) {
            return {0, {}, {}};
        }
        Pt p1(max(AA, CC), max(BB, DD));
        Pt p2(min(A, C), min(B, D));
        if (!pointOnSegment(p1, l1)) {
            swap(p1.y, p2.y);
        }
        if (p1 == p2) {
            return {3, p1, p2};
        } else {
            return {2, p1, p2};
        }
    }
    auto cp1 = cross(s2 - s1, e2 - s1);
    auto cp2 = cross(s2 - e1, e2 - e1);
    auto cp3 = cross(s1 - s2, e1 - s2);
    auto cp4 = cross(s1 - e2, e1 - e2);
    if (sign(cp1 * cp2) == 1 || sign(cp3 * cp4) == 1) {
        return {0, {}, {}};
    }
    // 使用下方函数时请使用浮点数
    Pd p = lineIntersection(l1, l2);
    if (sign(cp1) != 0 && sign(cp2) != 0 && sign(cp3) != 0 && sign(cp4) != 0) {
        return {1, p, p};
    } else {
        return {3, p, p};
    }
}

// 线段是否相交 如果不需要求交点，那么使用快速排斥+跨立实验即可，其中重叠、相交于端点均视为相交。
template <class T>
bool issegmentIntersection(Lt l1, Lt l2) {
    auto [s1, e1] = l1;
    auto [s2, e2] = l2;
    auto A = max(s1.x, e1.x), AA = min(s1.x, e1.x);
    auto B = max(s1.y, e1.y), BB = min(s1.y, e1.y);
    auto C = max(s2.x, e2.x), CC = min(s2.x, e2.x);
    auto D = max(s2.y, e2.y), DD = min(s2.y, e2.y);
    return A >= CC && B >= DD && C >= AA && D >= BB &&
           sign(cross(s1, s2, e1) * cross(s1, e1, e2)) == 1 &&
           sign(cross(s2, s1, e2) * cross(s2, e2, e1)) == 1;
}

/*平面圆相关*/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

// 点到圆的最近点
pair<Pd, ld> pointToCircle(Pd p, Pd o, ld r) {
    Pd U = o, V = o;
    ld d = dis(p, o);
    if (sign(d) == 0) { // p 为圆心时返回圆心本身
        return {o, 0};
    }
    ld val1 = r * abs(o.x - p.x) / d;
    ld val2 = r * abs(o.y - p.y) / d * ((o.x - p.x) * (o.y - p.y) < 0 ? -1 : 1);
    U.x += val1, U.y += val2;
    V.x -= val1, V.y -= val2;
    if (dis(U, p) < dis(V, p)) {
        return {U, dis(U, p)};
    } else {
        return {V, dis(V, p)};
    }
}

// 根据圆心角获取圆上某点
Point<ld> getPoint(Point<ld> p, ld r, ld rad) {
    return {p.x + cos(rad) * r, p.y + sin(rad) * r};
}

// 圆与直线交点 0代表不相交； 1 代表相切； 2 代表相交。
tuple<int, Pd, Pd> lineCircleCross(Ld l, Pd o, ld r) {
    Pd P = project(o, l);
    ld d = dis(P, o), tmp = r * r - d * d;
    if (sign(tmp) == -1) {
        return {0, {}, {}};
    } else if (sign(tmp) == 0) {
        return {1, P, {}};
    }
    Pd vec = standardize(l.b - l.a) * sqrt(tmp);
    return {2, P + vec, P - vec};
}

// 圆与线段交点  0代表不相交；1 代表相切； 2 代表相交于一个点； 3 代表相交于两个点
tuple<int, Pd, Pd> segmentCircleCross(Ld l, Pd o, ld r) {
    auto [type, U, V] = lineCircleCross(l, o, r);
    bool f1 = pointOnSegment(U, l), f2 = pointOnSegment(V, l);
    if (type == 1 && f1) {
        return {1, U, {}};
    } else if (type == 2 && f1 && f2) {
        return {3, U, V};
    } else if (type == 2 && f1) {
        return {2, U, {}};
    } else if (type == 2 && f2) {
        return {2, V, {}};
    } else {
        return {0, {}, {}};
    }
}

// 两圆是否相交及交点  同时返回相交状态和交点，分为四种情况： 0 代表内含； 1 代表相离； 2 代表相切； 3 代表相交
tuple<int, Pd, Pd> circleIntersection(Pd p1, ld r1, Pd p2, ld r2) {
    ld x1 = p1.x, x2 = p2.x, y1 = p1.y, y2 = p2.y, d = dis(p1, p2);
    if (sign(abs(r1 - r2) - d) == 1) {
        return {0, {}, {}};
    } else if (sign(r1 + r2 - d) == -1) {
        return {1, {}, {}};
    }
    ld a = r1 * (x1 - x2) * 2, b = r1 * (y1 - y2) * 2, c = r2 * r2 - r1 * r1 - d * d;
    ld p = a * a + b * b, q = -a * c * 2, r = c * c - b * b;
    ld cosa, sina, cosb, sinb;
    if (sign(d - (r1 + r2)) == 0 || sign(d - abs(r1 - r2)) == 0) {
        cosa = -q / p / 2;
        sina = sqrt(1 - cosa * cosa);
        Point<ld> p0 = {x1 + r1 * cosa, y1 + r1 * sina};
        if (sign(dis(p0, p2) - r2)) {
            p0.y = y1 - r1 * sina;
        }
        return {2, p0, p0};
    } else {
        ld delta = sqrt(q * q - p * r * 4);
        cosa = (delta - q) / p / 2;
        cosb = (-delta - q) / p / 2;
        sina = sqrt(1 - cosa * cosa);
        sinb = sqrt(1 - cosb * cosb);
        Pd ans1 = {x1 + r1 * cosa, y1 + r1 * sina};
        Pd ans2 = {x1 + r1 * cosb, y1 + r1 * sinb};
        if (sign(dis(ans1, p1) - r2))
            ans1.y = y1 - r1 * sina;
        if (sign(dis(ans2, p2) - r2))
            ans2.y = y1 - r1 * sinb;
        if (ans1 == ans2)
            ans1.y = y1 - r1 * sina;
        return {3, ans1, ans2};
    }
}

// 两圆相交面积
ld circleIntersectionArea(Pd p1, ld r1, Pd p2, ld r2) {
    ld x1 = p1.x, x2 = p2.x, y1 = p1.y, y2 = p2.y, d = dis(p1, p2);
    if (sign(abs(r1 - r2) - d) >= 0) {
        return PI * min(r1 * r1, r2 * r2);
    } else if (sign(r1 + r2 - d) == -1) {
        return 0;
    }
    ld theta1 = angle(r1, dis(p1, p2), r2);
    ld area1 = r1 * r1 * (theta1 - sin(theta1 * 2) / 2);
    ld theta2 = angle(r2, dis(p1, p2), r1);
    ld area2 = r2 * r2 * (theta2 - sin(theta2 * 2) / 2);
    return area1 + area2;
}

// 三点确定一圆
tuple<int, Pd, ld> getCircle(Pd A, Pd B, Pd C) {
    if (onLine(A, B, C)) { // 特判三点共线
        return {0, {}, 0};
    }
    Ld l1 = midSegment(Line{A, B});
    Ld l2 = midSegment(Line{A, C});
    Pd O = lineIntersection(l1, l2);
    return {1, O, dis(A, O)};
}

// 求解点到圆的切线数量与切点
pair<int, vector<Point<ld>>> tangent(Point<ld> p, Point<ld> A, ld r) {
    vector<Point<ld>> ans; // 储存切点
    Point<ld> u = A - p;
    ld d = sqrt(dot(u, u));
    if (d < r) {
        return {0, {}};
    } else if (sign(d - r) == 0) { // 点在圆上
        ans.push_back(u);
        return {1, ans};
    } else {
        ld ang = asin(r / d);
        ans.push_back(getPoint(A, r, -ang));
        ans.push_back(getPoint(A, r, ang));
        return {2, ans};
    }
}

// 求解两圆的内公、外公切线数量与切点 : 同时返回公切线数量以及每个圆的切点
tuple<int, vector<Point<ld>>, vector<Point<ld>>> tangent(Point<ld> A, ld Ar, Point<ld> B, ld Br) {
    vector<Point<ld>> a, b; // 储存切点
    if (Ar < Br) {
        swap(Ar, Br);
        swap(A, B);
        swap(a, b);
    }
    int d = disEx(A, B), dif = Ar - Br, sum = Ar + Br;
    if (d < dif * dif) { // 内含，无
        return {0, {}, {}};
    }
    ld base = atan2(B.y - A.y, B.x - A.x);
    if (d == 0 && Ar == Br) { // 完全重合，无数条外公切线
        return {-1, {}, {}};
    }
    if (d == dif * dif) { // 内切，1条外公切线
        a.push_back(getPoint(A, Ar, base));
        b.push_back(getPoint(B, Br, base));
        return {1, a, b};
    }
    ld ang = acos(dif / sqrt(d));
    a.push_back(getPoint(A, Ar, base + ang)); // 保底2条外公切线
    a.push_back(getPoint(A, Ar, base - ang));
    b.push_back(getPoint(B, Br, base + ang));
    b.push_back(getPoint(B, Br, base - ang));
    if (d == sum * sum) { // 外切，多1条内公切线
        a.push_back(getPoint(A, Ar, base));
        b.push_back(getPoint(B, Br, base + PI));
    } else if (d > sum * sum) { // 相离，多2条内公切线
        ang = acos(sum / sqrt(d));
        a.push_back(getPoint(A, Ar, base + ang));
        a.push_back(getPoint(A, Ar, base - ang));
        b.push_back(getPoint(B, Br, base + ang + PI));
        b.push_back(getPoint(B, Br, base - ang + PI));
    }
    return {a.size(), a, b};
}

ld TriAngleCircleInsection(Pd o, ld r, Pd A, Pd B) // 多边形和圆的面积交
{
    Pd OA = A - o, OB = B - o;
    Pd BA = A - B, BC = o - B;
    Pd AB = B - A, AC = o - A;
    double DOA = dis(A, o), DOB = dis(B, o), DAB = dis(A, B);
    if (sign(cross(OA, OB)) == 0)
        return 0;
    if (sign(DOA - r) < 0 && sign(DOB - r) < 0) {
        return cross(OA, OB) * 0.5;
    } else if (DOB < r && DOA >= r) {
        double x = (dot(BA, BC) + sqrt(r * r * DAB * DAB - cross(BA, BC) * cross(BA, BC))) / DAB;
        double TS = cross(OA, OB) * 0.5;
        return asin(TS * (1 - x / DAB) * 2 / r / DOA) * r * r * 0.5 + TS * x / DAB;
    } else if (DOB >= r && DOA < r) {
        double y = (dot(AB, AC) + sqrt(r * r * DAB * DAB - cross(AB, AC) * cross(AB, AC))) / DAB;
        double TS = cross(OA, OB) * 0.5;
        return asin(TS * (1 - y / DAB) * 2 / r / DOB) * r * r * 0.5 + TS * y / DAB;
    } else if (fabs(cross(OA, OB)) >= r * DAB || dot(AB, AC) <= 0 || dot(BA, BC) <= 0) {
        if (dot(OA, OB) < 0) {
            if (cross(OA, OB) < 0)
                return (-acos(-1.0) - asin(cross(OA, OB) / DOA / DOB)) * r * r * 0.5;
            else
                return (acos(-1.0) - asin(cross(OA, OB) / DOA / DOB)) * r * r * 0.5;
        } else
            return asin(cross(OA, OB) / DOA / DOB) * r * r * 0.5;
    } else {
        double x = (dot(BA, BC) + sqrt(r * r * DAB * DAB - cross(BA, BC) * cross(BA, BC))) / DAB;
        double y = (dot(AB, AC) + sqrt(r * r * DAB * DAB - cross(AB, AC) * cross(AB, AC))) / DAB;
        double TS = cross(OA, OB) * 0.5;
        return (asin(TS * (1 - x / DAB) * 2 / r / DOA) + asin(TS * (1 - y / DAB) * 2 / r / DOB)) * r * r * 0.5 + TS * ((x + y) / DAB - 1);
    }
}

ld polygon_circle_area(Pd o, ld r, vector<Pd> &p) // 多边形和圆的面积
{
    ld ans = 0;
    // cout << o << ' ' << r << endl;
    for (int i = 0; i < p.size() - 1; i++) {
        // cout << p[i] << ' ' << p[i + 1] << endl;
        ans += TriAngleCircleInsection(o, r, p[i], p[i + 1]);
        // cout << ans << ' ';
    }
    return fabs(ans);
}

/*平面三角形相关*/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

// 三角形面积
ld area(Point<ld> a, Point<ld> b, Point<ld> c) {
    return abs(cross(b, c, a)) / 2;
}

// 三角形外心 (三角形外接圆的圆心，即三角形三边垂直平分线的交点)
template <class T>
Pt center1(Pt p1, Pt p2, Pt p3) { // 外心
    return lineIntersection(midSegment({p1, p2}), midSegment({p2, p3}));
}

// 三角形内心 (三角形内切圆的圆心，也是三角形三个内角的角平分线的交点。其到三角形三边的距离相等)
Pd center2(Pd p1, Pd p2, Pd p3) { // 内心
#define atan2(p) atan2(p.y, p.x)  // 注意先后顺序
    Line<ld> U = {p1, {}}, V = {p2, {}};
    ld m, n, alpha;
    m = atan2((p2 - p1));
    n = atan2((p3 - p1));
    alpha = (m + n) / 2;
    U.b = {p1.x + cos(alpha), p1.y + sin(alpha)};
    m = atan2((p1 - p2));
    n = atan2((p3 - p2));
    alpha = (m + n) / 2;
    V.b = {p2.x + cos(alpha), p2.y + sin(alpha)};
    return lineIntersection(U, V);
}

// 三角形的垂心 (三角形的三条高线所在直线的交点。锐角三角形的垂心在三角形内；直角三角形的垂心在直角顶点上；钝角三角形的垂心在三角形外)
Pd center3(Pd p1, Pd p2, Pd p3) {     // 垂心
    Ld U = {p1, p1 + rotate(p2, p3)}; // 垂线
    Ld V = {p2, p2 + rotate(p1, p3)};
    return lineIntersection(U, V);
}

// 三角形的重心
Pd center4(Pd p1, Pd p2, Pd p3) {
    return (p1 + p2 + p3) / 3.0;
}
/*未整理 2/3*/

/*平面方程转换 */
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

// 浮点数计算直线的斜率
template <class T>
ld slope(Pt p1, Pt p2) { // 斜率，注意 inf 的情况
    return (p1.y - p2.y) / (p1.x - p2.x);
}
template <class T>
ld slope(Lt l) {
    return slope(l.a, l.b);
}
/* 计算斜率的分数形式
template <class T>
Frac<T> slopeEx(Pt p1, Pt p2)
{
    Frac<T> U = p1.y - p2.y;
    Frac<T> V = p1.x - p2.x;
    return U / V; // 调用分数精确计算
}
*/

// 两点式转一般式
template <class T>
tuple<int, int, int> getfun(Lt p) {
    T A = p.a.y - p.b.y, B = p.b.x - p.a.x, C = p.a.x * A + p.a.y * B;
    if (A < 0) { // 符号调整
        A = -A, B = -B, C = -C;
    } else if (A == 0) {
        if (B < 0) {
            B = -B, C = -C;
        } else if (B == 0 && C < 0) {
            C = -C;
        }
    }
    if (A == 0) { // 数值计算
        if (B == 0) {
            C = 0; // 共点特判
        } else {
            T g = fgcd(abs(B), abs(C));
            B /= g, C /= g;
        }
    } else if (B == 0) {
        T g = fgcd(abs(A), abs(C));
        A /= g, C /= g;
    } else {
        T g = fgcd(fgcd(abs(A), abs(B)), abs(C));
        A /= g, B /= g, C /= g;
    }
    return tuple{A, B, C}; // Ax + By = C
}

// 一般式转两点式
Line<ld> getfun(int A, int B, int C) { // Ax + By = C
    ld x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    if (A && B) { // 正常
        if (C) {
            x1 = 0, y1 = 1. * C / B;
            y2 = 0, x2 = 1. * C / A;
        } else { // 过原点
            x1 = 1, y1 = 1. * -A / B;
            x2 = 0, y2 = 0;
        }
    } else if (A && !B) { // 垂直
        if (C) {
            y1 = 0, x1 = 1. * C / A;
            y2 = 1, x2 = x1;
        } else {
            x1 = 0, y1 = 1;
            x2 = 0, y2 = 0;
        }
    } else if (!A && B) { // 水平
        if (C) {
            x1 = 0, y1 = 1. * C / B;
            x2 = 1, y2 = y1;
        } else {
            x1 = 1, y1 = 0;
            x2 = 0, y2 = 0;
        }
    } else { // 不合法，请特判
        assert(false);
    }
    return {{x1, y1}, {x2, y2}};
}

// 抛物线与 x 轴是否相交及交点 (0 代表没有交点；1 代表相切；2 代表有两个交点)
tuple<int, ld, ld> getAns(ld a, ld b, ld c) {
    ld delta = b * b - a * c * 4;
    if (delta < 0.) {
        return {0, 0, 0};
    }
    delta = sqrt(delta);
    ld ans1 = -(delta + b) / 2 / a;
    ld ans2 = (delta - b) / 2 / a;
    if (ans1 > ans2) {
        swap(ans1, ans2);
    }
    if (sign(delta) == 0) {
        return {1, ans2, 0};
    }
    return {2, ans1, ans2};
}

/*平面多边形 */
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

// 两向量构成的平面四边形有向面积
template <class T>
T areaEx(Point<T> p1, Point<T> p2, Point<T> p3) {
    return cross(p2, p3, p1);
}

// 判断四个点能否组成矩形/正方形 (2代表构成正方形；1 代表构成矩形； 0 代表其他情况)
template <class T>
int isSquare(vector<Pt> x) {
    sort(x.begin(), x.end());
    if (equal(dis(x[0], x[1]), dis(x[2], x[3])) && sign(dis(x[0], x[1])) &&
        equal(dis(x[0], x[2]), dis(x[1], x[3])) && sign(dis(x[0], x[2])) &&
        lineParallel(Lt{x[0], x[1]}, Lt{x[2], x[3]}) &&
        lineParallel(Lt{x[0], x[2]}, Lt{x[1], x[3]}) &&
        lineVertical(Lt{x[0], x[1]}, Lt{x[0], x[2]})) {
        return equal(dis(x[0], x[1]), dis(x[0], x[2])) ? 2 : 1;
    }
    return 0;
}

// 点是否在任意多边形内 (射线法判定，t为穿越次数，当其为奇数时即代表点在多边形内部；返回 2 代表点在多边形边界上)
template <class T>
int pointInPolygon(Point<T> a, vector<Point<T>> p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (pointOnSegment(a, Line{p[i], p[(i + 1) % n]})) {
            return 2;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        auto u = p[i], v = p[(i + 1) % n];
        if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line{v, u})) {
            t ^= 1;
        }
        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line{u, v})) {
            t ^= 1;
        }
    }
    return t == 1;
}

// 线段是否在任意多边形内部
template <class T>
bool segmentInPolygon(Line<T> l, vector<Point<T>> p) {
// 线段与多边形边界不相交且两端点都在多边形内部
#define L(x, y) pointOnLineLeft(x, y)
    int n = p.size();
    if (!pointInPolygon(l.a, p))
        return false;
    if (!pointInPolygon(l.b, p))
        return false;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        auto w = p[(i + 2) % n];
        auto [t, p1, p2] = segmentIntersection(l, Line(u, v));
        if (t == 1)
            return false;
        if (t == 0)
            continue;
        if (t == 2) {
            if (pointOnSegment(v, l) && v != l.a && v != l.b) {
                if (cross(v - u, w - v) > 0) {
                    return false;
                }
            }
        } else {
            if (p1 != u && p1 != v) {
                if (L(l.a, Line(v, u)) || L(l.b, Line(v, u))) {
                    return false;
                }
            } else if (p1 == v) {
                if (l.a == v) {
                    if (L(u, l)) {
                        if (L(w, l) && L(w, Line(u, v))) {
                            return false;
                        }
                    } else {
                        if (L(w, l) || L(w, Line(u, v))) {
                            return false;
                        }
                    }
                } else if (l.b == v) {
                    if (L(u, Line(l.b, l.a))) {
                        if (L(w, Line(l.b, l.a)) && L(w, Line(u, v))) {
                            return false;
                        }
                    } else {
                        if (L(w, Line(l.b, l.a)) || L(w, Line(u, v))) {
                            return false;
                        }
                    }
                } else {
                    if (L(u, l)) {
                        if (L(w, Line(l.b, l.a)) || L(w, Line(u, v))) {
                            return false;
                        }
                    } else {
                        if (L(w, l) || L(w, Line(u, v))) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

// 任意多边形的面积
template <class T>
ld area(vector<Point<T>> P) {
    int n = P.size();
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cross(P[i], P[(i + 1) % n]);
    }
    return ans / 2.0;
}

// 任意多边形上的网格点个数（仅能处理整数）
int onPolygonGrid(vector<Point<int>> p) {
    int n = p.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        auto a = p[i], b = p[(i + 1) % n];
        ans += gcd(abs(a.x - b.x), abs(a.y - b.y));
    }
    return ans;
}

// 任意多边形内部的网格点个数（仅能处理整数）
int inPolygonGrid(vector<Point<int>> p) {
    int n = p.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        auto a = p[i], b = p[(i + 1) % n], c = p[(i + 2) % n];
        ans += b.y * (a.x - c.x);
    }
    ans = abs(ans);
    return (ans - onPolygonGrid(p)) / 2 + 1;
}