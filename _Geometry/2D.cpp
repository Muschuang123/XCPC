#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

// 有浮点数但是大部分都是 i64 时，可以选择用 pair<ld, ld> 替换必需内容
// 然后删去强制浮点数的函数，改用手写 pair<ld, ld> 替代。
using T = ld; // 全局数据类型

const T eps = 1e-12; // 注意一旦使用 T = i64，eps 就是 0LL ！！！
const T INF = numeric_limits<T>::max();
const T PI = acosl(-1); // 注意一旦使用 T = i64，PI 就是 3LL ！！！
#define setp(x) cout << fixed << setprecision(x)
int sgn(T x) { return x < -eps ? -1 : x > eps; }

istream &operator<<(istream &is, ld &x) {
    i64 t;
    is >> t;
    x = (ld)t;
    return is;
}

void map_add(map<ld, int> &mp, const ld &k, const int &v) {
    auto it = mp.lower_bound(k - eps);
    if (it != mp.end() && abs(it->first - k) <= eps) {
        it->second += v;
    } else {
        mp[k] += v;
    }
}

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
    Pt rot(const T rad) const { return {x * cosl(rad) - y * sinl(rad), x * sinl(rad) + y * cosl(rad)}; } // 逆时针旋转（给定角度）
    Pt rot(const T cosr, const T sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; }      // 逆时针旋转（给定角度的正弦与余弦）
};

// pair<ld, ld> 叉积
ld operator^(const pair<ld, ld> &a, const pair<ld, ld> &b) {
    return a.first * b.second - a.second * b.first;
}

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
    // 计算线段上的网格点数量（包括端点）
    // 要求端点都在网格点上（必须用整数）
    i64 calc_pts_on_segment() const {
        i64 dx = (a.x - b.x), dy = (a.y - b.y);
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        return gcd(dx, dy) + 1;
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
    // 计算线段的中垂线（必须用浮点数）
    Lt midperp() const {
        Pt mid = (a + b) / 2; // 线段中点
        Pt vec = b - a;
        return {mid, Pt{-vec.y, vec.x}};
    }
};

