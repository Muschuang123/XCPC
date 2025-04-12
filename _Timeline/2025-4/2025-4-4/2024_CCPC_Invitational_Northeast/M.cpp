#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 向量 (x, y) 与 向量 (xx, yy) 夹角
// 正数代表 < π
// 0 代表 共线
// 负数代表 > π
inline i64 Xmul(pair<i64, i64> &a, pair<i64, i64> &b) {
    return a.first * b.second - a.second * b.first;
}

inline i64 Dmul(pair<i64, i64> &a, pair<i64, i64> &b) {
    return a.first * b.first + a.second * b.second;
}

inline i64 dis(pair<i64, i64> &a) {
    return a.first * a.first + a.second * a.second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<i64, i64>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            auto C = a[i], D = a[j];
            pair<i64, i64> CD = {a[j].first - a[i].first, a[j].second - a[i].second};
            i64 lf = 0;
            map<i64, int> ri;
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k) {
                    continue;
                }
                auto X = a[k];
                pair<i64, i64> CX = {a[k].first - a[i].first, a[k].second - a[i].second};
                pair<i64, i64> DX = {a[k].first - a[j].first, a[k].second - a[j].second};
                if (Xmul(CD, CX) == 0) {
                    continue;
                } else if (Xmul(CD, CX) > 0) {
                    if (dis(CX) == dis(DX)) {
                        lf++;
                    }
                } else if (Dmul(CD, CX) == 0) {
                    ri[dis(CX)]++;
                } else if (Dmul(CD, DX) == 0) {
                    ri[dis(DX)]++;
                }
            }
            for (auto &[f, s] : ri) {
                if (s == 2) {
                    ans += lf;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}