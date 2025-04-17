#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int q;
    cin >> q;
    deque<i64> a, b;
    i64 sum = 0;
    i64 ca = 0, cb = 0;
    int m = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            i64 x = a.back();
            ca += sum;
            ca -= x * m;
            cb -= sum;
            cb += x * m;
            a.push_front(x);
            b.push_back(x);
            a.pop_back();
            b.pop_front();
        } else if (op == 2) {
            swap(a, b);
            swap(ca, cb);
        } else if (op == 3) {
            m++;
            i64 x;
            cin >> x;
            a.push_back(x);
            ca += x * m;
            // 哈哈***刚刚这个 b 写成 a 了 ^_^
            b.push_front(x);
            cb += sum + x;
            sum += x;
        }
        cout << ca << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}