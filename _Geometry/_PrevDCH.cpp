// https://codeforces.com/problemset/problem/70/D
// erase 写不对，甚至不可能写对，因为涉及到上下凸壳交换。
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using DB = long long;
const DB INF = numeric_limits<DB>::max();
struct Point { // 定义二维平面点的结构体
    DB x, y;
    // 返回两点构成的向量
    Point operator-(const Point &a) const { return {x - a.x, y - a.y}; }
    // 定义以 x 为第一关键字 y 为第二关键字的排序
    bool operator<(const Point &a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
    bool operator==(const Point &a) const {
        return x == a.x && y == a.y;
    }
    bool operator!=(const Point &a) const {
        return !(*this == a);
    }
    DB operator^(const Point &a) const { return x * a.y - y * a.x; }
};
using Vector = Point;

// 计算二维向量叉积
DB cross(const Vector &a, const Vector &b) {
    return a.x * b.y - b.x * a.y;
}

// 完整凸包类
struct ConvexHull {
    set<Point> up;   // 用有序集合维护上凸壳的点集（按x坐标排序）
    set<Point> down; // 用有序集合维护下凸壳的点集（按x坐标排序）

    // 获取迭代器的前驱（上一个元素）
    template <typename SetType>
    typename SetType::iterator pre(SetType &s, typename SetType::iterator it) {
        return it == s.begin() ? s.end() : --it;
    }

    // 获取迭代器的后继（下一个元素）
    template <typename SetType>
    typename SetType::iterator next(SetType &s, typename SetType::iterator it) {
        ++it;
        return it == s.end() ? s.end() : it;
    }

    // 检查点p是否在上凸壳内部或边界上
    bool checkUp(const Point &p) {
        auto it = up.lower_bound(p);               // 找到第一个x >= p.x的点
        if (it == up.end()) return false;          // 无后继点，不在凸壳内
        if (it == up.begin()) {                    // 是第一个点
            if (it->x == p.x) return it->y >= p.y; // x相同且y >= p.y，在边界上
            return false;                          // 否则不在凸壳内
        }
        auto prev_it = pre(up, it);           // 获取前驱点
        Vector a = *prev_it - p, b = *it - p; // 向量pa和pb
        return cross(a, b) <= 0;              // 叉积<=0表示p在pa和pb构成的线段下方或共线
    }

    // 检查点p是否在下凸壳内部或边界上
    bool checkDown(const Point &p) {
        auto it = down.lower_bound(p);             // 找到第一个x >= p.x的点
        if (it == down.end()) return false;        // 无后继点，不在凸壳内
        if (it == down.begin()) {                  // 是第一个点
            if (it->x == p.x) return it->y <= p.y; // x相同且y <= p.y，在边界上
            return false;                          // 否则不在凸壳内
        }
        auto prev_it = pre(down, it);         // 获取前驱点
        Vector a = *prev_it - p, b = *it - p; // 向量pa和pb
        return cross(a, b) >= 0;              // 叉积>=0表示p在pa和pb构成的线段上方或共线
    }

    // 尝试删除上凸壳上的点it，返回是否成功删除
    bool eraseUp(typename set<Point>::iterator it) {
        if (it == up.end() || it == up.begin()) return false; // 首尾点不删除
        auto prev_it = pre(up, it), next_it = next(up, it);
        if (next_it == up.end()) return false;         // 无后继点，无法删除
        Vector a = *it - *prev_it, b = *next_it - *it; // 向量prev->it和it->next
        if (cross(a, b) >= 0) {                        // 叉积>=0表示三点共线或右拐，it点冗余
            up.erase(it);
            return true;
        }
        return false;
    }

