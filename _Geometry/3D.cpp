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