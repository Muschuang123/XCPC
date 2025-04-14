#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

pair<int, int> ran(int n) {
    int l = uniform_int_distribution{1, n}(rnd);
    int r = 0;
    do {
        r = uniform_int_distribution{1, n}(rnd);
    } while (l == r);
    return {l, r};
}

struct Pt {
    int x, y;

    Pt rot() {
        return {-y, x};
    }
    
    Pt operator-(const Pt &b) const {
        return {x - b.x, y - b.y};
    }
};

i64 dot(Pt &a, Pt &b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<Pt> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    while (1) {
        // 随机出一条线
        auto [p1, p2] = ran(n);
        Pt cur = a[p1] - a[p2];
        // 求这条线的垂线
        Pt ro = cur.rot();
        map<i64, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            Pt res = a[i] - a[p1];
            // 几个点连上a[p1]，如果对 垂线的投影相同，则这几个点共线
            mp[dot(ro, res)].push_back(i);
            if (mp.size() > k) {
                break;
            }
        }

        if (mp.size() != k) {
            continue;
        }

        int ok = 1;
        for (auto &[f, s] : mp) {
            if (s.size() <= 1) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            for (auto &[f, s] : mp) {
                cout << s.size() << ' ';
                for (auto &e : s) {
                    cout << e << ' ';
                }
                cout << '\n';
            }
            break;
        }
    }

    return 0;
}