    // 尝试删除下凸壳上的点it，返回是否成功删除
    bool eraseDown(typename set<Point>::iterator it) {
        if (it == down.end() || it == down.begin()) return false; // 首尾点不删除
        auto prev_it = pre(down, it), next_it = next(down, it);
        if (next_it == down.end()) return false;       // 无后继点，无法删除
        Vector a = *it - *prev_it, b = *next_it - *it; // 向量prev->it和it->next
        if (cross(a, b) <= 0) {                        // 叉积<=0表示三点共线或左拐，it点冗余
            down.erase(it);
            return true;
        }
        return false;
    }

    // 插入点p到上凸壳中，维护凸壳结构
    void insertUp(const Point &p) {
        if (checkUp(p)) return;       // 若p在凸壳内或边界上，直接返回
        auto it = up.insert(p).first; // 插入p并获取迭代器

        // 从插入点左侧开始删除冗余点（左链优化）
        for (auto pit = pre(up, it); pit != up.end() && pit != up.begin(); pit = pre(up, it))
            if (!eraseUp(pit)) break; // 无法删除时停止
        // 从插入点右侧开始删除冗余点（右链优化）
        for (auto ait = next(up, it); ait != up.end(); ait = next(up, it))
            if (!eraseUp(ait)) break; // 无法删除时停止
    }

    // 插入点p到下凸壳中，维护凸壳结构
    void insertDown(const Point &p) {
        if (checkDown(p)) return;       // 若p在凸壳内或边界上，直接返回
        auto it = down.insert(p).first; // 插入p并获取迭代器

        // 从插入点左侧开始删除冗余点
        for (auto pit = pre(down, it); pit != down.end() && pit != down.begin(); pit = pre(down, it))
            if (!eraseDown(pit)) break; // 无法删除时停止
        // 从插入点右侧开始删除冗余点
        for (auto ait = next(down, it); ait != down.end(); ait = next(down, it))
            if (!eraseDown(ait)) break; // 无法删除时停止
    }

    // 插入点到凸包中，同时维护上下凸壳
    void insert(const Point &p) {
        insertUp(p);
        insertDown(p);
    }

    // 检查点p是否在凸包内部或边界上
    bool check(const Point &p) {
        return checkUp(p) && checkDown(p);
    }

    // 获取完整的凸包顶点（按逆时针顺序）
    vector<Point> getHull() {
        vector<Point> hull;

        // 添加上凸壳的点（从左到右）
        for (const auto &p : up) {
            hull.push_back(p);
        }

        // 添加下凸壳的点（从右到左，避免重复添加端点）
        vector<Point> lower;
        for (auto it = down.rbegin(); it != down.rend(); ++it) {
            // 跳过与上凸壳重复的端点（最左和最右的点）
            if (!up.empty() && (*it == *up.begin() || *it == *up.rbegin())) {
                continue;
            }
            lower.push_back(*it);
        }

        // 合并下凸壳到结果
        hull.insert(hull.end(), lower.begin(), lower.end());
        return hull;
    }

    // 清空凸包
    void clear() {
        up.clear();
        down.clear();
    }

    // 获取凸包中的点数
    int size() {
        if (up.size() == 1 && down.size() == 1) return 1;
        // 需要减去重复计算的端点
        int common = 0;
        if (!up.empty() && !down.empty()) {
            // 检查左右端点是否重合
            if (*up.begin() == *down.begin()) common++;
            if (*up.rbegin() == *down.rbegin()) common++;
        }
        return up.size() + down.size() - common;
    }

    void erase(const Point &p) {
        up.erase(p);
        down.erase(p);
        if (!up.empty() && !down.empty()) {
            if (*up.begin() != *down.begin()) {
                Point p = min(*up.begin(), *down.begin());
                up.insert(p);
                down.insert(p);
            }
            if (*up.rbegin() != *down.rbegin()) {
                Point p = max(*up.rbegin(), *down.rbegin());
                up.insert(p);
                down.insert(p);
            }
        }
    }
    
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ConvexHull C;
    int Q;
    cin >> Q;
    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            C.insert({x, y});
        } else {
            if (C.check({x, y})) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}