// 多边形
struct Polygon {
    vector<Pt> p; // 以逆时针顺序存储
    int ne(const int i) const { return i == p.size() - 1 ? 0 : i + 1; }
    int pre(const int i) const { return i == 0 ? p.size() - 1 : i - 1; }
    // 回转数
    // 返回值第一项表示点是否在多边形边上
    // 对于狭义多边形，回转数为 0 表示点在多边形外，否则点在多边形内
    pair<bool, int> winding(const Pt &a) const {
        int cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            const Pt u = p[i], v = p[ne(i)];
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
        for (int i = 0; i < p.size(); i++) sum += p[i] ^ p[ne(i)];
        return sum;
    }
    // 计算多边形内（不包括边上）的网格点数（必须用整数）
    i64 calc_pts_in_polygon() const {
        i64 S = 0, C = 0;
        for (int i = 0; i < p.size(); i++) {
            C += St{p[i], p[ne(i)]}.calc_pts_on_segment() - 1;
        }
        // 注意这里 S 和 C 其实可能 有 .5 的
        // 只不过要有一起有，计算的时候就可以抵掉了。
        S = area() / 2;
        // 多边形面积 = 多边形内网格点数 + 多边形边上网格点数 / 2 - 1
        // 平行四边形格点仍然成立，三角形格点 等式右边 * 2
        // S = I + C / 2 - 1
        return S - C / 2 + 1;
    }
    // 多边形的周长（必须用浮点数）
    T circ() const {
        T sum = 0;
        for (int i = 0; i < p.size(); i++) sum += p[i].dis(p[ne(i)]);
        return sum;
    }
    // 预处理多边形周长前缀和（必须用浮点数）
    vector<T> s;
    void build_circ() {
        int n = p.size();
        s.resize(n * 2);
        for (int i = 1; i < 2 * n; i++) {
            int j = i % n;
            s[i] = s[i - 1] + p[j].dis(p[pre(j)]);
        }
    }
    // O(1) 查询多边形 逆时针从 i ~ j 这部分周长（必须用浮点数）
    T query_circ(int i, int j) const {
        if (i > j) j += p.size();
        return s[j] - s[i];
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
        for (int i = 0; i < p.size(); i++) e1[i] = {p[i], p[this->ne(i)]};
        for (int i = 0; i < c.p.size(); i++) e2[i] = {c.p[i], c.p[c.ne(i)]};
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
        for (int i = 0, j = 1; i < p.size(); i++) {
            const auto nxti = this->ne(i);
            ans = max({ans, p[j].dis2(p[i]), p[j].dis2(p[nxti])});
            while (area(p[this->ne(j)], p[i], p[nxti]) >= area(p[j], p[i], p[nxti])) {
                j = this->ne(j);
                ans = max({ans, p[j].dis2(p[i]), p[j].dis2(p[nxti])});
            }
        }
        return ans;
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
        const int i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
        if (i == 1) return St{p[0], p[i]}.is_on(a) ? -1 : 0;
        if (i == p.size() - 1 && St{p[0], p[i]}.is_on(a)) return -1;
        if (St{p[i - 1], p[i]}.is_on(a)) return -1;
        return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
    }
    // 求点在凸多边形上的两侧的点，逆时针给出下标
    // 必须保证 is_in(a) == -1
    pair<int, int> around_points(const Pt &a) const {
        const auto &p = this->p;
        if (a == p[0]) return {p.size() - 1, 1};
        if (St{p.back(), p[0]}.is_on(a) == 1) return {p.size() - 1, 0};
        if (St{p[0], p[1]}.is_on(a) == 1) return {0, 1};
        const auto cmp = [&](const Pt &u, const Pt &v) { return (u - p[0]).toleft(v - p[0]) == 1; };
        const int i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
        if (St{p[this->pre(i)], p[i]}.is_on(a) == -1) return {pre(i), ne(i)};
        return {this->pre(i), i};
    }
    // 凸多边形关于某一方向的极点
    // 复杂度 O(logn)
    // 参考资料：https://codeforces.com/blog/entry/48868
    // 凸包点数 >= 3
    template <typename F>
    int extreme(const F &dir) const {
        const auto &p = this->p;
        const auto check = [&](const int i) { return dir(p[i]).toleft(p[this->ne(i)] - p[i]) >= 0; };
        const auto dir0 = dir(p[0]);
        const auto check0 = check(0);
        if (!check0 && check(p.size() - 1)) return 0;
        const auto cmp = [&](const Pt &v) {
            const int vi = &v - p.data();
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
    pair<int, int> tangent(const Pt &a) const {
        if (is_in(a) == -1) return around_points(a);
        const int i = extreme([&](const Pt &u) { return u - a; });
        const int j = extreme([&](const Pt &u) { return a - u; });
        return {i, j};
    }
    // 求平行于给定直线的凸多边形的切线，返回切点下标
    // 复杂度 O(logn)
    // 凸包点数 >= 3
    pair<int, int> tangent(const Lt &a) const {
        const int i = extreme([&](...) { return a.v; });
        const int j = extreme([&](...) { return -a.v; });
        return {i, j};
    }
    // 最小矩形覆盖 O(n)，返回面积和矩形端点（必须用浮点数）
    // 矩形端点按逆时针给出。
    pair<T, vector<Pt>> min_rectangle_cover() const {
        const auto &p = this->p;
        if (p.size() == 1) return {0, {}};
        if (p.size() == 2) return {0, {}};
        const auto dot = [&](const int u, const int v, const int w) { return (p[v] - p[u]) * (p[w] - p[u]); };
        const auto cross = [&](const int u, const int v, const int w) { return (p[v] - p[u]) ^ (p[w] - p[u]); };
        int u = 1, d = 1;
        T mu = INF, md = -INF;
        for (int i = 0; i < p.size(); i++) {
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
        for (int l = 0, r = 1; l < p.size(); l++) {
            const auto nxtl = this->ne(l);
            while (cross(l, nxtl, r) <= cross(l, nxtl, this->ne(r))) r = this->ne(r);
            while (dot(l, nxtl, u) >= dot(l, nxtl, this->ne(u))) u = this->ne(u);
            while (dot(l, nxtl, d) <= dot(l, nxtl, this->ne(d))) d = this->ne(d);
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
    int k = st.size();
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
    for (int i = 1; i < a.size(); i++) {
        if (C.r < C.c.dis(a[i])) {
            C = {a[i], 0};
            for (int j = 0; j < i; j++) {
                if (C.r < C.c.dis(a[j])) {
                    C = get2(a[i], a[j]);
                    for (int k = 0; k < j; k++) {
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
    for (int i = 0; i < l.size(); i++) {
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
    for (int i = 0, l = 0; i < pts.size(); i++) {
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
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
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
    vector<int> vx(vec.size()), pos(vec.size());
    for (int i = 0; i < vec.size(); i++) vx[i] = i;
    sort(vx.begin(), vx.end(), [&](int x, int y) { return vec[x] < vec[y]; });
    for (int i = 0; i < vx.size(); i++) pos[vx[i]] = i;
    for (auto [u, v] : evt) {
        const int i = pos[u], j = pos[v];
        const int l = min(i, j), r = max(i, j);
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
    for (int i = 0; i < poly.p.size(); i++) {
        const Pt a = poly.p[i], b = poly.p[poly.ne(i)];
        ans += cal(circ, a, b);
    }
    return ans;
}

// 多边形面积并
// 轮廓积分，复杂度 O(n^2logn)，n为边数
// ans[i] 表示被至少覆盖了 i+1 次的区域的面积
vector<T> area_union(const vector<Polygon> &polys) {
    const int siz = polys.size();
    vector<vector<pair<Pt, Pt>>> segs(siz);
    const auto check = [](const Pt &u, const St &e) { return !((u < e.a && u < e.b) || (u > e.a && u > e.b)); };
    auto cut_edge = [&](const St &e, const int i) {
        const Lt le{e.a, e.b - e.a};
        vector<pair<Pt, int>> evt;
        evt.push_back({e.a, 0});
        evt.push_back({e.b, 0});
        for (int j = 0; j < polys.size(); j++) {
            if (i == j) continue;
            const auto &pj = polys[j];
            for (int k = 0; k < pj.p.size(); k++) {
                const St s = {pj.p[k], pj.p[pj.ne(k)]};
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
        for (int i = 0; i < evt.size(); i++) {
            sum += evt[i].second;
            const Pt u = evt[i].first, v = evt[i + 1].first;
            if (!(u == v) && check(u, e) && check(v, e)) segs[sum].push_back({u, v});
            if (v == e.b) break;
        }
    };
    for (int i = 0; i < polys.size(); i++) {
        const auto &pi = polys[i];
        for (int k = 0; k < pi.p.size(); k++) {
            const St ei = {pi.p[k], pi.p[pi.ne(k)]};
            cut_edge(ei, i);
        }
    }
    vector<T> ans(siz);
    for (int i = 0; i < siz; i++) {
        T sum = 0;
        sort(segs[i].begin(), segs[i].end());
        int cnt = 0;
        for (int j = 0; j < segs[i].size(); j++) {
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
    const int siz = circs.size();
    using arc_t = tuple<Pt, T, T, T>;
    vector<vector<arc_t>> arcs(siz);
    const auto eq = [](const arc_t &u, const arc_t &v) {
        const auto [u1, u2, u3, u4] = u;
        const auto [v1, v2, v3, v4] = v;
        return u1 == v1 && abs(u2 - v2) <= eps && abs(u3 - v3) <= eps && abs(u4 - v4) <= eps;
    };
    auto cut_circ = [&](const Circle &ci, const int i) {
        vector<pair<T, int>> evt;
        evt.push_back({-PI, 0});
        evt.push_back({PI, 0});
        int init = 0;
        for (int j = 0; j < circs.size(); j++) {
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
        for (int i = 0; i < evt.size(); i++) {
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
    for (int i = 0; i < circs.size(); i++) {
        const auto &ci = circs[i];
        cut_circ(ci, i);
    }
    vector<T> ans(siz);
    for (int i = 0; i < siz; i++) {
        T sum = 0;
        sort(arcs[i].begin(), arcs[i].end());
        int cnt = 0;
        for (int j = 0; j < arcs[i].size(); j++) {
            if (j > 0 && eq(arcs[i][j], arcs[i][j - 1]))
                arcs[i + (++cnt)].push_back(arcs[i][j]);
            else
                cnt = 0, sum += oint(arcs[i][j]);
        }
        ans[i] = sum / 2;
    }
    return ans;
}