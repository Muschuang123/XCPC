#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 观察发现 可以转化为方形。
// 方形开关，改变不了原始坐标的奇偶。
// XOR 可以得到原始坐标

// 翻看题解，可以优化，不用 map，直接用一个变量就行。

void solve() {
    int n;
    cin >> n;
    i64 X = 0, Y = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        X ^= x;
        Y ^= y + x;
    }
    cout << X << ' ' << Y - X << '\n';
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