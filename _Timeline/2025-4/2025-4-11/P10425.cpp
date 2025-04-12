#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 34.4445 四舍五入到整数
// 是 34 ，不是 35

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    string d;
    cin >> n >> d;
    // if (n <= 10 && d.size() <= 15) {
    //     cout << fixed << setprecision(0);
    //     long double f = stold(d);
    //     for (int i = 1; i <= n; i++) {
    //         f *= 2;
    //     }
    //     cout << f << '\n';
    // } else {
        auto mul = [&](string &s) {
            reverse(s.begin(), s.end());
            int fl = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '.') {
                    continue;
                }
                int t = s[i] - '0';
                t = t * 2 + fl;
                if (t >= 10) {
                    fl = 1;
                    t -= 10;
                } else {
                    fl = 0;
                }
                s[i] = t + '0';
            }
            if (fl) {
                s.push_back('1');
            }
            reverse(s.begin(), s.end());
        };
        for (int i = 1; i <= n; i++) {
            mul(d);
        }
        reverse(d.begin(), d.end());
        int dot = 0, fl = 0;
        for (int i = 0; i < d.size(); i++){
            if (d[i] == '.') {
                dot = i;
                if (d[i - 1] >= '5') {
                    fl = 1;
                }
            } else if (fl) {
                d[i]++;
                if (d[i] > '9') {
                    d[i] -= 10;
                    fl = 1;
                } else {
                    fl = 0;
                }
            }
        }
        if (fl) {
            d.push_back('1');
        }
        d = d.substr(dot + 1);
        reverse(d.begin(), d.end());
        cout << d << '\n';
    // }

    return 0;
}