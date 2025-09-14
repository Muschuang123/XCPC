// 扫描线算法，线段树求解。
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